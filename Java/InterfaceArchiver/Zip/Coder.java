import java.io.FileWriter;
import java.io.IOException;

public class Coder {
    private String input_file;
    private String zip_file;
    private String output_file;

    public Coder(ConfigHandler cfg) {
        input_file = cfg.GetInputFileName();
        zip_file = cfg.GetZipFileName();
        output_file = cfg.GetOutputFileName();
    }

    public void Encode() {
        // Used to handle secondary tasks
        FileWorker FWorker = new FileWorker();

        // Get size of input file as amount of characters
        int input_file_size = FWorker.CountCharacters(input_file);
        
        // Count maximum amount of possible pairs in file
        int max_dict_size = input_file_size / 2 + input_file_size % 2;
        
        // Amount of bytes coded as single array element
        int block_size = 2;
        
        // Input file characters represented as array of bytes
        byte[] inBuffer = FWorker.FillBytesBuffer(input_file, input_file_size);
        // Coding dictionary declaration
        byte[][] dict = new byte[max_dict_size][block_size];
        // Real size of dictionary
        int dict_size;
        // Encoded file buffer
        int[] zipBuffer = new int[max_dict_size];
        
        // Filling dictionary from buffer and writing coded file to buffer in parallel
        dict_size = FillDictAndZipBuff(inBuffer, block_size, dict, zipBuffer);

        // Write one after another to zip file:
        // 1) Real size of dictionary (amount of filled pairs)
        // 2) Dictionary as sequence of bytes
        // 3) Coded text as sequence of dictionary indexes
        WriteDataToZipFile(dict, dict_size, zipBuffer, block_size);
    }

    public void Decode() {
        // Used to handle secondary tasks
        FileWorker FWorker = new FileWorker();
        
        // Decoding file
        try (FileWriter inFile = new FileWriter(output_file)) {
            // Read whole file into bytes buffer
            byte[] iBuffer = FWorker.FillBytesBuffer(zip_file, FWorker.CountCharacters(zip_file));

            // Read size of dictionary
            int dict_size = iBuffer[0];

            // Read dictionary and save it
            byte[][] dict = new byte[dict_size][2];
            for (int dict_i = 0, buff_i = 1; dict_i < dict_size; ++dict_i, buff_i += 2) {
                dict[dict_i][0] = (byte)iBuffer[buff_i];
                dict[dict_i][1] = (byte)iBuffer[buff_i + 1];
            }

            // Read coded character
            // Decode it using dictionary
            // Write decoded character to output file
            for (int i = dict_size * 2 + 1; i < iBuffer.length; ++i) {
                inFile.write(dict[iBuffer[i]][0]);
                if (dict[iBuffer[i]][1] != 0)
                    inFile.write(dict[iBuffer[i]][1]);
            }
        }
        catch(IOException exc) {
            Errors.OpenFileErr.PrintError();
        }
    }

    // Runs through dict and checks if any of its subarrays match given array
    private int BlockAlreadyExists(byte[][] dict, byte[] block) {
        for (int dict_i = 0; dict_i < dict.length; ++dict_i)
            for (int block_i = 0; block_i < block.length; ++block_i)
                if (dict[dict_i][block_i] == block[block_i])
                    return dict_i;
        return -1;
    }

    private int FillDictAndZipBuff(byte[] inBuffer, int block_size, byte[][] dict, int[] zipBuffer) {
        int dict_size = 0;
        for (int buff_i = 0, zip_i = 0; buff_i < inBuffer.length - block_size + 1; buff_i += block_size, ++zip_i) {
            // Create array of bytes currently being proccessed 
            byte[] bytes_block = new byte[block_size];
            for (int block_i = 0; block_i < block_size; ++block_i)
                bytes_block[block_i] = inBuffer[buff_i + block_i];

            // Check if a pair is already coded in dictionary
            // Returns -1 if pair doesn't already exist
            // Returns pair index if it already exists
            int code = BlockAlreadyExists(dict, bytes_block);
            // If pair doesn't already exist, write it
            if (code == -1) {
                for (int pair_i = 0; pair_i < block_size; ++pair_i) {
                    dict[dict_size][pair_i] = inBuffer[buff_i + pair_i];
                }
                code = dict_size++;
            }
            
            // Write pair index in output buffer
            zipBuffer[zip_i] = code;
            
            // Handles case of uneven-sized files
            // If last pair consists of only one element, fill only first element
            if (buff_i + block_size == inBuffer.length - 1) {
                ++zip_i;
                dict[dict_size][0] = inBuffer[buff_i + 2];
                code = dict_size++;
                zipBuffer[zip_i] = code;
            }
        }
        return dict_size;
    }

    private void WriteDataToZipFile(byte[][] dict, int dict_size, int[] zipBuffer, int block_size) {
        try (FileWriter zipWriter = new FileWriter(zip_file)) {
            // Write size of dictionary
            zipWriter.write(dict_size);
            
            // Write dictionary into file
            for (byte[] tmp : dict) {
                if (tmp[0] == 0)
                    break;
                for (int block_i = 0; block_i < block_size; ++block_i)
                    zipWriter.write(tmp[block_i]);
            }

            // Write coded text into file
            for (int tmp : zipBuffer)
                zipWriter.write(tmp);
        }
        catch (IOException exc) {
            Errors.OpenFileErr.PrintError();
        }
    }
}
