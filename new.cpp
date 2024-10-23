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

bool isDigit(str input) {
    str temp = input;
    if(temp.find("-") == 0) {
        temp.str::erase(0);
    }
    return all_of(temp.begin(), temp.end(), ::isdigit);
}

str sort(int shf, str alp) {
    str cip = "";
    int len = alp.length();
    for(int i = shf; i < len + shf; i++) {
        if(i < len) {
            cip += alp[i];
            continue;
        }
        cip += alp[abs(i - len)];
    }
    return cip;
}

str sortcap(int shf, str alpcap) {
    str cipcap = "";
    int len = alpcap.length();
    for(int i = shf; i < len + shf; i++) {
        if(i < len) {
            cipcap += alpcap[i];
            continue;
        }
        cipcap += alpcap[abs(i - len)];
    }
    return cipcap;
}

str Encipher(str alp, str cip, str alpcap, str cipcap, str chr) {
    str output = "";
    for(int k = 0; k < chr.length(); k++) {
        if(alp.find(chr[k]) != str::npos) {
            output += cip[alp.find(chr[k])];
            continue;
        }
        else if(alpcap.find(chr[k]) != str::npos) {
            output += cipcap[alpcap.find(chr[k])];
            continue;
        }
        output += chr[k];
    }
    return output;
}

str Decipher(str alp, str cip, str alpcap, str cipcap, str chr) {
    str output = "";
    for(int k = 0; k < chr.length(); k++) {
        if(cip.find(chr[k]) != str::npos) {
            output += alp[cip.find(chr[k])];
            continue;
        }
        else if(cipcap.find(chr[k]) != str::npos) {
            output += alpcap[cipcap.find(chr[k])];
            continue;
        }
        output += chr[k];
    }
    return output;
}

int algorithm(int shf) {
    int temp = shf;
    if(temp >= 0) {
        temp = temp % 26;
        return temp;
    }
    else {
        while(temp < 0) {
            temp = (26 + temp) % 26;
        }
        return temp;
    }
}

int main() {
    str cmd = "";
    while(true) {
        cout << "Type E for deciphering, type D for deciphering (Case insensitive). Type / to exit the program: ";
        std::getline(cin >> std::ws, cmd);
        bool bck = true;
        if(cmd == "e" || cmd == "E") {
            while(true) {
                if(bck) { //Start
                    cout << "Your input: ";
                    std::getline(cin >> std::ws, chr);
                    while(true) {
                        cout << "Shift (type / to cancel): ";
                        std::getline(cin >> std::ws, shf);
                        if(shf == "/") {
                            bck = false;
                            break;
                        }
                        else if(isDigit(shf)) {
                            int temp = stoi(shf);
                            cout << "Output: " << Encipher(alp, sort(algorithm(temp), alp), alpcap, sortcap(algorithm(temp), alpcap), chr) << '\n';
                        }
                        else {
                            cout << "Invalid input. \n";
                        }
                    }
                    continue;
                } //End
                break;
            }
        }
        else if(cmd == "d" || cmd == "D") {
            while(true) {
                if(bck) { //Start
                    cout << "Your input: ";
                    std::getline(cin >> std::ws, chr);
                    while(true) {   
                        cout << "Shift (type / to cancel): ";
                        std::getline(cin >> std::ws, shf);
                        if(shf == "/") {
                            bck = false;
                            break;
                        }
                        else if(isDigit(shf)) {
                            int temp = stoi(shf);
                            cout << "Output: " << Decipher(alp, sort(algorithm(temp), alp), alpcap, sortcap(algorithm(temp), alpcap), chr) << '\n';
                        }
                        else {
                            cout << "Invalid input. \n";
                        }
                    }
                    continue;
                } //End
                break;
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
