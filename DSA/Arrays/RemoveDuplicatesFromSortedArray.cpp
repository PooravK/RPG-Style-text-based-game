#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    cout << "Enter a sorted array: " << endl;
    for (int i = 0; i<n; i++)
    {
        cin >> arr[i];
    }

    int index = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] != arr[index-1])
        {
            arr[index] = arr[i];
            index++;
        }
    }
    for (int i = 0; i < index; i++)
    {
        cout << arr[i];
    }
    return 0;
}