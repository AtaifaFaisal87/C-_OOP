#include <iostream>
using namespace std;

class complexno
{

    int real;
    int img;

public:
    complexno(int real, int img)
    {
        this->real = real;
        this->img = img;
    }

    int sum(complexno c)
    {
        real = real + c.real;
        img = img + c.img;
        cout << "AFTER THE SUM THE COMPLEX NUMBER IS=" << real << "+" << img << "i" << endl;
    }

    void display()
    {

        cout << "THE COMPLEX NUMBER IS=" << real << "+" << img << "i" << endl;
    }
};

int main()
{

    complexno c1(8, 2);
    c1.display();
    complexno c2(4, 5);
    c2.display();
    c1.sum(c2);

    return 0;
}