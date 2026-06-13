#include <iostream>
using namespace std;

template <class T>
class Matrix
{
    T a[2][2];

public:
    void input()
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                cin >> a[i][j];
            }
        }
    }

    void display()
    {
        for (int i = 0; i < 2; i++)
        {
            cout << "[ ";

            for (int j = 0; j < 2; j++)
            {
                cout << a[i][j] << " ";
            }

            cout << "]" << endl;
        }
    }

    void determinant()
    {
        T det;

        det = (a[0][0] * a[1][1]) - (a[0][1] * a[1][0]);

        cout << "Determinant = "
             << det << endl;
    }

    Matrix operator+(Matrix m)
    {
        Matrix temp;

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                temp.a[i][j] = a[i][j] + m.a[i][j];
            }
        }

        return temp;
    }

    Matrix operator-(Matrix m)
    {
        Matrix temp;

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                temp.a[i][j] = a[i][j] - m.a[i][j];
            }
        }

        return temp;
    }
};

int main()
{
    Matrix<float> m1, m2, sum, diff;

    cout << "Enter Matrix 1:\n";
    m1.input();

    cout << "Enter Matrix 2:\n";
    m2.input();

    cout << "\nDeterminant of Matrix 1:\n";
    m1.determinant();

    cout << "\nDeterminant of Matrix 2:\n";
    m2.determinant();

    sum = m1 + m2;
    diff = m1 - m2;

    cout << "\nAddition:\n";
    sum.display();

    cout << "\nSubtraction:\n";
    diff.display();

    return 0;
}