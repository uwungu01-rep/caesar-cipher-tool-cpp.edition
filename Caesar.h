#ifndef CAESAR_H
#define CAESAR_H

#include <string>

class Caesar {
    public:
        static std::string Cipher(std::string alphabet, std::string shifted, std::string upper_alphabet, std::string shifted_upper, std::string user_input);
        static std::string Sort(int shift, std::string alphabet);
        static short Algorithm(long long shift);
};

#endif