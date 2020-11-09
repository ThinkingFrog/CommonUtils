public class WriterParser extends BaseParser {
    private String write_block_token = "BLOCK_SIZE";

    public WriterParser() {
        super();
        String[] gram_tokens = new String[] {write_block_token};
        grammar = new ExtendedGrammar(gram_tokens);
    }

    public int getWriteBlockSize() {
        return Integer.parseInt(dict.get(write_block_token));
    }
}
