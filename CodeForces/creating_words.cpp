#include <iostream>
#include <string>
using namespace std;

void swapFirstCharacter(string &a, string &b) {
    char temp = a[0];
    a[0] = b[0];
    b[0] = temp;
}

int main() {
    int t;
    cin >> t; 
    while (t--) {
        string a, b;
        cin >> a >> b; 
        swapFirstCharacter(a, b);
        cout << a << " " << b << endl;
    }
    return 0;
}
