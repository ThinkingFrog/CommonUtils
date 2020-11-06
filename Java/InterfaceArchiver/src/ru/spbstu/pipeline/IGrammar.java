package ru.spbstu.pipeline;

public interface IGrammar {
    int numberTokens();
    String delimiter();
    String token(int index);
}
