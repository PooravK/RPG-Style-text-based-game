#include <iostream>
using namespace std;

class employee{
    int id;
    static int count;
    //COUNT IS THE STATIC DATA MEMBER OF THE CLASS EMPLOYEE

    public:
        void setData(void){
            cout << "Enter the ID of employee: " << endl;
            cin>>id;
            count++;
        }
        void getData(void)
        {
            cout << "The ID of the employee is: " << id << " and his number is: " << count << endl;;
        }

        static void getCount(void){
            cout << "The value of count is " << count << endl;
        }
};

int employee :: count;

int main()
{
    employee poorav, aarush, aayush;
    //poorav.id = 1;
    //poorav.count = 1;
    //CANNOT DO THIS AS ID AND COUNT ARE PRIVATE MEMBERS!!

    poorav.setData();
    poorav.getData();
    employee :: getCount();

    aarush.setData();
    aarush.getData();
    employee :: getCount();

    aayush.setData();
    aayush.getData();
    employee :: getCount();
    return 0;
}