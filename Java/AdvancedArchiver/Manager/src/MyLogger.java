import java.io.IOException;
import java.util.HashMap;
import java.util.logging.FileHandler;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.util.logging.SimpleFormatter;

import ru.spbstu.pipeline.RC;

public class MyLogger {
    private final Logger logger = Logger.getLogger(MyLogger.class.getName());
    private RC err_code;
    private final HashMap<RC, String> err_logs = new HashMap<>();

    public MyLogger() {
        InitErrLogs();
        err_code = RC.CODE_SUCCESS;
    }

    public MyLogger(String filename) {
        InitErrLogs();
        try {
            FileHandler fh = new FileHandler(filename);
            SimpleFormatter sf = new SimpleFormatter();
            fh.setFormatter(sf);

            logger.addHandler(fh);
            logger.setUseParentHandlers(false);

            err_code = RC.CODE_SUCCESS;
        }
        catch (IOException exc) {
            err_code = RC.CODE_INVALID_ARGUMENT;
        }
    }

    private void InitErrLogs() {
        err_logs.put(RC.CODE_SUCCESS, "Success");
        err_logs.put(RC.CODE_INVALID_ARGUMENT, "Received invalid argument");
        err_logs.put(RC.CODE_FAILED_TO_READ, "Can't read from stream");
        err_logs.put(RC.CODE_FAILED_TO_WRITE, "Can't write to stream");
        err_logs.put(RC.CODE_INVALID_INPUT_STREAM, "Can't open input stream");
        err_logs.put(RC.CODE_INVALID_OUTPUT_STREAM, "Can't open output stream");
        err_logs.put(RC.CODE_CONFIG_GRAMMAR_ERROR, "Wrong config grammar");
        err_logs.put(RC.CODE_CONFIG_SEMANTIC_ERROR, "Wrong config semantics");
        err_logs.put(RC.CODE_FAILED_PIPELINE_CONSTRUCTION, "Can't construct pipeline");
    }

    public void log(Level lvl, RC code) {
        logger.log(lvl, err_logs.get(code));
    }

    public RC getErrCode() {
        return err_code;
    }
}
