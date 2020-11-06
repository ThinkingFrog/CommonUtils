import java.io.FileOutputStream;
import ru.spbstu.pipeline.*;

public class MyWriter implements IWriter {
    private IExecutable consumer;
    private IExecutable producer;
    private FileOutputStream file;
    private ConfigHandler config;

	public RC setOutputStream(FileOutputStream fos) {
        file = fos;
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
        return RC.CODE_SUCCESS;
    }

    public RC setConfig(String cfg) {
        config = new ConfigHandler(cfg);
        return RC.CODE_SUCCESS;
    }
}