#include <iostream>
using namespace std;

struct employee
{
    double ID;
    int salary;
};

int main()
{
    struct employee poorav;
    poorav.ID = 2429040027;
    poorav.salary = 300000;

    cout << "ID = " << poorav.ID << endl;
    cout << "Salary = " << poorav.salary << endl;

    return 0;
}