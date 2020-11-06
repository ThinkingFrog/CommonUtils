import ru.spbstu.pipeline.IReader;
import ru.spbstu.pipeline.IExecutor;
import ru.spbstu.pipeline.IWriter;

public class Manager {
    private IReader reader = new MyReader();
    private IExecutor executor = new MyExecutor();
    private IWriter writer = new MyWriter();
    
    private MyLogger logger = new MyLogger();

    // Шаблон
    // Надо получать коды из каждого метода, чтобы проверить, что нигде не возникло ошибок
    public static void main(String[] args) {
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
