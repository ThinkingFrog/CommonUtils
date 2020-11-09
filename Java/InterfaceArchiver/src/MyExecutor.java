import ru.spbstu.pipeline.*;

public class MyExecutor implements IExecutor{
    private IExecutable consumer;
    private IExecutable producer;
    private ExecutorParser parser;

    public RC setConsumer(IExecutable c) {
        consumer = c;
        return RC.CODE_SUCCESS;
    }

    public RC setProducer(IExecutable p) {
        producer = p;
        return RC.CODE_SUCCESS;
    }
    
    public RC execute(byte [] data) {
        if (parser.isEncodeMode()) {

        }
        else if (parser.isDecodeMode()) {

        }
        else
            return RC.CODE_CONFIG_GRAMMAR_ERROR;
            
        return RC.CODE_SUCCESS;
    }

    public RC setConfig(String filename) {
        parser = new ExecutorParser();
        parser.Parse(filename);
        return RC.CODE_SUCCESS;
    }
}
