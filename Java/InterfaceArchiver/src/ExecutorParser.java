public class ExecutorParser extends BaseParser {
    private String mode_token = "MODE";
    private String encode_mode_token = "Encode";
    private String decode_mode_token = "Decode";
    
    public ExecutorParser() {
        super();
        String[] gram_tokens = new String[] {mode_token};
        grammar = new ExtendedGrammar(gram_tokens);
    }

    public boolean isEncodeMode() {
        return dict.get(mode_token).equals(encode_mode_token);
    }

    public boolean isDecodeMode() {
        return dict.get(mode_token).equals(decode_mode_token);
    }
}
