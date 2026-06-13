#include <iostream>
using namespace std;

class printer
{
public:
    virtual void print()
    {
        cout << "Printing using normal printer" << endl;
    }
};

class inkjet : public printer
{
public:
    void print() override
    {
        cout << "Printing using inkjet printer" << endl;
    }
};

class laser : public printer
{
public:
    void print() override
    {
        cout << "Printing using laser printer" << endl;
    }
};

class P_3D : public printer
{
public:
    void print() override
    {
        cout << "Printing using 3D printer" << endl;
    }
};

void demonstrateprint(printer *p)
{
    p->print();
}

int main()
{
    inkjet ink;
    laser l;
    P_3D d;

    cout << "Printing with different printers:" << endl;

    demonstrateprint(&ink);
    demonstrateprint(&l);
    demonstrateprint(&d);
}