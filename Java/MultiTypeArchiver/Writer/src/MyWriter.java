import java.io.FileOutputStream;
import java.io.IOException;
import java.nio.ByteBuffer;
import java.nio.charset.StandardCharsets;
import java.util.Arrays;

import ru.spbstu.pipeline.*;

public class MyWriter implements IWriter {
    private IProducer producer;
    private final WriterParser parser;
    private IMediator mediator;

    private final TYPE[] inTypes = { TYPE.BYTE };
    private final TYPE[] outTypes = { TYPE.BYTE, TYPE.CHAR, TYPE.SHORT };

    private FileOutputStream file;
    private int blockSize;
    private byte[] data;

    public MyWriter() {
        parser = new WriterParser();
    }

    @Override
	public RC setOutputStream(FileOutputStream fos) {
        if (fos == null)
            return RC.CODE_INVALID_ARGUMENT;

        file = fos;
        return RC.CODE_SUCCESS;
    }

    @Override
    public RC setConsumer(IConsumer c) {
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
        if (filename == null)
            return RC.CODE_INVALID_ARGUMENT;

        RC err_code = parser.Parse(filename);

        if (err_code != RC.CODE_SUCCESS)
            return err_code;

        blockSize = parser.getWriteBlockSize();

        return RC.CODE_SUCCESS;
    }

    @Override
    public RC execute() {
        data = (byte[])mediator.getData();
        if (data == null)
            return RC.CODE_SUCCESS;

        try {
            for (int start = 0; start < data.length; start += blockSize)
                file.write(data, start, Math.min(blockSize, data.length - start));
        }
        catch (IOException exc) {
            return RC.CODE_FAILED_TO_WRITE;
        }

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
