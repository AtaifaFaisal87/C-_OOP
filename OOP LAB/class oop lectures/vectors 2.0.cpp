#include <iostream>
using namespace std;

// Class to represent a point in 2D space
class Point
{
private:
    double x;
    double y;

public:
    void set(double a, double b)
    {
        x = a;
        y = b;
    }

    double getX() { return x; }
    double getY() { return y; }

    void offset(double dx, double dy)
    {
        x += dx;
        y += dy;
    }

    void display()
    {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

// Class to represent a vector using two points
class Vector
{
private:
    Point start;
    Point end;

public:
    void setStart(double x, double y)
    {
        start.set(x, y);
    }

    void setEnd(double x, double y)
    {
        end.set(x, y);
    }

    double getStartX() { return start.getX(); }
    double getStartY() { return start.getY(); }
    double getEndX()   { return end.getX(); }
    double getEndY()   { return end.getY(); }

    void offset(double dx, double dy)
    {
        start.offset(dx, dy);
        end.offset(dx, dy);
    }

    void print()
    {
        cout << "Start: ";
        start.display();
        cout << "End: ";
        end.display();
    }
};

int main()
{
    Vector v1;
    v1.setStart(0.2, 0.4);
    v1.setEnd(0.7, 0.7);

    cout << "Vector v1:" << endl;
    v1.print();

    Vector v2;
    v2.setStart(v1.getStartX(), v1.getStartY());
    v2.setEnd(v1.getEndX(), v1.getEndY());

    cout << "Vector v2:" << endl;
    v2.print();

    v2.offset(0.5, 0.5);
    cout << "Vector v2 after offset:" << endl;
    v2.print();

    return 0;
}

