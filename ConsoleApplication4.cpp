#include <iostream>
#include <ctime>
#include <fstream>

using namespace std;

int main() {
    srand(time(0));

    string str = "1234567890qwertyuioplkjhgfdsazxcvbnmQWERTYUIOPLKJHGFDSAZXCVBNM";
    string pass = "";
    string symbols = "#$@!?*&^%=+";
    for (int i = 0; i < 17; i++) {
        pass += str[rand() % 62];
    }
    pass[rand() % 17] = symbols[rand() % 11];
    ofstream save;
    save.open("./password.txt");
    save << pass;
    save.close();
}