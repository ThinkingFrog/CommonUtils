import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.HashMap;
import ru.spbstu.pipeline.BaseGrammar;

public abstract class Parser extends BaseGrammar{
    private ArrayList<String> cfg_lines;

    public Parser(String filename) {
        try (FileReader reader = new FileReader(filename);
            Scanner scanner = new Scanner(reader);) {
            while (scanner.hasNextLine()) {
                String line = scanner.nextLine();
                cfg_lines.add(line);
            }
        }
        catch (IOException exc) {
            ;
        }
    }

    public void Parse() {
        for (String line : cfg_lines) {
            String[] parsed_line = line.split("=");
            if (parsed_line.length == 2) {
                parsed.put(parsed_line[0].strip(), parsed_line[1].strip());
            }
        }
    }
}
