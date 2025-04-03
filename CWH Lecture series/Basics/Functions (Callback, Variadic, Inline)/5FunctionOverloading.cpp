#include <iostream>
using namespace std;

int volume (double r, double h)
{
    return (3.14 * r * r * h);
}
int volume (int a)
{
    return a * a * a;
}
int volume (int l, int b, int h)
{
    return l * b * h;
}

int main()
{
    cout << "Volume of sphere = " << volume(5, 5) << endl;
    cout << "Volume of cube = " << volume(5) << endl;
    cout << "Volume of cuboid = " << volume (5, 6, 7) << endl;

    return 0;
}