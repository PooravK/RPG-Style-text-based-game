#include <iostream>
using namespace std;

int main()
{
    int pos, siz;
    string str1;

    cout << "Enter a string: " << endl;
    getline(cin, str1);
    cout << "Which position do you want to get rid of? " << endl;
    cin >> pos;

    siz = str1.length();

    for (int i = 0; i < siz; i++)
    {
        if (i == pos)
        {
            str1.erase(i, 1);
            break;
        }
        else
        {
            continue;
        }
    }

    cout << "New string is: " << endl;
    cout << str1;
    return 0;

}