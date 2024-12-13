#ifndef MISC_H
#define MISC_H

#include <string>

class Misc {
    public:
        static bool IsInt(std::string& input);
        static std::string Trim(std::string input);
};

#endif