import ru.spbstu.pipeline.IReader;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

import ru.spbstu.pipeline.IExecutor;
import ru.spbstu.pipeline.IWriter;
import ru.spbstu.pipeline.RC;

public class Manager {
    private final IReader reader;
    private final IExecutor executor;
    private final IWriter writer;

    private final MyLogger logger;
    private final ManagerParser parser;

    public Manager(){
        reader = new MyReader();
        executor = new MyExecutor();
        writer = new MyWriter();
        
        logger = new MyLogger();
        parser = new ManagerParser();
    }

    // Шаблон
    // Надо получать коды из каждого метода, чтобы проверить, что нигде не возникло ошибок
    public RC run(String cfg_filename) {
        parser.Parse(cfg_filename);

        reader.setConfig(parser.getReaderConfig());
        writer.setConfig(parser.getWriterConfig());
        executor.setConfig(parser.getExecutorConfig());

        reader.setConsumer(executor);
        executor.setProducer(reader);
        executor.setConsumer(writer);
        writer.setProducer(executor);
        try {
        reader.setInputStream(new FileInputStream(parser.getInputFile()));
        writer.setOutputStream(new FileOutputStream(parser.getOutputFile()));
        }
        catch(IOException exc) {}
        
        reader.execute(null);

        return RC.CODE_SUCCESS;
    }
}
