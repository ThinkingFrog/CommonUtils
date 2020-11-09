public class ManagerParser extends BaseParser {
    private String input_file_token = "INPUT_FILE";
    private String output_file_token = "OUTPUT_FILE";
    private String reader_conf_token = "READER_CONFIG";
    private String writer_conf_token = "WRITER_CONFIG";
    private String executor_conf_token = "EXECUTOR_CONFIG";

    public ManagerParser() {
        super();
        String[] gram_tokens = new String[] {input_file_token, output_file_token, reader_conf_token, writer_conf_token, executor_conf_token};
        grammar = new ExtendedGrammar(gram_tokens);
    }

    public String getInputFile() {
        return dict.get(input_file_token);
    }

    public String getOutputFile() {
        return dict.get(output_file_token);
    }

    public String getReaderConfig() {
        return dict.get(reader_conf_token);
    }

    public String getWriterConfig() {
        return dict.get(writer_conf_token);
    }

    public String getExecutorConfig() {
        return dict.get(executor_conf_token);
    }
}
