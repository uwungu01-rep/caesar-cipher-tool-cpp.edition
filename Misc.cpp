#include "Misc.h"
#include <cctype>
#include <string>

std::string Misc::Trim(std::string input) {
    input.erase(0, input.find_first_not_of(" \t\n\r\f\v"));
    input.erase(input.find_last_not_of(" \t\n\r\f\v") + 1);
    return input;
}

bool Misc::IsInt(std::string& input) {
    int start = 0;

    if(Trim(input).empty()) {
        return false;
    }

    if(input[0] == '+' || input[0] == '-') {
        if(input.length() == 1) {
            return false;
        }
        start = 1;
    }

    for(int i = start; i < input.length(); i++) {
        if(!std::isdigit(input[i])) {
            return false;
        }
    }
    return true;
}
