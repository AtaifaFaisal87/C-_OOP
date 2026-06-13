#include <iostream>
using namespace std;

class intarray
{

    int size;
    int *arr;

public:

    intarray(int s);
    intarray(const intarray &x);
    int sum();
    void display();

    ~intarray()
    {
        delete[] arr;
    }
};

    intarray::intarray(int s)
    {
        size = s;

        arr = new int[size];

        cout << "ENTER " << size << " ELEMENTS" << endl;

        for (int i = 0; i < size; i++)
        {

            cout << "ENTER ELEMENT " << i + 1 << ":";
            cin >> arr[i];
        }
    }

intarray::intarray(const intarray &x)
{
    size = x.size;
    arr = new int[size];

    for (int i = 0; i < size; i++)
    {
        arr[i] = x.arr[i];
    }
}
int intarray::sum()
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }

    return sum;
}

void intarray::display()
{
    for (int i = 0; i < size; i++)
    {
        cout << "arr[" << i << "]=" << arr[i] << endl;
    }
}
int main()
{

    intarray a1(3);
    a1.display();
    int res;

    res = a1.sum();

    cout << "THE SUM OF ARRAY IS=" << res;
}