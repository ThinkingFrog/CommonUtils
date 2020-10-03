public class ArgsValidater {
    private String[] args;

    public ArgsValidater(String[] args) {
        this.args = args;
    }

    public void ValidateLength() {
        if (args.length != 1)
            Errors.WrongCmdArgs.PrintError();
    }
}
