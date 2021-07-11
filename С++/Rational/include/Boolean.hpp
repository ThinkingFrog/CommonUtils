#pragma once

enum boolean {
    FALSE,
    TRUE,
    AMOUNT
};

//inline std::ostream& operator<<(std::ostream& out, const boolean& val) { return out << (val == TRUE ? "true" : "false"); }
inline std::string toString(boolean val) { return val == TRUE ? "true" : "false"; }