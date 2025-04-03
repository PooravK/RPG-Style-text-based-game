#include <iostream>
using namespace std;

void swap( int *x, int *y)
{
    *x = *x + *y;
    *y = *x - *y;
    *x = *x - *y;
}

int main()
{
    int a, b;
    cout << "Enter value for a and b: ";
    cin >> a >> b;

    swap (&a, &b);

    cout << "Swapped a = " << a << " and swapped b = " << b << endl;
    return 0;
}