#include <iostream>
using namespace std;

int absolute(int num)
{
    if (num <= 51)
    {
        return abs(num - 51);
    }
    else
    {
        return (3  * abs(num - 51));
    }
}

int main()
{
    int n;
    cin >> n;

    cout << absolute(n);
}