#pragma once
#include <functional>
#include <string>
#include <vector>
#include <map>
#include "Subject.hpp"

class Wrapper {
private:
    std::map<std::string, int> defaultArgs;
    std::function<int(const std::vector<int>&)> caller;

    template <class Subject, class Func, size_t... Index>
    int ExecFunc(Subject* subj, Func func, const std::vector<int>& args, std::index_sequence<Index...>) {
        return ((subj->*func)(args[Index]...));
    }

    std::vector<int> MergeArgs(const std::map<std::string, int>& args) {
        std::vector<int> mergedArgs;

        for (auto pair : defaultArgs)
            if (args.find(pair.first) == args.end())
                mergedArgs.push_back(pair.second);
            else
                mergedArgs.push_back(args.find(pair.first)->second);

        return mergedArgs;
    }
public:
    template <class Subject, class... Args>
    Wrapper(Subject* subj, int (Subject::*func)(Args...), const std::map<std::string, int>& args) {
        defaultArgs = args;

        auto lambda = [this, subj, func](const std::vector<int>& args) { return ExecFunc(subj, func, args, std::make_index_sequence<sizeof... (Args)>{}); };
        caller = static_cast<std::function<int(const std::vector<int>&)>>(lambda);
    }

    ~Wrapper() = default;

    int execute(const std::map<std::string, int>& args) {
        return caller(MergeArgs(args));
    }
};