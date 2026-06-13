#include <iostream>
using namespace std;

template <class T>
class Matrix
{
    T a[2][2];

    public:

    Matrix()
    {
    }

    void input()
    {
        for(int i = 0; i < 2; i++)
        {
            for(int j = 0; j < 2; j++)
            {
                cin >> a[i][j];
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

    void determinant()
    {
        T det;

        det = (a[0][0] * a[1][1])
            - (a[0][1] * a[1][0]);

        cout << "Determinant = "
             << det << endl;
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
    Matrix<int> m1, m2, m3;

    cout << "Enter elements of Matrix 1:\n";
    m1.input();

    cout << "Enter elements of Matrix 2:\n";
    m2.input();

    cout << "\nMatrix 1:\n";
    m1.display();

    cout << "\nMatrix 2:\n";
    m2.display();

    m3 = m1 + m2;

    cout << "\nAddition of matrices:\n";
    m3.display();

    m3 = m1 - m2;

    cout << "\nSubtraction of matrices:\n";
    m3.display();

    cout << "\nDeterminant of Matrix 1:\n";
    m1.determinant();

    cout << "\nDeterminant of Matrix 2:\n";
    m2.determinant();

    return 0;
}

