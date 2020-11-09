public class ReaderParser extends BaseParser{
    private String read_block_token = "BLOCK_SIZE";

    public ReaderParser() {
        super();
        String[] gram_tokens = new String[] {read_block_token};
        grammar = new ExtendedGrammar(gram_tokens);
    }

    public int getReadBlockSize() {
        return Integer.parseInt(dict.get(read_block_token));
    }
}
