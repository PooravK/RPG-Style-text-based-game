#include <iostream>
using namespace std;

class shop
{
    int itemID[100];
    int itemPrice[100];
    int counter;

public:
    void initCounter(void)
    {
        counter = 0;
    }
    void getItem(void);
    void setItem(void);
};

void shop ::getItem(void)
{
    cout << "Enter the ID of the item: " << endl;
    cin >> itemID[counter];
    cout << "Enter the price of the given product: " << endl;
    cin >> itemPrice[counter];

    counter++;
}

void shop ::setItem(void)
{
    for (int i = 0; i < counter; i++)
    {
        cout << "The item number " << itemID[i] << " has the price: " << itemPrice[i] << endl;
        ;
    }
}

int main()
{
    shop dukaan;
    dukaan.initCounter();
    dukaan.getItem();
    dukaan.getItem();
    dukaan.getItem();
    dukaan.setItem();

    return 0;
}