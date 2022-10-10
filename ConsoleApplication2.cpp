
#include <iostream>
#include <vector>

using namespace std;
int main()
{
    int k = 0;
    string a = "";
    cin >> a;
    vector<char>symbols = {'@','#', '$', '_', '%','^','&','*','!','?','=','-','+'};
    for (int i = 0; i < symbols.size(); i++) {
        for (int j = 0; j < a.length(); j++) {
            if (a[j] == symbols[i]) {
                k++;
            }
        }
    }
    if (k != 1||a.length()!= 16) {
        cout << "Try again";
    }

}
