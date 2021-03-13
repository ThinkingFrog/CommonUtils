import ru.spbstu.pipeline.*;

import java.util.ArrayList;

public class Decoder implements IExecutor {
    private IExecutable consumer;
    int dictSize;
    int decodedSize;

    public Decoder() {
        dictSize = 0;
        decodedSize = 0;
    }

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
        ArrayList<Byte> dict = new ArrayList<>();
        ArrayList<Byte> decoded = new ArrayList<>();

        // data-iteration index
        int idx = 0;

        // If new coded block begins, start reading code dictionary
        dictSize = data[idx++] * 2;

        // Read and save dictionary to ArrayList
        for (; dictSize > 0; --dictSize, ++idx)
            dict.add(data[idx]);

        decodedSize = data[idx++];

        // Read coded character
        // Decode it using dictionary
        // Write decoded character to output buffer
        for (; decodedSize > 0; --decodedSize, ++idx) {
            int code = data[idx];

            decoded.add(dict.get(code * 2));
            if (dict.get(code * 2 + 1) != 0)
                decoded.add(dict.get(code * 2 + 1));
        }

        // Pass decoded data to consumer
        byte[] buffer = new byte[decoded.size()];
        for (int i = 0; i < buffer.length; ++i)
            buffer[i] = decoded.get(i);

         RC err_code = consumer.execute(buffer);
         if (err_code != RC.CODE_SUCCESS)
             return err_code;

        return RC.CODE_SUCCESS;
    }
}
