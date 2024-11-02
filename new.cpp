#include <iostream>
#include <string>
#include <algorithm>

using str = std::string; 
using std::cin; 
using std::cout; 
using std::getline;

const str alphabet = "abcdefghijklmnopqrstuvwxyz", upper_alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

bool IsInt(str input) {
    try {
        stoi(input);
        return true;
    }
    catch(...) {
        return false;
    }
}

str Trim(std::string& input) {
    input.erase(0, input.find_first_not_of(" \t\n\r\f\v"));
    input.erase(input.find_last_not_of(" \t\n\r\f\v") + 1);
    return input;
}

str Sort(int shift, str alphabet) {
    str ciphered = "";
    int len = alphabet.length();
    for(int i = shift; i < len + shift; i++) {
        if(i < len) {
            ciphered += alphabet[i];
            continue;
        }
        ciphered += alphabet[abs(i - len)];
    }
    return ciphered;
}

str Sortcap(int shift, str upper_alphabet) {
    str ciphered_upper = "";
    int len = upper_alphabet.length();
    for(int i = shift; i < len + shift; i++) {
        if(i < len) {
            ciphered_upper += upper_alphabet[i];
            continue;
        }
        ciphered_upper += upper_alphabet[abs(i - len)];
    }
    return ciphered_upper;
}

str Encipher(str alphabet, str ciphered, str upper_alphabet, str ciphered_upper, str user_input) {
    str output = "";
    for(int k = 0; k < user_input.length(); k++) {
        if(alphabet.find(user_input[k]) != str::npos) {
            output += ciphered[alphabet.find(user_input[k])];
            continue;
        }
        else if(upper_alphabet.find(user_input[k]) != str::npos) {
            output += ciphered_upper[upper_alphabet.find(user_input[k])];
            continue;
        }
        output += user_input[k];
    }
    return output;
}

str Decipher(str alphabet, str ciphered, str upper_alphabet, str ciphered_upper, str user_input) {
    str output = "";
    for(int k = 0; k < user_input.length(); k++) {
        if(ciphered.find(user_input[k]) != str::npos) {
            output += alphabet[ciphered.find(user_input[k])];
            continue;
        }
        else if(ciphered_upper.find(user_input[k]) != str::npos) {
            output += upper_alphabet[ciphered_upper.find(user_input[k])];
            continue;
        }
        output += user_input[k];
    }
    return output;
}

int Algorithm(int shift) {
    int temp = shift;
    if(temp >= 0) {
        temp = temp % 26;
        return temp;
    }
    while(temp < 0) {
        temp = (26 + temp) % 26;
    }
    return temp;
}

int main() {
    str cmd = "", user_input, shift;
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
                        cout << "Output: " << Encipher(alphabet, Sort(Algorithm(stoi(shift)), alphabet), upper_alphabet, Sortcap(Algorithm(stoi(shift)), upper_alphabet), user_input) << '\n';
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
                    cout << "Input cannot be empty. \n";\
                    continue;
                }
                while(run) {
                    cout << "Shift (type / to cancel): "; getline(cin, shift);
                    if(shift == "/") {
                        run = false;
                    }
                    else if(IsInt(shift)) {
                        cout << "Output: " << Decipher(alphabet, Sort(Algorithm(stoi(shift)), alphabet), upper_alphabet, Sortcap(Algorithm(stoi(shift)), upper_alphabet), user_input) << '\n';
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
