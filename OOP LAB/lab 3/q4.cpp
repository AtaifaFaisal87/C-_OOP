#include <iostream>
using namespace std;

class myclass
{
    int data[2];

public:
    int *p;

public:
    myclass()
    {
        p = data;
    }
};

int main()
{
    myclass *cp;
    cp = new myclass[3];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << "Enter value for object " << i << ", element " << j << ": ";
            cin >> (cp + i)->p[j];
        }
    }

    for (int i = 0; i < 3; i++)
    {
        cout << "Data of object " << i << ": ";
        for (int j = 0; j < 2; j++)
        {
            cout << (cp + i)->p[j] << " ";
        }
        cout << endl;
    }

    delete[] cp;

    return 0;
}
