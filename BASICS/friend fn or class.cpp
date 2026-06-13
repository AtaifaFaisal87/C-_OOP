#include <iostream>
using namespace std;

class Y;

class X
{
    int data;
    friend void add(X,Y);

public:
    void setvalue(int value)
    {

        data = value;
    }
};

class Y
{
    int data;
    friend void add(X,Y);

public:
    void setvalue(int value)
    {

        data = value;
    }
};

void add(X o1,Y o2)
{
   cout<<"summing datas of x and y gives me="<<o1.data+o2.data;
}

int main()
{

    X a;
    a.setvalue(2);

    Y b;
    b.setvalue(3);

    add(a,b);

    return 0;
}