import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.ArrayList;

import ru.spbstu.pipeline.IReader;
import ru.spbstu.pipeline.IExecutor;
import ru.spbstu.pipeline.IWriter;
import ru.spbstu.pipeline.RC;
import ru.spbstu.pipeline.IConsumer;

public class Manager {
    private IReader reader;
    private IWriter writer;
    private ArrayList<IExecutor> executors;

    private final ManagerParser parser;

    public Manager() {
        parser = new ManagerParser();
    }

    public RC run(String cfg_filename) {
        RC err_code;

        err_code = parser.Parse(cfg_filename);
        if (err_code != RC.CODE_SUCCESS)
            return err_code;

        reader = parser.getReader();
        writer = parser.getWriter();
        executors = parser.getExecutorsList();

        err_code = reader.setConfig(parser.getReaderConfig());
        if (err_code != RC.CODE_SUCCESS)
            return err_code;
        err_code = writer.setConfig(parser.getWriterConfig());
        if (err_code != RC.CODE_SUCCESS)
            return err_code;
        for (IExecutor exec : executors) {
            err_code = exec.setConfig(parser.getExecutorConfig(exec));
            if (err_code != RC.CODE_SUCCESS)
                return err_code;
        }

        try {
            err_code = reader.setInputStream(new FileInputStream(parser.getInputFile()));
            if (err_code != RC.CODE_SUCCESS)
                return err_code;

            err_code = writer.setOutputStream(new FileOutputStream(parser.getOutputFile()));
            if (err_code != RC.CODE_SUCCESS)
                return err_code;
        }
        catch(IOException exc) {
            return RC.CODE_FAILED_PIPELINE_CONSTRUCTION;
        }

        err_code = reader.setConsumer(executors.get(0));
        if (err_code != RC.CODE_SUCCESS)
            return err_code;

        executors.get(0).setProducer(reader);
        if (executors.size() > 1)
            executors.get(0).setConsumer(executors.get(1));
        for (int i = 1; i < executors.size() - 1; ++i) {
            err_code = executors.get(i).setConsumer(executors.get(i + 1));
            if (err_code != RC.CODE_SUCCESS)
                return err_code;
            err_code = executors.get(i).setProducer(executors.get(i - 1));
            if (err_code != RC.CODE_SUCCESS)
                return err_code;
        }
        if (executors.size() > 1)
            executors.get(executors.size() - 1).setProducer(executors.get(executors.size() - 2));
        executors.get(executors.size() - 1).setConsumer(writer);

        writer.setProducer(executors.get(executors.size() - 1));

        err_code = reader.execute();
        return err_code;
    }
}
