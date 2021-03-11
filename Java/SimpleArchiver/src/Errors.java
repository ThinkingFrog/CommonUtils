import java.util.logging.Level;
import java.util.logging.Logger;

enum Errors {
    OpenFileErr("Couldn't load file"),
    WrongConfigDelimeter("Wrong delimeter used in configuration file"),
    WrongConfigFormat("Wrong string format used in configuration file"),
    WrongCmdArgs("Wrong command line arguments format"),
    DecodingError("Input and output files don't match");

    private final Logger logger = Logger.getLogger(Errors.class.getName());
    
    private String msg;
    Errors(String msg) {
        this.msg = msg;
    }

    void PrintError() {
        logger.log(Level.WARNING, msg);
    }
}