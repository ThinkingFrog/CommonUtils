import java.io.FileInputStream;
import java.io.IOException;

import ru.spbstu.pipeline.*;

public class MyReader implements IReader {
    private IExecutable consumer;
    private IExecutable producer;
    private FileInputStream file;
    private byte[] buffer;
    private ReaderParser parser;

	public RC setInputStream(FileInputStream fis) {
        file = fis;
        return RC.CODE_SUCCESS;
    }

    public RC setConsumer(IExecutable c) {
        consumer = c;
        return RC.CODE_SUCCESS;
    }

    public RC setProducer(IExecutable p) {
        producer = p;
        return RC.CODE_SUCCESS;
    }
    
    public RC execute(byte [] data) {
        long file_size;
        try {
            file_size = file.getChannel().size();
        }
        catch (IOException exc) {
            return RC.CODE_FAILED_TO_READ;
        }

        byte[] buffer = new byte[(int)file_size];
        
        try {
            while(file.read(buffer) != -1);
        }
        catch(IOException exc) {
            return RC.CODE_FAILED_TO_READ;
        }

        consumer.execute(buffer);

        return RC.CODE_SUCCESS;
    }

    public RC setConfig(String filename) {
        parser = new ReaderParser();
        parser.Parse(filename);
        return RC.CODE_SUCCESS;
    }
}
