import ru.spbstu.pipeline.*;

public class MyExecutor implements IExecutor{
    private IExecutable consumer;
    private IExecutable producer;
    private ConfigHandler config;

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
