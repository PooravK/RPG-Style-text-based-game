#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s1, s2;
    cout << "Enter string 1: ";
    getline(cin, s1);
    s2.resize(s1.length());

    for (int i = 0; i < s2.length(); i++)
    {
        s2[i] = s1[i - s2.length() - 1];
    }
    for (int i = 0; i < s1.length(); i++)
    {
        if (s1[i] == s2[i])
        {
            
        }
    }
}