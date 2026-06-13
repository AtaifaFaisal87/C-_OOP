#include <iostream>
using namespace std;

class c2;

class c1
{

    int val1;
    friend void swap(c1 &x, c2 &y);

public:
    void indata(int a)
    {
        val1 = a;
    }

    void display()
    {
        cout << val1 << endl;
    }
};

class c2
{

    int val2;

    friend void swap(c1 &x, c2 &y);

public:
    void indata(int a)
    {
        val2 = a;
    }

    void display()
    {
        cout << val2 << endl;
    }
};

void swap(c1 &x, c2 &y)
{
    int temp = x.val1;
    x.val1 = y.val2;
    y.val2 = temp;
}

int main()
{
    c1 num1;
    num1.indata(2);
    num1.display();

    c2 num2;
    num2.indata(5);
    num2.display();

    swap(num1, num2);

    num1.display();
    num2.display();

    return 0;
}