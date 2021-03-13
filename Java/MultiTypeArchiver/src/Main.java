import ru.spbstu.pipeline.RC;

import java.util.logging.Level;

public class Main {
    public static void main(String[] args) {
        RC err_code;

        CustomLogger logger = new CustomLogger("output.log");
        if (logger.getErrCode() != RC.CODE_SUCCESS) {
            CustomLogger newLogger = new CustomLogger();
            newLogger.log(Level.SEVERE, logger.getErrCode());
            return;
        }

        ArgsValidater validater = new ArgsValidater(args);
        err_code = validater.ValidateLength();
        if (err_code != RC.CODE_SUCCESS) {
            logger.log(Level.SEVERE, err_code);
            return;
        }
        String config_filename = args[0];

        Manager manager = new Manager();
        err_code = manager.run(config_filename);
        if (err_code != RC.CODE_SUCCESS)
            logger.log(Level.SEVERE, err_code);
        else
            logger.log(Level.INFO, err_code);
    }
}
