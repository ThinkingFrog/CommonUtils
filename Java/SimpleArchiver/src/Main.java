class Main {
    public static void main(String[] args) {
        ArgsValidater validater = new ArgsValidater(args);
        validater.ValidateLength();

        String config_filename = args[0];
        ConfigHandler cfg = new ConfigHandler(config_filename);

        Coder coder = new Coder(cfg);
        coder.Encode();
        coder.Decode();

        Tester tester = new Tester(cfg);
        tester.CompareInputOutputFiles();
    }
}