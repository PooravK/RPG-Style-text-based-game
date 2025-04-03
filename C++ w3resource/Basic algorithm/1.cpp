#include <iostream>
using namespace std;

int sum(int a, int b)
{
    if (a == b)
    {
        return (3 * (a + b));
    }
    else
    {
        return (a + b);
    }
}

int main()
{
    int num1, num2;
    cin >> num1 >> num2;

    cout << sum(num1, num2);
}