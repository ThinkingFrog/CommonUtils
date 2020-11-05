import ru.spbstu.pipeline.IReader;
import ru.spbstu.pipeline.IExecutor;
import ru.spbstu.pipeline.IWriter;
import MyReader;

public class Manager {
    private IReader reader;
    private IExecutor executor;
    private IWriter writer;

    public Manager() {
        reader = new IReader();
        writer = new IWriter();
        executor = new IExecutor();
    }

    // Шаблон
    // Надо получать кодиков из каждого метода, чтобы проверить, что нигде не возникло ошибок
    public RunCoding() {
        manager.parse_config();

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
    }
}
