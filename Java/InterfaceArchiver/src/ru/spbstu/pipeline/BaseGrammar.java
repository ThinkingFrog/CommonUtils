package ru.spbstu.pipeline;

public abstract class BaseGrammar implements IGrammar {

    private final String[] tokens;
    private static final String delimiter = "=";

    protected BaseGrammar(String[] tokens) {
        assert tokens != null;

        this.tokens = tokens;
    }

    @Override
    public final int numberTokens() {
        return this.tokens.length;
    }

    @Override
    public final String token(int index) {
        assert index >= 0;

        return this.tokens[index];
    }

    @Override
    public String delimiter() {
        return this.delimiter;
    }
}
