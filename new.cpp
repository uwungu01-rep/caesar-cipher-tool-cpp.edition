#include <iostream>
#include <string>
#include <algorithm>

using str = std::string;
using std::cin;
using std::cout;

const str alp = "abcdefghijklmnopqrstuvwxyz";
const str alpcap = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

str chr;
str shf;

bool isDigit(str& input) {
    return all_of(input.begin(), input.end(), ::isdigit);
}

str sort(int shf, str alp) {
    str cip = "";
    int len = alp.length();
    for(int i = shf; i < len + shf; i++) {
        if(i < alp.length()) {
            cip += alp[i];
        }
        else {
            cip += alp[abs(i - len)];
        }
    }
    return cip;
}

str sortcap(int shf, str alpcap) {
    str cipcap = "";
    int len = alpcap.length();
    for(int i = shf; i < len + shf; i++) {
        if(i < alp.length()) {
            cipcap += alpcap[i];
        }
        else {
            cipcap += alpcap[abs(i - len)];
        }
    }
    return cipcap;
}

str Encipher(str alp, str cip, str alpcap, str cipcap, str chr) {
    str output = "";
    for(int k = 0; k < chr.length(); k++) {
        if(alp.find(chr[k]) != str::npos) {
            output += cip[alp.find(chr[k])];
        }
        else if(alpcap.find(chr[k]) != str::npos) {
            output += cipcap[alpcap.find(chr[k])];
        }
        else {
            output += chr[k];
        }
    }
    return output;
}

str Decipher(str alp, str cip, str alpcap, str cipcap, str chr) {
    str output = "";
    for(int k = 0; k < chr.length(); k++) {
        if(cip.find(chr[k]) != str::npos) {
            output += alp[cip.find(chr[k])];
        }
        else if(cipcap.find(chr[k]) != str::npos) {
            output += alpcap[cipcap.find(chr[k])];
        }
        else {
            output += chr[k];
        }
    }
    return output;
}

int main() {
    str cmd = "";
    while(true) {
        cout << "Type E for deciphering, type D for deciphering (Case insensitive). Type / to exit the program: ";
        std::getline(cin >> std::ws, cmd);
        bool bck = false;
        if(cmd == "e" || cmd == "E") {
            while(true) {
                if(bck) {
                    break;
                }

                cout << "Type your string: ";
                std::getline(cin >> std::ws, chr);
                while(true) {
                    cout << "Shift (from 1 to 25) (type / to cancel): ";
                    std::getline(cin >> std::ws, shf);

                    if(shf == "/") {
                        bck = true;
                        break;
                    }
                    else if(isDigit(shf)) {
                        int temp = stoi(shf);
                        if(temp < 1 || temp > 25) {
                            cout << "Input has to be greater than 1 and less than 25. \n";
                        }
                        else {
                            cout << "Output: " << Encipher(alp, sort(temp, alp), alpcap, sortcap(temp, alpcap), chr) << '\n';
                        }
                    }
                    else {
                        cout << "Invalid input. \n";
                    }
                }
            }
        }
        else if(cmd == "d" || cmd == "D") {
            while(true) {
                if(bck) {
                    break;
                }

                cout << "Type your string: ";
                std::getline(cin >> std::ws, chr);

                while(true) {   
                    cout << "Shift (from 1 to 25) (type / to cancel): ";
                    std::getline(cin >> std::ws, shf);
                    if(shf == "/") {
                        bck = true;
                        break;
                    }
                    else if(isDigit(shf)) {
                        int temp = stoi(shf);
                        if(temp < 1 || temp > 25) {
                            cout << "Input has to be greater than 1 and less than 25. \n";
                        }
                        else {
                            cout << "Output: " << Decipher(alp, sort(temp, alp), alpcap, sortcap(temp, alpcap), chr) << '\n';
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
