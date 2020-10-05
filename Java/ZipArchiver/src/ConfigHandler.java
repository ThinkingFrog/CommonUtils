import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;

public class ConfigHandler {
    private String input_file;
    private String output_file;
    private String zip_file;
    private int block_size;

    public ConfigHandler(String filename) {
        try (FileReader reader = new FileReader(filename);
            Scanner scanner = new Scanner(reader);) {
            while (scanner.hasNextLine()) {
                String line[] = scanner.nextLine().split(ConfigSyntax.delimeter);
                ProcLine(line);
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

    public String GetInputFileName() {
        return input_file;
    }

    public String GetZipFileName() {
        return zip_file;
    }

    public String GetOutputFileName() {
        return output_file;
    }

    public int GetBlockSize() {
        return block_size;
    }
}

enum ConfigSyntax {
    INPUT_FILE_NAME,
    ZIP_FILE_NAME,
    OUTPUT_FILE_NAME;

    public static final String delimeter = "=";
}