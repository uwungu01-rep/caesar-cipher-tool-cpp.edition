#include <string>
#include <cstdlib>
#include "Caesar.h"

int Caesar::Algorithm(long long shift) {
    if(shift >= 0) {
        return shift % 26;
    }
    return 26 + shift % 26;
}

std::string Caesar::Sort(int shift, std::string alphabet) {
    std::string shifted = "";
    int len = alphabet.length();
    for(int i = shift; i < len + shift; i++) {
        if(i < len) {
            shifted += alphabet[i];
            continue;
        }
        shifted += alphabet[std::abs(i - len)];
    }
    return shifted;
}
std::string Caesar::Cipher(std::string alphabet, std::string shifted, std::string upper_alphabet, std::string shifted_upper, std::string user_input) {
    std::string output = "";
    for(char k : user_input) {
        if(alphabet.find(k) != std::string::npos) {
            output += shifted[alphabet.find(k)];
        }
        else if(upper_alphabet.find(k) != std::string::npos) {
            output += shifted_upper[upper_alphabet.find(k)];
        }
        else {
            output += k;
        }
    }
    return output;
}
