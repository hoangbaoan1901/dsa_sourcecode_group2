#include <functional>
#include <iostream>

using namespace std;

int main() {
    hash<int> h;
    for (int i = 0; i < 100; i ++) {
        cout << "Key: " << i << " - " << "Hash value: " << h(i) << endl;
    }

    hash<string> hs;
    string s = "b";
    cout << "Key: " << s << " - " << "Hash value: " << hs(s) << endl;

    return 0;
}