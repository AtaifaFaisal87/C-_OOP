#include <iostream>
#include <cmath>
using namespace std;

class Complex_No
{
private:
    int real;
    int imag;

public:
    // CONSTRUCTORS
    Complex_No();
    Complex_No(int r, int i);
    Complex_No(const Complex_No &c);  

    void SetReal(int r) { real = r; }
    void SetImag(int i) { imag = i; }

    int GetReal() { return real; }
    int GetImag() { return imag; }

    void Display();
    double Magnitude();
    Complex_No Add(Complex_No c);
};

// DEFAULT CONSTRUCTOR
Complex_No::Complex_No()
{
    real = 0;
    imag = 0;
}

// PARAMETERIZED CONSTRUCTOR
Complex_No::Complex_No(int r, int i)
{
    real = r;
    imag = i;
}

// COPY CONSTRUCTOR (FIXED)
Complex_No::Complex_No(const Complex_No &c)
{
    real = c.real;
    imag = c.imag;
}

// DISPLAY FUNCTION
void Complex_No::Display()
{
    cout << real << " + " << imag << "i" << endl;
}

// MAGNITUDE FUNCTION
double Complex_No::Magnitude()
{
    return sqrt(real * real + imag * imag);
}

// ADD FUNCTION
Complex_No Complex_No::Add(Complex_No c)
{
    Complex_No result;
    result.SetReal(real + c.GetReal());
    result.SetImag(imag + c.GetImag());
    return result;
}

int main()
{
    Complex_No c1(3, 4);
    Complex_No c2;

    c2.SetReal(1);
    c2.SetImag(2);

    Complex_No sum = c1.Add(c2);

    cout << "FIRST COMPLEX NUMBER: ";
    c1.Display();

    cout << "SECOND COMPLEX NUMBER: ";
    c2.Display();

    cout << "SUM: ";
    sum.Display();

    cout << "MAGNITUDE OF FIRST: " << c1.Magnitude();

    return 0;
}
