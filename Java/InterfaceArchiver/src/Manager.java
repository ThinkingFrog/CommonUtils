import ru.spbstu.pipeline.IReader;
import grammars.ManagerGrammar;
import ru.spbstu.pipeline.IExecutor;
import ru.spbstu.pipeline.IWriter;
import ru.spbstu.pipeline.RC;

public class Manager {
    private final IReader reader;
    private final IExecutor executor;
    private final IWriter writer;
    private final MyLogger logger;

    private final String[] gram_tokens;
    private final ManagerGrammar grammar;
    private final MyParser parser;

    public Manager(){
        reader = new MyReader();
        executor = new MyExecutor();
        writer = new MyWriter();
        logger = new MyLogger();

        gram_tokens = new String[] {"INPUT_FILE", "OUTPUT_FILE"};
        grammar = new ManagerGrammar(gram_tokens);
        parser = new MyParser(grammar);
    }

    // Шаблон
    // Надо получать коды из каждого метода, чтобы проверить, что нигде не возникло ошибок
    public RC run(String cfg_filename) {
        parser.Parse(cfg_filename);

        reader.setConfig(cfg1);
        writer.setConfig(cfg2);
        executor.setConfig(cfg3);

        reader.setConsumer(executor);
        executor.setProducer(reader);
        executor.setConsumer(writer);
        writer.setProducer(executor);

        reader.setInputStream(istream);
        writer.setOutputStream(ostream);
        
        reader.execute(null);

        return RC.CODE_SUCCESS;
    }
}
