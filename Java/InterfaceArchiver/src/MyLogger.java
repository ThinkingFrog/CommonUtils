import java.util.HashMap;
import java.util.logging.Level;
import java.util.logging.Logger;
import ru.spbstu.pipeline.RC;

public class MyLogger {
    private final Logger logger = Logger.getLogger(MyLogger.class.getName());

    private final HashMap<RC, String> err_logs = new HashMap<>();

    public MyLogger() {
        err_logs.put(RC.CODE_SUCCESS, "Success");
        err_logs.put(RC.CODE_INVALID_ARGUMENT, "Received invalid argument");
        err_logs.put(RC.CODE_FAILED_TO_READ, "Can't read from stream");
        err_logs.put(RC.CODE_FAILED_TO_WRITE, "Can't write to stream");
        err_logs.put(RC.CODE_INVALID_INPUT_STREAM, "Can't open input stream");
        err_logs.put(RC.CODE_INVALID_INPUT_STREAM, "Can't open input stream");
        err_logs.put(RC.CODE_CONFIG_GRAMMAR_ERROR, "Wrong config grammatics");
        err_logs.put(RC.CODE_CONFIG_SEMANTIC_ERROR, "Wrong config semantics");
        err_logs.put(RC.CODE_FAILED_PIPELINE_CONSTRUCTION, "Can't initialize pipeline");
    }

    public void log(Level lvl, RC code) {
        logger.log(lvl, err_logs.get(code));
    }
}
