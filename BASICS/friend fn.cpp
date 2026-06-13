#include <iostream>
using namespace std;

class complex
{

    int real;
    int img;

public:

//friend function and can use the privt members of class

    friend complex sum(complex o1, complex o2);
    
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

complex sum(complex o1, complex o2)
{
    complex o3  ((o1.real + o2.real), (o1.img + o2.img));

    return o3;
}

int main()
{
    complex c1(2, 3);
    c1.display();

    complex c2(4, 8);
    c2.display();

    complex res;

    res = sum(c1, c2);
    res.display();

    return 0;
}