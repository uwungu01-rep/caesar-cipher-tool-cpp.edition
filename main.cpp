#include <iostream>
#include <string>
#include <algorithm>

using str = std::string;
using std::cin;
using std::cout;
using std::getline;
using std::stoll;

str Trim(str input) {
    input.erase(0, input.find_first_not_of(" \t\n\r\f\v"));
    input.erase(input.find_last_not_of(" \t\n\r\f\v") + 1);
    return input;
}

bool IsInt(str& input) {
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

str Sort(int shift, str alphabet) {
    str shifted = "";
    int len = alphabet.length();
    for(int i = shift; i < len + shift; i++) {
        if(i < len) {
            shifted += alphabet[i];
            continue;
        }
        shifted += alphabet[abs(i - len)];
    }
    return shifted;
}

str Encipher(str alphabet, str shifted, str upper_alphabet, str shifted_upper, str user_input) {
    str output = "";
    for(char k : user_input) {
        if(alphabet.find(k) != str::npos) {
            output += shifted[alphabet.find(k)];
            continue;
        }
        else if(upper_alphabet.find(k) != str::npos) {
            output += shifted_upper[upper_alphabet.find(k)];
            continue;
        }
        output += k;
    }
    return output;
}

str Decipher(str alphabet, str shifted, str upper_alphabet, str shifted_upper, str user_input) {
    str output = "";
    for(char k : user_input) {
        if(shifted.find(k) != str::npos) {
            output += alphabet[shifted.find(k)];
            continue;
        }
        else if(shifted_upper.find(k) != str::npos) {
            output += upper_alphabet[shifted_upper.find(k)];
            continue;
        }
        output += k;
    }
    return output;
}

long long Algorithm(long long shift) {
    if(shift >= 0) {
        return shift % 26;
    }
    return shift = 26 + shift % 26;
}

int main() {
    const str alphabet = "abcdefghijklmnopqrstuvwxyz", upper_alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    str cmd, user_input, shift;
    while(true) {
        cout << "Type E for Deciphering, type D for Deciphering (Case insensitive). Type / to exit the program: "; getline(cin, cmd);
        bool run = true;
        if(cmd == "e" || cmd == "E") {
            while(run) {
                cout << "Your input: "; getline(cin , user_input);
                if(Trim(user_input).empty()) {
                    cout << "Input cannot be empty. \n"; 
                    continue;
                }   
                while(run) {
                    cout << "Shift (type / to cancel): "; getline(cin, shift);
                    if(shift == "/") {
                        run = false;
                    }
                    else if(IsInt(shift)) {
                        try {
                            str shifted = Sort(Algorithm(stoll(shift)), alphabet);
                            str shifted_upper = Sort(Algorithm(stoll(shift)), upper_alphabet);
                            cout << "Output: " << Encipher(alphabet, shifted, upper_alphabet, shifted_upper, user_input) << '\n';
                        }
                        catch(std::out_of_range) {
                            cout << "Why? \n";
                        }
                    }
                    else {
                        cout << "Invalid input. \n";
                    }
                }
            }
        }
        else if(cmd == "d" || cmd == "D") {
            while(run) {
                cout << "Your input: "; getline(cin, user_input);
                if(Trim(user_input).empty()) {
                    cout << "Input cannot be empty. \n";
                    continue;
                }
                while(run) {
                    cout << "Shift (type / to cancel): "; getline(cin, shift);
                    if(shift == "/") {
                        run = false;
                    }
                    else if(IsInt(shift)) {
                        try {
                            str shifted = Sort(Algorithm(stoll(shift)), alphabet);
                            str shifted_upper = Sort(Algorithm(stoll(shift)), upper_alphabet);
                            cout << "Output: " << Decipher(alphabet, shifted, upper_alphabet, shifted_upper, user_input) << '\n';
                        }
                        catch(std::out_of_range) {
                            cout << "Why? \n";
                        }
                    }
                    else {
                        cout << "Invalid input. \n";
                    }
                }
            }
        }
        else if(cmd == "/") {
            break;
        }
        else {
            cout << "Invalid command. \n";
        }
    }
    return 0;
}
