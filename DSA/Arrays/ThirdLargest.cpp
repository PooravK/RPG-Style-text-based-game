#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int n;
    int max1 = INT_MIN;
    int max2 = INT_MIN;
    int max3 = INT_MIN;
    cin >> n;
    int arr[n];
    cout << "Enter an array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i ++)
    {
        if (arr[i] > max1)
        {
            max3 = max2;
            max2 = max1;
            max1 = arr[i];
        }
        else if (arr[i] > max2)
        {
            max3 = max2;
            max2 = arr[i];
        }
        else if (arr[i] > max3)
        {
            max3 = arr[i];
        }
    }
    cout << max3;
    return 0;
}


/*Lets say I wanted to find third largest DISTINT number, then I simply had to add one more line that is
if (arr[i] == max1 || arr[i] == max2 || arr[i] == max3)
{
    continue;
}
*/