#include <iostream>
using namespace std;

int lalala(int n)
{
    if (n <= 210 && n >= 190)
    {
        return 1;
    }
    else if (n <= 110 && n >= 90)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int num;
    cin >> num;
    cout << lalala(num);
}