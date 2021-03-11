import ru.spbstu.pipeline.*;

import java.nio.ByteBuffer;
import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.util.Arrays;

public class MyDecoder implements IExecutor {
    private IConsumer consumer;
    private IProducer producer;
    private IMediator mediator;

    private final TYPE[] inTypes = { TYPE.BYTE };
    private final TYPE[] outTypes = { TYPE.BYTE, TYPE.CHAR, TYPE.SHORT };

    private byte[] data;

    int dictSize;
    int decodedSize;

    public MyDecoder() {
        dictSize = 0;
        decodedSize = 0;
    }

    @Override
    public RC setConsumer(IConsumer c) {
        if (c == null)
            return RC.CODE_INVALID_ARGUMENT;

        consumer = c;
        return RC.CODE_SUCCESS;
    }

    @Override
    public RC setProducer(IProducer p) {
        if (p == null)
            return RC.CODE_INVALID_ARGUMENT;

        producer = p;

        TYPE intersectType = determineType();
        if (intersectType != null)
            mediator = producer.getMediator(intersectType);

        return RC.CODE_SUCCESS;
    }

    @Override
    public RC setConfig(String filename) {
        return RC.CODE_SUCCESS;
    }

    @Override
    public RC execute() {
        data = (byte[])mediator.getData();
        if (data == null)
            return RC.CODE_SUCCESS;

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

         data = buffer;

         RC err_code = consumer.execute();
         if (err_code != RC.CODE_SUCCESS)
             return err_code;

        return RC.CODE_SUCCESS;
    }

    private TYPE determineType() {
        TYPE[] ptypes = producer.getOutputTypes();
        for (TYPE ptype : ptypes)
            if (Arrays.asList(inTypes).contains(ptype))
                return ptype;
        return null;
    }

    private class MyMediator implements IMediator {
        private final TYPE type;

        MyMediator(TYPE type) {
            this.type = type;
        }

        @Override
        public Object getData() {
            if (data == null)
                return null;

            switch (type) {
                case BYTE:
                    return Arrays.copyOf(data, data.length);

                case CHAR:
                    return new String(data, StandardCharsets.UTF_8).toCharArray();

                case SHORT:
                    ByteBuffer buffer = ByteBuffer.wrap(data);
                    short[] arr = new short[data.length / 2];

                    for (int i = 0; i < arr.length; ++i)
                        arr[i] = buffer.getShort();
                    return arr;

                default:
                    return null;
            }
        }
    }

    public IMediator getMediator(TYPE type) {
        return new MyMediator(type);
    }

    public TYPE[] getOutputTypes() {
        return outTypes;
    }
}
