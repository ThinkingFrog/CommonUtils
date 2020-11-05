import java.io.FileInputStream;
import ru.spbstu.pipeline.*;

public class MyReader implements IReader {
    private IExecutable consumer;
    private IExecutable producer;
    private FileInputStream file;
    private ConfigHandler config;

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
        return RC.CODE_SUCCESS;
    }

    public RC setConfig(String cfg) {
        config = new ConfigHandler(cfg);
        return RC.CODE_SUCCESS;
    }
}
