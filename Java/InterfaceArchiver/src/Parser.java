import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.HashMap;

public abstract class Parser {
    private ArrayList<String> cfg_lines;
    private final String delimeter = "=";
    private HashMap<String, String> parsed = new HashMap<>();

    public Parser(String filename) {
        try (FileReader reader = new FileReader(filename);
            Scanner scanner = new Scanner(reader);) {
            while (scanner.hasNextLine()) {
                String line = scanner.nextLine();
                cfg_lines.add(line);
            }
        }
        catch (IOException exc) {
            Errors.OpenFileErr.PrintError();
        }
    }

    private void ProcLine(String[] line) {

        if (line.length != 2)
            Errors.WrongConfigDelimeter.PrintError();
        
        for (int i = 0; i < line.length; ++i)
            line[i] = line[i].strip();
        
        switch (ConfigSyntax.valueOf(line[0])) {
            case INPUT_FILE_NAME:
                input_file = line[1];
            break;
            case ZIP_FILE_NAME:
                zip_file = line[1];
            break;
            case OUTPUT_FILE_NAME:
                output_file = line[1];
            break;
            default:
                Errors.WrongConfigFormat.PrintError();
            break;
        }
    }
}
