import java.io.FileInputStream;
import java.io.IOException;
import java.nio.ByteBuffer;
import java.nio.charset.StandardCharsets;
import java.util.Arrays;

import ru.spbstu.pipeline.*;

public class MyReader implements IReader {
    private IConsumer consumer;
    private final ReaderParser parser;

    private FileInputStream file;
    private int blockSize;
    private byte[] data;

    private final TYPE[] outTypes = { TYPE.BYTE, TYPE.CHAR, TYPE.SHORT };

    public MyReader() {
        parser = new ReaderParser();
    }

    @Override
	public RC setInputStream(FileInputStream fis) {
        if (fis == null)
            return RC.CODE_INVALID_ARGUMENT;

        file = fis;
        return RC.CODE_SUCCESS;
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
        return RC.CODE_SUCCESS;
    }

    @Override
    public RC setConfig(String filename) {
        if (filename == null)
            return RC.CODE_INVALID_ARGUMENT;

        RC err_code = parser.Parse(filename);

        if (err_code != RC.CODE_SUCCESS)
            return err_code;

        blockSize = parser.getReadBlockSize();

        return RC.CODE_SUCCESS;
    }

    @Override
    public RC execute() {
        try {
            while (true) {
                int bytesToEOF =  (int)(file.getChannel().size() - file.getChannel().position());
                if (bytesToEOF == 0)
                    break;

                byte[] buffer = new byte[Math.min(blockSize, bytesToEOF)];
                if (file.read(buffer) == -1)
                    break;

                data = buffer;
                RC err_code = consumer.execute();

                if (err_code != RC.CODE_SUCCESS)
                    return err_code;
            }
        }
        catch(IOException exc) {
            return RC.CODE_FAILED_TO_READ;
        }

        return RC.CODE_SUCCESS;
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
