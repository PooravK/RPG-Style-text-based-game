#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    // Complete the code.
    int a, b;
    const char *num[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};
    cin >> a >> b;
    
    for (int i = a; i <= b; i++)
    {
        if (i >= 1 && i <= 9)
        {
            cout << num[i-1] << "\n";
        }
        else {
            if (i % 2 == 0)
            {
                cout << "even\n";
            }
            else {
                cout << "odd\n";
            }
        }
    }
    return 0;
}