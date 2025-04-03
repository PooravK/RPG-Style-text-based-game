#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str1, str2;
    cout << "Enter a string: ";
    getline(cin, str1);

    str2.resize(str1.length());

    for (int i = 0; i < str1.length(); i++)
    {
        str2[i] = str1[str1.length() - i - 1];
    }
    cout << "Reversed string is: ";
    cout << str2;
    return 0;
}