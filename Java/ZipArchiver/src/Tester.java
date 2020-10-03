import java.io.FileReader;
import java.io.IOException;

public class Tester {
    private String input_file;
    private String output_file;

    public Tester(ConfigHandler cfg) {
        input_file = cfg.GetInputFileName();
        output_file = cfg.GetOutputFileName();
    }

    public void CompareInputOutputFiles() {
        try (FileReader inFile = new FileReader(input_file);
        FileReader outFile = new FileReader(output_file);) {
            if (inFile.read() != outFile.read())
                Errors.DecodingError.PrintError();
        }
        catch (IOException exc) {
            Errors.OpenFileErr.PrintError();
        }
    }
}
