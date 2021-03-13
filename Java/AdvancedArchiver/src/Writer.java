import java.io.FileOutputStream;
import java.io.IOException;

import ru.spbstu.pipeline.*;

public class Writer implements IWriter {
    private final WriterParser parser;

    private FileOutputStream file;
    private int blockSize;

    public Writer() {
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
    public RC setConsumer(IExecutable c) {
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

        blockSize = parser.getWriteBlockSize();

        return RC.CODE_SUCCESS;
    }

    @Override
    public RC execute(byte [] data) {
        try {
            for (int start = 0; start < data.length; start += blockSize)
                file.write(data, start, Math.min(blockSize, data.length - start));
        }
        catch (IOException exc) {
            return RC.CODE_FAILED_TO_WRITE;
        }

        return RC.CODE_SUCCESS;
    }
}
