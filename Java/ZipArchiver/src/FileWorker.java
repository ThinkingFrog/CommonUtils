import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.FileInputStream;

public class FileWorker {
    public byte[] FillBytesBuffer(String filename, int buff_size) {
        byte[] buffer = new byte[buff_size];
        
        try (InputStream inFile = new FileInputStream(filename)) {
            while(inFile.read(buffer) != -1);
        }
        catch(IOException exc) {
            Errors.OpenFileErr.PrintError();
        }

        return buffer;
    }

    public int[] FillIntsBuffer(String filename, int buff_size) {
        int[] buffer = new int[buff_size];
        
        try (FileReader inFile = new FileReader(filename)) {
            int tmp;
            for (int i = 0; (tmp = inFile.read()) != -1; ++i)
                buffer[i] = tmp;
        }
        catch(IOException exc) {
            Errors.OpenFileErr.PrintError();
        }

        return buffer;
    }

    public int CountCharacters(String filename) {
        int file_size = 0;
        
        try(FileReader reader = new FileReader(filename)) {
            while (reader.read() != -1)
                ++file_size;
        }
        catch(IOException exc) {
            Errors.OpenFileErr.PrintError();
        }
        
        return file_size;
    }
}
