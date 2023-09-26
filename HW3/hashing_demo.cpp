#include <functional>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    hash<int> h;
    for (int i = 0; i < 15; i++)
    {
        cout << "Key: " << i << " - "
             << "Hash value: " << h(i) << endl;
    }

    cout << endl;

    hash<string> hs;
    for (int i = 0; i < 15; i++)
    {
        cout << "Key: " << i << " - "
             << "Hash value: " << hs(to_string(i)) << endl;
    }

    return 0;
}