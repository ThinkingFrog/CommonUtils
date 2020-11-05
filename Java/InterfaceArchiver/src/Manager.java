import ru.spbstu.pipeline.IReader;
import ru.spbstu.pipeline.IExecutor;
import ru.spbstu.pipeline.IWriter;

public class Manager {
    private IReader reader;
    private IExecutor executor;
    private IWriter writer;

    public Manager() {
        reader = new MyReader();
        writer = new MyWriter();
        executor = new MyExecutor();
    }

    // Шаблон
    // Надо получать кодиков из каждого метода, чтобы проверить, что нигде не возникло ошибок
    public void RunCoding() {
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
