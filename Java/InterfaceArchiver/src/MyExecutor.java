import java.util.ArrayList;

import ru.spbstu.pipeline.*;

public class MyExecutor implements IExecutor{
    private IExecutable consumer;
    private IExecutable producer;
    private ExecutorParser parser;

    public RC setConsumer(IExecutable c) {
        consumer = c;
        return RC.CODE_SUCCESS;
    }

    public RC setProducer(IExecutable p) {
        producer = p;
        return RC.CODE_SUCCESS;
    }
    
    public RC execute(byte [] data) {
        ArrayList<Short> out_buffer = new ArrayList<>();
        ArrayList<Byte[]> dict = new ArrayList<>();

        if (parser.isEncodeMode()) {
            ArrayList<Short> coded_buffer = new ArrayList<>();

            for (int i = 0; i < data.length; ++i) {
                // Create array of bytes currently being proccessed 
                Byte[] block;
                if (i == data.length - 1)
                    block = new Byte[] {data[i], 0};
                else
                    block = new Byte[] {data[i], data[i + 1]};
                
                // Check if a pair is already coded in dictionary
                // Returns -1 if pair doesn't already exist
                // Returns pair index if it already exists
                int code = BlockAlreadyExists(dict, block);
                
                // If pair doesn't already exist, write it
                if (code == -1) {
                    dict.add(block);
                    code = dict.size();
                }

                // Write pair index in output buffer
                coded_buffer.add((short)code);
            }
            
            // Fill output buffer
            out_buffer.add((short)dict.size());
            for (Byte[] pair : dict)
                for (Byte symb : pair)
                    out_buffer.add((short)symb);
            out_buffer.add((short)coded_buffer.size());
            for (Short code : coded_buffer)
                out_buffer.add(code);
        }
        else if (parser.isDecodeMode()) {
            // Read size of dictionary
            short dict_size = data[0];

            // Read dictionary and save it
            for (short i = 1; i <= dict_size; ++i)
                dict.add(new Byte[] {data[i], data[i + 1]});

            // Read coded character
            // Decode it using dictionary
            // Write decoded character to output file
            for (int i = dict_size * 2 + 1; i < data.length; ++i) {
                out_buffer.add((short)dict.get(data[i])[0]);
                if (dict.get(data[i])[1] != 0)
                    out_buffer.add((short)dict.get(data[i])[1]);
            }
        }
        else
            return RC.CODE_CONFIG_GRAMMAR_ERROR;

        consumer.execute(out_buffer);
            
        return RC.CODE_SUCCESS;
    }

    public RC setConfig(String filename) {
        parser = new ExecutorParser();
        parser.Parse(filename);
        return RC.CODE_SUCCESS;
    }

    // Runs through dict and checks if any of its subarrays match given array
    private int BlockAlreadyExists(ArrayList<Byte[]> dict, Byte[] block) {
        for (int dict_i = 0; dict_i < dict.size(); ++dict_i)
            for (int block_i = 0; block_i < block.length; ++block_i)
                if (dict.get(dict_i)[block_i] == block[block_i])
                    return dict_i;
        return -1;
    }
}
