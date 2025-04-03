#include <iostream>
using namespace std;

int main()
{
    const char *num[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};
    int n;
    cin >> n;

    if (n >= 1 && n <= 9)
    {
        cout << num[n-1];
    }
    else
    {
        cout << "Greather than 9";
    }
    return 0;
}