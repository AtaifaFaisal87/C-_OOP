#include <iostream>
using namespace std;

class complex_number
{
private:
    int real;
    int img;

public:
    // inline setter functions
    void set_real(int r)
    {
        real = r;
    }
    void set_img(int i)
    {
        img = i;
    }

    // inline getter functions
    int get_real()
    {
        return real;
    }

    int get_img()
    {
        return img;
    }

    // out-of-line function
    void display();
};

void complex_number::display()
{
    cout << "Complex Number = " << get_real() << " + " << get_img() << "j" << endl;
}

int main()
{
    complex_number c1;
    int r, i;

    cout << "ENTER REAL PART: ";
    cin >> r;

    cout << "ENTER IMAGINARY PART: ";
    cin >> i;

    c1.set_real(r);
    c1.set_img(i);
    c1.display();

    return 0;
}
