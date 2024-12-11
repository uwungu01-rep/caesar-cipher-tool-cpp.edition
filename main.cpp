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

str Caesar(str alphabet, str shifted, str upper_alphabet, str shifted_upper, str user_input) {
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

long long Algorithm(long long shift) {
    if(shift >= 0) {
        return shift % 26;
    }
    return shift = 26 + shift % 26;
}

int main() {
    const str alphabet = "abcdefghijklmnopqrstuvwxyz", upper_alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const str COMMAND = "eEdD";
    str cmd, user_input, shift;
    while(true) {
        bool run = true;
        cout << "Type E for Deciphering, type D for Deciphering (Case insensitive). Type / to exit the program: "; getline(cin, cmd);
        if(cmd == "/") {
            break;
        }
        else if(COMMAND.find(cmd) == str::npos) {
            cout << "Invalid command. \n";
            continue;
        }
        while(run) {
            cout << "Your input: "; getline(cin , user_input);
            if(Trim(user_input).empty()) {
                cout << "Input cannot be empty. \n"; 
                continue;
            }
            while(run) {
                cout << "Shift (type / to cancel): "; getline(cin, shift);
                try {
                    if(shift == "/") {
                        run = false;
                    }
                    else if(IsInt(shift) && (cmd == "e" || cmd == "E")) {
                        str shifted = Sort(Algorithm(stoll(shift)), alphabet);
                        str shifted_upper = Sort(Algorithm(stoll(shift)), upper_alphabet);
                        cout << "Output: " << Caesar(alphabet, shifted, upper_alphabet, shifted_upper, user_input) << '\n';
                    }
                    else if(IsInt(shift) && (cmd == "d" || cmd == "D")) {
                        str shifted = Sort(Algorithm(-stoll(shift)), alphabet);
                        str shifted_upper = Sort(Algorithm(-stoll(shift)), upper_alphabet);
                        cout << "Output: " << Caesar(alphabet, shifted, upper_alphabet, shifted_upper, user_input) << '\n';
                    }
                    else {
                        cout << "Invalid input. \n";
                    }
                }
                catch(std::out_of_range) {
                    cout << "Why? \n";
                }
            }
        }
    }
    return 0;
}
