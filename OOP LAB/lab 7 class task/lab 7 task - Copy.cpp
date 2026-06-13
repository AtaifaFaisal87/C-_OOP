#include <iostream>
using namespace std;

#define PI 3.1416

// ABSTRACT CLASS
class Shape
{
protected:
    float Area;

public:
    Shape()
    {
        Area = 0;
    }

    void setArea(float a) { Area = a; }
    float getArea() { return Area; }

    // PURE VIRTUAL FUNCTION
    virtual void Calculate_Area() = 0;
    // VIRTUAL DISPLAY
    virtual void Display()
    {
        cout << "AREA: " << Area << endl;
    }
};

class Circle : public Shape
{
private:
    float radius;

public:
    // CONSTRUCTOR
    Circle(float r)
    {
        radius = r;
    }

    void setRadius(float r) { radius = r; }
    float getRadius() { return radius; }

    // OVERRIDING
    void Calculate_Area() override
    {
        setArea(PI * radius * radius);
    }

    void Display() override
    {
        cout << "=======CIRCLE=======" << endl;
        cout << "CIRCLE RADIUS: " << getRadius() << endl;
        cout << "AREA OF CIRCLE: " << getArea() << endl;
    }
};

class Triangle : public Shape
{
private:
    float base, height;

public:
    Triangle(float b, float h)
    {
        base = b;
        height = h;
    }

    void setbase(float b) { base = b; }
    void setheight(float h) { height = h; }

    float getbase() { return base; }
    float getheight() { return height; }

    // OVERRIDING
    void Calculate_Area() override
    {
        setArea(0.5 * base * height);
    }

    void Display() override
    {
        cout << "=======TRIANGLE=======" << endl;
        cout << "HEIGHT: " << getheight() << endl;
        cout << "BASE: " << getbase() << endl;
        cout << "AREA OF TRIANGLE: " << getArea() << endl;
    }
};

class Rectangle : public Shape
{
private:
    float length, breadth;

public:
    Rectangle(float l, float b)
    {
        length = l;
        breadth = b;
    }

    void setbreadth(float b) { breadth = b; }
    void setlength(float l) { length = l; }

    float getbreadth() { return breadth; }
    float getlength() { return length; }

    // OVERRIDING
    void Calculate_Area() override { setArea(length * breadth); }

    void Display() override
    {
        cout << "=======RECTANGLE=======" << endl;
        cout << "LENGTH: " << getlength() << endl;
        cout << "BREADTH: " << getbreadth() << endl;
        cout << "AREA OF RECTANGLE: " << getArea() << endl;
    }
};

int main()
{

    Circle c(5);
    Rectangle r(4, 6);
    Triangle t(6, 7);

    Shape *shape[3] = {&c, &r, &t};

    for (int i = 0; i < 3; i++)
    {
        shape[i]->Calculate_Area();
        shape[i]->Display();
        cout << "-----------------------" << endl;
        ;
    }

    Shape *max = shape[0];

    for (int i = 0; i < 3; i++)
    {
        if (shape[i]->getArea() > max->getArea())
        {
            max = shape[i];
        }
    }
    cout << "THE SHAPE WITH MAXIMUM AREA IS=>" << endl;
    max->Display();
}