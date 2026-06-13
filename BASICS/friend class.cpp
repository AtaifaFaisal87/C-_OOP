#include <iostream>
using namespace std;

// forward decleration
class complex;

class calculator
{

public:
    int addcomplex(complex o1, complex o2);
};

class complex
{

    int real;
    int img;

    //for one function
    // friend int calculator::addcomplex(complex o1, complex o2);
    
    //for multiple fn
    friend class calculator;

public:
    complex(int r = 0, int i = 0)
    {
        real = r;
        img = i;
    }

    void display()
    {

        cout << "THE COMPLEX NO IS=" << real << "+" << img << "i" << endl;
    }
};

int calculator::addcomplex(complex o1, complex o2)
{

    return (o1.real + o2.real);
}

int main()
{
    complex c1(2, 3);
    complex c2(4, 3);

    calculator res;
    cout << res.addcomplex(c1, c2);

    return 0;
}