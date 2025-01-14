#include <string>
#include <cstdlib>
#include "Caesar.h"

using str = std::string;

short Caesar::Algorithm(long long shift) {
    if(shift >= 0) {
        return shift % 26;
    }
    return 26 + shift % 26;
}

str Caesar::Sort(int shift, str alphabet) {
    str shifted = "";
    int len = alphabet.length();
    for(int i = shift; i < len + shift; i++) {
        if(i < len) {
            shifted += alphabet[i];
        }
        else {
            shifted += alphabet[std::abs(i - len)];
        }
    }
    return shifted;
}
str Caesar::Cipher(str alphabet, str shifted, str upper_alphabet, str shifted_upper, str user_input) {
    str output = "";
    for(char k : user_input) {
        if(alphabet.find(k) != str::npos) {
            output += shifted[alphabet.find(k)];
        }
        else if(upper_alphabet.find(k) != str::npos) {
            output += shifted_upper[upper_alphabet.find(k)];
        }
        else {
            output += k;
        }
    }
    return output;
}