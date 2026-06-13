#include <iostream>
#include <string>
using namespace std;

class Product
{
protected:
    string name;
    int id;

public:
    Product()
    {
        name = "UNKNOWN";
        id = 0;
    }

    void READ()
    {
        cout << "ENTER NAME: ";
        getline(cin, name);
        cout << "ENTER PRODUCT ID: ";
        cin >> id;
        cin.ignore();  // clear newline for next getline
    }

    void SHOWBASE()
    {
        cout << "| NAME       : " << name << endl;
        cout << "| PRODUCT ID : " << id << endl;
    }
};

class UtilityItem : public Product
{
protected:
    float disc;

public:
    UtilityItem()
    {
        disc = 0;
    }

    void READ()
    {
        Product::READ();
        cout << "ENTER DISCOUNT (%): ";
        cin >> disc;
        cin.ignore();
    }

    void SHOW()
    {
        cout << "---------------------------------------------\n";
        cout << "| UTILITY ITEM\n";
        SHOWBASE();
        cout << "| DISCOUNT   : " << disc << "%" << endl;
        cout << "---------------------------------------------\n";
    }
};

class FoodItem : public Product
{
protected:
    string exp;

public:
    FoodItem()
    {
        exp = "UNKNOWN";
    }

    void READ()
    {
        Product::READ();
        cout << "ENTER EXPIRY DATE: ";
        getline(cin, exp);
    }

    void SHOW()
    {
        cout << "---------------------------------------------\n";
        cout << "| FOOD ITEM\n";
        SHOWBASE();
        cout << "| EXPIRY DATE: " << exp << endl;
        cout << "---------------------------------------------\n";
    }
};

int main()
{
    UtilityItem u;
    FoodItem f;

    cout << "ENTER UTILITY ITEM DETAILS:\n";
    u.READ();

    cout << "\nENTER FOOD ITEM DETAILS:\n";
    f.READ();

    cout << "\nDISPLAYING PRODUCT DETAILS:\n";
    u.SHOW();
    f.SHOW();

    return 0;
}
