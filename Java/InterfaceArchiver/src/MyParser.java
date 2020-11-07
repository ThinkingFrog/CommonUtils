import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;
import java.util.HashMap;
import ru.spbstu.pipeline.RC;
import ru.spbstu.pipeline.BaseGrammar;

public class MyParser {
    private BaseGrammar grammar;
    private HashMap<String, String> dict;

    public MyParser(BaseGrammar curGrammar) {
        grammar = curGrammar;
        dict = new HashMap<>();
    }

    public RC Parse(String filename) {
        try (FileReader reader = new FileReader(filename);
            Scanner scanner = new Scanner(reader);) {
            while (scanner.hasNextLine()) {
                String[] line = scanner.nextLine().split(grammar.delimiter());
                
                if (line.length != 2)
                    return RC.CODE_CONFIG_SEMANTIC_ERROR;

                for (int i = 0; i < grammar.numberTokens(); ++i)
                    if (grammar.token(i) == line[0]) {
                        dict.put(line[0], line[1]);
                        break;
                    }
            }
        }
        catch (IOException exc) {
            return RC.CODE_FAILED_PIPELINE_CONSTRUCTION;
        }
        
        return RC.CODE_SUCCESS;
    }
}
