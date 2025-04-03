#include <iostream>
using namespace std;

int fibb(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    else{
        return (fibb(n-1) + fibb(n-2));
    }
}

int main()
{
    int term;
    cout << "Upto what term do you want to find the fibbonachi series? ";
    cin >> term;
    int fibo;

    cout << "The series is as follows: ";
    for (int i = 0; i < term; i++)
    {
        fibo = fibb(i);
        cout << fibo << " ";
    }
    return 0;
}