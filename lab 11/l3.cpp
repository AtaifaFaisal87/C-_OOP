#include <iostream>
using namespace std;

// ======================================================
// BASE CLASS
// ======================================================

class Base
{
public:
    int val;

    Base()
    {
        val = 0;
    }
};

// ======================================================
// CLASS A
// ======================================================

// CHANGE:
// virtual inheritance is used
// so only ONE shared copy of Base exists

class A : virtual public Base
{
};

// ======================================================
// CLASS B
// ======================================================

// CHANGE:
// Previously B inherited normally:
// class B : public Base
//
// Now virtual inheritance is added
// to remove duplicate Base objects

class B : virtual public Base
{
};

// ======================================================
// CLASS C
// ======================================================

// C inherits from both A and B

class C : public A, public B
{
};

// ======================================================
// MAIN FUNCTION
// ======================================================

int main()
{
    C obj;

    // No ambiguity now
    // because only ONE Base object exists

    obj.val = 100;

    cout << "Value = " << obj.val << endl;

    return 0;
}