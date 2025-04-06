#include <iostream>
using namespace std;

class employee{
    int id;
    int salary;
    public:
        void setID(void)
        {
            salary = 122;
            cout << "Enter ID" << endl;
            cin >> id;
        }
        void getID(void)
        {
            cout << "The id is: " << id << endl;
        }

};

int main()
{
    employee company[10];
    
    for (int i = 0; i < 10; i++)
    {
        company[i].setID();
        company[i].getID();
        cout << "\n";
    }
    return 0;
}