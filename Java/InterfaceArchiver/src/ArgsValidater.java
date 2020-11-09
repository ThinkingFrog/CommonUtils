import ru.spbstu.pipeline.RC;

public class ArgsValidater {
    private String[] args;

    public ArgsValidater(String[] args) {
        this.args = args;
    }

    public RC ValidateLength() {
        if (args.length != 1)
            return RC.CODE_INVALID_ARGUMENT;
        return RC.CODE_SUCCESS;
    }
}
