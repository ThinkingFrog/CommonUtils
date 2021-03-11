public class ReaderParser extends BaseParser {
    private final String read_block_token = "BLOCK_SIZE";

    public ReaderParser() {
        super();
        String[] gram_tokens = new String[] {read_block_token};
        grammar = new ExtendedGrammar(gram_tokens);
    }

    public int getReadBlockSize() {
        int block_size = Integer.parseInt(dict.get(read_block_token));
        if (block_size > 255)
            block_size = 255;

        return block_size;
    }
}
