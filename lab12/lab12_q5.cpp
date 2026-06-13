#include <iostream>
using namespace std;

class Complex_No
{
    int real, imag;

    public:

    Complex_No(int r = 0, int i = 0)
    {
        real = r;
        imag = i;
    }

    void input()
    {
        cout<<"Enter real part: ";
        cin >> real;
        cout<<"Enter imaginary part: ";
        cin >> imag;
    }

    Complex_No operator +(Complex_No c)
    {
        return Complex_No(real + c.real,
                          imag + c.imag);
    }

    Complex_No operator -(Complex_No c)
    {
        return Complex_No(real - c.real,
                          imag - c.imag);
    }

    friend ostream& operator <<(ostream& out,
                                Complex_No c)
    {
        if (c.imag<0)
        {
            out << c.real
                << "-" << -c.imag << "i";    
        }
        else
        {
         out << c.real
             << "+" << c.imag << "i";   
        }
        return out;
    }
};

template <class T>
class Matrix
{
    T a[2][2];

    public:

    void input()
    {
        for(int i = 0; i < 2; i++)
        {
            for(int j = 0; j < 2; j++)
            {
                a[i][j].input();
            }
        }
    }

    void display()
    {
        for(int i = 0; i < 2; i++)
        {
            for(int j = 0; j < 2; j++)
            {
                cout << a[i][j] << " ";
            }

            cout << endl;
        }
    }

    Matrix operator +(Matrix m)
    {
        Matrix temp;

        for(int i = 0; i < 2; i++)
        {
            for(int j = 0; j < 2; j++)
            {
                temp.a[i][j]
                = a[i][j] + m.a[i][j];
            }
        }

        return temp;
    }

    Matrix operator -(Matrix m)
    {
        Matrix temp;

        for(int i = 0; i < 2; i++)
        {
            for(int j = 0; j < 2; j++)
            {
                temp.a[i][j]
                = a[i][j] - m.a[i][j];
            }
        }

        return temp;
    }
};

int main()
{
    Matrix<Complex_No> m1, m2, sum, diff;

    cout << "Enter Matrix 1:\n";
    m1.input();

    cout << "Enter Matrix 2:\n";
    m2.input();

    sum = m1 + m2;
    diff = m1 - m2;

    cout << "\nAddition:\n";
    sum.display();

    cout << "\nSubtraction:\n";
    diff.display();

    return 0;
}