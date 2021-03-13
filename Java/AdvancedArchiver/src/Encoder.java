import java.util.ArrayList;

import ru.spbstu.pipeline.*;

public class Encoder implements IExecutor {
    private IExecutable consumer;

    @Override
    public RC setConsumer(IExecutable c) {
        if (c == null)
            return RC.CODE_INVALID_ARGUMENT;

        consumer = c;
        return RC.CODE_SUCCESS;
    }

    @Override
    public RC setProducer(IExecutable p) {
        return RC.CODE_SUCCESS;
    }

    @Override
    public RC setConfig(String filename) {
        return RC.CODE_SUCCESS;
    }

    @Override
    public RC execute(byte [] data) {

        ArrayList<Byte[]> dict = new ArrayList<>();
        ArrayList<Byte> coded_buffer = new ArrayList<>();

        for (int i = 0; i < data.length; i += 2) {
            // Create array of bytes currently being processed
            Byte[] block;
            if (data.length % 2 == 1 && i == data.length - 1)
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
                code = dict.size() - 1;
            }

            // Write pair index in output buffer
            coded_buffer.add((byte)code);
        }

        // output buffer
        ArrayList<Byte> out_buffer = new ArrayList<>();
        // Add dictionary to output buffer
        out_buffer.add((byte)dict.size());
        for (Byte[] pair : dict)
            for (Byte symb : pair)
                out_buffer.add(symb);

        // Add coded text to output buffer
        out_buffer.add((byte)coded_buffer.size());
        out_buffer.addAll(coded_buffer);

        // Convert ArrayList<Byte> to byte[]
        byte [] out_data = new byte[out_buffer.size()];
        for (int i = 0; i < out_buffer.size(); ++i)
            out_data[i] = out_buffer.get(i);

        return consumer.execute(out_data);
    }

    // Runs through dict and checks if any of its subarrays match given array
    private int BlockAlreadyExists(ArrayList<Byte[]> dict, Byte[] block) {
        for (int dict_i = 0; dict_i < dict.size(); ++dict_i)
            if (dict.get(dict_i)[0] == block[0] && dict.get(dict_i)[1] == block[1])
                return dict_i;
        return -1;
    }
}
