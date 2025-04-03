#include <iostream>
using namespace std;

int main()
{
    int a[5];
    int i = 0;

    for (int i = 0; i < 5; i++)
    {
        cout << "Enter element " << i << ": ";
        cin >> a[i];
    }

    cout << "\nEntered list of arrays is: ";

    /*for (int i = 0; i < 5; i++)
    {
        cout << a[i];
    }*/

    /*while (i < 5)
    {
        cout << a[i];
        i += 1;
    }*/

   /*do {
    cout << a[i];
    i += 1;
   } while (i < 5);*/
   int *p = a;

   cout << "\nValue at a[0] is " << *p << endl;
   cout << "Value at a[1] is " << *(p + 1) << endl;
   cout << "Value at a[3] is " << *(p + 2) << endl;

    return 0;
}