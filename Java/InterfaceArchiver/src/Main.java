public class Main {
    public static void main(String[] args) {
        ArgsValidater validater = new ArgsValidater(args);
        validater.ValidateLength();

        String config_filename = args[0];

        Manager manager = new Manager();
        manager.run(config_filename);
    }
}
