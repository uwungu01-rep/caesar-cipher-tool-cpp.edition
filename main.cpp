#include <iostream>
#include <string>
#include <algorithm>

using str = std::string;
using std::cin;
using std::cout;
using std::getline;

bool IsInt(str input) {
    if(input.find(".") != str::npos) {
        return false;
    }
    try {
        stoi(input);
        return true;
    }
    catch(...) {
        return false;
    }
}

str Trim(str input) {
    input.erase(0, input.find_first_not_of(" \t\n\r\f\v"));
    input.erase(input.find_last_not_of(" \t\n\r\f\v") + 1);
    return input;
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
    for(int k = 0; k < user_input.length(); k++) {
        if(alphabet.find(user_input[k]) != str::npos) {
            output += shifted[alphabet.find(user_input[k])];
            continue;
        }
        else if(upper_alphabet.find(user_input[k]) != str::npos) {
            output += shifted_upper[upper_alphabet.find(user_input[k])];
            continue;
        }
        output += user_input[k];
    }
    return output;
}

str Decipher(str alphabet, str shifted, str upper_alphabet, str shifted_upper, str user_input) {
    str output = "";
    for(int k = 0; k < user_input.length(); k++) {
        if(shifted.find(user_input[k]) != str::npos) {
            output += alphabet[shifted.find(user_input[k])];
            continue;
        }
        else if(shifted_upper.find(user_input[k]) != str::npos) {
            output += upper_alphabet[shifted_upper.find(user_input[k])];
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
    const str alphabet = "abcdefghijklmnopqrstuvwxyz", upper_alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    str cmd = "", user_input, shift;
    while(true) {
        cout << "Type E for Enciphering, type D for Deciphering (Case insensitive). Type / to exit the program: "; getline(cin, cmd);
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
                        str shifted = Sort(Algorithm(stoi(shift)), alphabet);
                        str shifted_upper = Sort(Algorithm(stoi(shift)), upper_alphabet);
                        cout << "Output: " << Encipher(alphabet, shifted, upper_alphabet, shifted_upper, user_input) << '\n';
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
                        str shifted = Sort(Algorithm(stoi(shift)), alphabet);
                        str shifted_upper = Sort(Algorithm(stoi(shift)), upper_alphabet);
                        cout << "Output: " << Decipher(alphabet, shifted, upper_alphabet, shifted_upper, user_input) << '\n';
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
