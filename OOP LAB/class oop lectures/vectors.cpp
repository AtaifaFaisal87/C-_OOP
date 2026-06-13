#include <iostream>
using namespace std;

class point
{
public:
    double x;
    double y;

    void offset(double dx, double dy)
    {
        x += dx;
        y += dy;
    }

    void display()
    {
        cout << "(" << x << "," << y << ")" << endl;
    }
};

class vector
{
public:
    point start;
    point end;

    void offset(double dx, double dy)
    {
        start.offset(dx, dy);
        end.offset(dx, dy);
    }

    void print()
    {
        start.display();
        end.display();
    }
};

int main()
{
    vector v1;
    v1.start.x = 2;
    v1.start.y = 4;
    v1.end.x = 3;
    v1.end.y = 9;
    v1.print();
    v1.offset(3, 4);
    v1.print();

    return 0;
}