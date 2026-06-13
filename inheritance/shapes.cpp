#include <iostream>
#include <cmath>
using namespace std;

// input fns maye include  kro and display sahi kro
class shapes
{
    string colour;

protected:
    // validation functions
    int validint(int a, const string &msg)
    {
        do
        {
            cout << msg;
            cin >> a;

        } while (a < 0);

        return a;
    }
    float validfloat(float a, const string &msg)
    {
        do
        {
            cout << msg;
            cin >> a;

        } while (a < 0);

        return a;
    }

public:
    shapes()
    {
        colour = "unknown";
    }

    shapes(string c) : colour(c) {}

    void input()
    {
        cin.ignore();
        cout << "ENTER COLOUR:";
        getline(cin, colour);
    }

    void display() const
    {
        cout << "-----PROPERTIES OF THE SHAPE-----" << endl;
        cout << "COLOUR:" << colour << endl;
    }
};

class rectangle : public shapes
{
    float length;
    float width;
    float area;
    float perimeter;

public:
    rectangle()
    {
        length = 0;
        width = 0;
        area = 0;
        perimeter = 0;
    }

    rectangle(float l, float w)
    {
        length = l;
        width = w;
        cal_area();
        cal_perimeter();
    }

    void input()
    {
        cout << "---INPUT INFO OF RECTANGLE---" << endl;
        shapes::input();
        length = validfloat(length, "ENTER LENGTH:");
        width = validfloat(width, "ENTER WIDTH:");
        cal_area();
        cal_perimeter();
    }

    void display() const
    {
        cout << "---DISPLAYING INFO OF RECTANGLE---" << endl;
        shapes::display();
        cout << "LENGTH:" << length << endl
             << "WIDTH:" << width << endl
             << "AREA:" << area << endl
             << "PERIMETER:" << perimeter << endl;
    }

    void cal_area()
    {
        area = length * width;
    }

    void cal_perimeter()
    {
        perimeter = 2 * (length + width);
    }
};

class triangle : public shapes
{
    float base;
    float height;
    float area;

public:
    triangle()
    {
        base = 0;
        height = 0;
        area = 0;
    }

    triangle(float b, float h)
    {
        base = b;
        height = h;
        cal_area();
    }

    void input()
    {
        cout << "---INPUT INFO OF TRIANGLE---" << endl;
        shapes::input();
        base = validfloat(base, "ENTER BASE:");
        height = validfloat(height, "ENTER HEIGHT:");
        cal_area();
    }

    void display() const
    {
        cout << "---DISPLAYING INFO OF TRIANGLE---" << endl;
        shapes::display();
        cout << "BASE:" << base << endl
             << "HEIGHT:" << height << endl
             << "AREA:" << area << endl;
    }

    void cal_area()
    {
        area = 0.5 * base * height;
    }
};

class cylinder : public shapes
{
    float radius;
    float height;
    float SurfaceArea;
    float volume;

public:
    cylinder()
    {
        radius = 0;
        height = 0;
        SurfaceArea = 0;
        volume = 0;
    }

    cylinder(float r, float h)
    {
        radius = r;
        height = h;
        cal_surfaceArea();
        cal_volume();
    }

    void input()
    {
        cout << "---INPUT INFO OF CYLINDER---" << endl;
        shapes::input();
        radius = validfloat(radius, "ENTER RADIUS");
        height = validfloat(height, "ENTER HEIGHT");
        cal_surfaceArea();
        cal_volume();
    }

    void display() const
    {
        cout << "---DISPLAYING INFO OF CYLINDER---" << endl;
        shapes::display();
        cout << "RADIUS:" << radius << endl
             << "HEIGHT:" << height << endl
             << "SURFACE AREA:" << SurfaceArea << endl
             << "VOLUME:" << volume << endl;
    }

    void cal_volume()
    {
        volume = 3.1416 * radius * radius * height;
    }

    void cal_surfaceArea()
    {
        SurfaceArea = 2 * 3.1416 * radius * (height + radius);
    }
};

class sphere : public shapes
{
    float radius;
    float SurfaceArea;
    float volume;

public:
    sphere()
    {
        radius = 0;
        SurfaceArea = 0;
        volume = 0;
    }

    sphere(float r)
    {
        radius = r;
        cal_surfaceArea();
        cal_volume();
    }

    void input()
    {
        cout << "---INPUT INFO OF SPHERE---" << endl;
        shapes::input();
        radius = validfloat(radius, "ENTER RADIUS:");
        cal_surfaceArea();
        cal_volume();
    }

    void display() const
    {
        cout << "---DISPLAYING INFO OF SPHERE---" << endl;
        shapes::display();
        cout << "RADIUS:" << radius << endl
             << "SURFACE AREA:" << SurfaceArea << endl
             << "VOLUME:" << volume << endl;
    }

    void cal_volume()
    {
        volume = (4.0 / 3.0) * 3.1416 * radius * radius * radius;
    }

    void cal_surfaceArea()
    {
        SurfaceArea = 4 * 3.1416 * radius * radius;
    }
};

class regularPentagon : public shapes
{
    int side;
    float area;
    float perimeter;

public:
    regularPentagon()
    {
        side = 0;
        area = 0;
        perimeter = 0;
    }

    regularPentagon(int s)
    {
        side = s;
        cal_area();
        cal_perimeter();
    }

    void input()
    {
        cout << "---INPUT INFO OF REGULAR PENTAGON---" << endl;
        shapes::input();
        side = validint(side, "ENTER NO OF SIDES:");
        cal_area();
        cal_perimeter();
    }

    void display() const
    {
        cout << "---DISPLAYING INFO OF REGULAR PENTAGON---" << endl;
        shapes::display();
        cout << "NO OF SIDES:" << side << endl
             << "AREA:" << area << endl
             << "PERIMETER:" << perimeter << endl;
    }

    void cal_perimeter()
    {
        perimeter = 5 * side;
    }

    void cal_area()
    {
        area = 0.25 * sqrt(5 * (5 + 2 * sqrt(5))) * side * side;
    }
};

int main()
{
    int choice;

    do
    {
        cout << "\n====== SHAPE MENU ======\n";
        cout << "1. Rectangle\n";
        cout << "2. Triangle\n";
        cout << "3. Cylinder\n";
        cout << "4. Sphere\n";
        cout << "5. Regular Pentagon\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            rectangle r;
            r.input();
            r.display();
            break;
        }

        case 2:
        {
            triangle t;
            t.input();
            t.display();
            break;
        }

        case 3:
        {
            cylinder c;
            c.input();
            c.display();
            break;
        }

        case 4:
        {
            sphere s;
            s.input();
            s.display();
            break;
        }

        case 5:
        {
            regularPentagon p;
            p.input();
            p.display();
            break;
        }

        case 0:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 0);

    return 0;
}