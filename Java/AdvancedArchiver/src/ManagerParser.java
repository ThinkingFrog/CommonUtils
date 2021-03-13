import ru.spbstu.pipeline.*;

import java.lang.reflect.Constructor;
import java.lang.reflect.InvocationTargetException;
import java.util.HashMap;
import java.util.ArrayList;
import java.util.logging.Logger;

public class ManagerParser extends BaseParser {
    private final String input_file_token = "INPUT_FILE";
    private final String output_file_token = "OUTPUT_FILE";
    private final String reader_token = "READER";
    private final String reader_conf_token = "READER_CONFIG";
    private final String writer_token = "WRITER";
    private final String writer_conf_token = "WRITER_CONFIG";
    private final String executors_token = "EXECUTORS";
    private final String executors_confs_token = "EXECUTORS_CONFIGS";

    private IReader reader;
    private IWriter writer;
    private final HashMap<IExecutor, String> exec_configs;
    private final ArrayList<IExecutor> exec_list;


    public ManagerParser() {
        super();
        String[] gram_tokens = new String[] {input_file_token, output_file_token, reader_token, reader_conf_token,
                writer_token, writer_conf_token, executors_token, executors_confs_token};
        grammar = new ExtendedGrammar(gram_tokens);

        exec_configs = new HashMap<>();
        exec_list = new ArrayList<>();
    }

    @Override
    public RC Parse(String filename) {
        super.Parse(filename);

        reader = (IReader)Reflect(dict.get(reader_token));
        if (reader == null)
            return RC.CODE_CONFIG_SEMANTIC_ERROR;

        writer = (IWriter)Reflect(dict.get(writer_token));
        if (writer == null)
            return RC.CODE_CONFIG_SEMANTIC_ERROR;

        String[] executors_line = dict.get(executors_token).split(" ");
        for (int i = 0; i < executors_line.length; ++i) {
            // Remove symbols that are not related to actual value of string
            executors_line[i] = executors_line[i].trim();
            executors_line[i] = executors_line[i].replace(",", "");

            IExecutor executor = (IExecutor)Reflect(executors_line[i]);
            if (executor == null)
                return RC.CODE_CONFIG_SEMANTIC_ERROR;
            exec_list.add(executor);
        }

        String[] executors_confs_line = dict.get(executors_confs_token).split(" ");
        for (int i = 0; i < executors_confs_line.length; ++i) {
            // Remove symbols that are not related to actual value of string
            executors_confs_line[i] = executors_confs_line[i].trim();
            executors_confs_line[i] = executors_confs_line[i].replace("(", "");
            executors_confs_line[i] = executors_confs_line[i].replace(")", "");
            executors_confs_line[i] = executors_confs_line[i].replace(",", "");

            // Form dictionary of (executor, path-to-executor-config) pairs
            if (i % 2 == 1) {
                // Create IExecutor instance from String with class-name and put it into dictionary
                IExecutor executor = (IExecutor)Reflect(executors_confs_line[i - 1]);
                if (executor == null)
                    return RC.CODE_CONFIG_SEMANTIC_ERROR;
                exec_configs.put(executor, executors_confs_line[i]);
            }
        }

        return RC.CODE_SUCCESS;
    }

    private Object Reflect(String classname) {
        Object step = null;

        try {
            Class step_as_class = Class.forName(classname);
            Constructor[] constructors = step_as_class.getConstructors();
            if (constructors.length == 0)
                return RC.CODE_CONFIG_SEMANTIC_ERROR;

            for (Constructor constructor : constructors) {
                if (constructor.getParameterCount() == 0) {
                    step = constructor.newInstance();
                    break;
                }
                else if (constructor.getParameterCount() == 1) {
                    step = constructor.newInstance(Logger.getAnonymousLogger());
                    break;
                }
            }
        }

        catch (ClassNotFoundException | InstantiationException | IllegalAccessException | InvocationTargetException exc) {
            step = null;
        }

        return step;
    }

    public String getInputFile() {
        return dict.get(input_file_token);
    }

    public String getOutputFile() {
        return dict.get(output_file_token);
    }

    public IReader getReader() {
        return reader;
    }

    public String getReaderConfig() {
        return dict.get(reader_conf_token);
    }

    public IWriter getWriter() {
        return writer;
    }

    public String getWriterConfig() {
        return dict.get(writer_conf_token);
    }

    public ArrayList<IExecutor> getExecutorsList() {
        return exec_list;
    }

    public String getExecutorConfig(IExecutor exec) {
        return exec_configs.get(exec);
    }

}
