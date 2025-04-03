#include <iostream>
using namespace std;

int main()
{
    string s1;
    cout << "Enter a string: ";
    getline(cin, s1);

    if (s1[0] == 'i' && s1[1] == 'f')
    {
        cout << s1;
    }
    else
    {
        cout << "if " << s1;
    }
    return 0;
}