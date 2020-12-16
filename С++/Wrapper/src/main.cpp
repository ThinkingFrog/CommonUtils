#include <iostream>
#include "Engine.hpp"
#include "Subject.hpp"

int main() {
    Engine engine;
    Subject subj;

    Wrapper wrapperOfTwo(&subj, &Subject::sumOfTwo, { {"arg1", 5}, {"arg2", 6} });
    Wrapper wrapperOfThree(&subj, &Subject::sumOfThree, { {"arg1", 5}, {"arg2", 6}, {"arg3", 10} });
    Wrapper wrapperOfFour(&subj, &Subject::sumOfFour, { {"arg1", 5}, {"arg2", 6}, {"arg3", 10}, {"arg4", 50} });

    engine.register_command(&wrapperOfTwo, "command1");
    engine.register_command(&wrapperOfThree, "command2");
    engine.register_command(&wrapperOfFour, "command3");

    std::cout << "4 + 5 = " << engine.execute("command1", { {"arg1", 4}, {"arg2", 5} }) << std::endl;
    std::cout << "4 + 6 + 500 = " << engine.execute("command2", { {"arg1", 4}, {"arg3", 500} }) << std::endl;
    std::cout << "5 + 6 + 10 + 50 = " << engine.execute("command3", {}) << std::endl;

}