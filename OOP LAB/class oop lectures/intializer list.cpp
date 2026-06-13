#include <iostream>
using namespace std;

class check
{

    int b;
    int a;

public:
    // check(int i, int j) : a(i), b(j) {}
    // check(int i, int j) : a(i), b(j+i) {}
    // check(int i, int j) : a(i), b(j+a) {}
    // check(int i, int j) : b(j+i),a(i) {}

    check(int i, int j) : a(i), b(j + i) {}

    void display()
    {
        cout << a << "," << b;
    }
};

int main()
{

    check c1(2, 3);
    c1.display();
}