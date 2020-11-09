public class ExecutorParser extends BaseParser {
    private String mode_token = "MODE";
    
    public ExecutorParser() {
        super();
        String[] gram_tokens = new String[] {mode_token};
        grammar = new ExtendedGrammar(gram_tokens);
    }

    public String getMode() {
        return dict.get(mode_token);
    }
}
