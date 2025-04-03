#include <iostream>
using namespace std;

int lalala(int num1, int num2)
{
    if (num1 == 30 || num2 == 30 || (num1 + num2) == 30)
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
    int a, b;
    cin >> a >> b;

    cout << lalala(a, b);
}