#include <iostream>
#include <string>
#include <algorithm>
#include "Caesar.h"
#include "Misc.h"
#include "Caesar.cpp"
#include "Misc.cpp"

using str = std::string;
using std::cin;
using std::cout;
using std::getline;
using std::stoll;

int main() {
    const str alphabet = "abcdefghijklmnopqrstuvwxyz", upper_alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const str COMMAND = "eEdD";
    str cmd, user_input, shift;
    while(true) {
        cout << "Type E for Deciphering, type D for Deciphering (Case insensitive). Type / to exit the program: "; getline(cin, cmd);
        if(cmd == "/") {
            break;
        }
        else if(COMMAND.find(cmd) == str::npos || cmd.length() != 1) {
            cout << "Invalid command. \n";
            continue;
        }
        while(true) {
            cout << "Your input: "; getline(cin , user_input);
            if(Misc::Trim(user_input).empty()) {
                cout << "Input cannot be empty. \n"; 
            }
            else {
                break;
            }
        }
        while(true) {
            cout << "Shift (type / to cancel): "; getline(cin, shift);
            try {
                if(shift == "/") {
                    break;
                }
                else if(Misc::IsInt(shift) && (cmd == "e" || cmd == "E")) {
                    int temp = Caesar::Algorithm(stoll(shift));
                    str shifted = Caesar::Sort(temp, alphabet);
                    str shifted_upper = Caesar::Sort(temp, upper_alphabet);
                    cout << "Output: " << Caesar::Cipher(alphabet, shifted, upper_alphabet, shifted_upper, user_input) << '\n';
                }
                else if(Misc::IsInt(shift) && (cmd == "d" || cmd == "D")) {
                    int temp = Caesar::Algorithm(-stoll(shift));
                    str shifted = Caesar::Sort(temp, alphabet);
                    str shifted_upper = Caesar::Sort(temp, upper_alphabet);
                    cout << "Output: " << Caesar::Cipher(alphabet, shifted, upper_alphabet, shifted_upper, user_input) << '\n';
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
    return 0;
}