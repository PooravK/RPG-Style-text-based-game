#include <iostream>
using namespace std;

class complex;

class calculator{
    public:
        int add(int a, int b)
        {
            return (a + b);
        }
        int sumComplex(complex o1, complex o2);

};

class complex{
    int a, b;
    friend int calculator::sumComplex(complex, complex);
    public:
        void setNumber(int n1, int n2)
        {
            a = n1;
            b = n2;
        }
        void printNumber()
        {
            cout << "Your number is: " << a << " + " << b << "*i" << endl;
        }
};

int calculator :: sumComplex(complex o1, complex o2){
    return (o1.a + o2.a);
}

int main()
{
    return 0;
}