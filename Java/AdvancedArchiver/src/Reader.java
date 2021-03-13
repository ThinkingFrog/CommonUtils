import java.io.FileInputStream;
import java.io.IOException;

import ru.spbstu.pipeline.*;

public class Reader implements IReader {
    private IExecutable consumer;
    private final ReaderParser parser;

    private FileInputStream file;
    private int blockSize;

    public Reader() {
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
        if (filename == null)
            return RC.CODE_INVALID_ARGUMENT;

        RC err_code = parser.Parse(filename);

        if (err_code != RC.CODE_SUCCESS)
            return err_code;

        blockSize = parser.getReadBlockSize();

        return RC.CODE_SUCCESS;
    }

    @Override
    public RC execute(byte[] data) {
        try {
            while (true) {
                int bytesToEOF =  (int)(file.getChannel().size() - file.getChannel().position());
                if (bytesToEOF == 0)
                    break;

                byte[] buffer = new byte[Math.min(blockSize, bytesToEOF)];
                if (file.read(buffer) == -1)
                    break;

                RC err_code = consumer.execute(buffer);

                if (err_code != RC.CODE_SUCCESS)
                    return err_code;
            }
        }
        catch(IOException exc) {
            return RC.CODE_FAILED_TO_READ;
        }

        return RC.CODE_SUCCESS;
    }
}
