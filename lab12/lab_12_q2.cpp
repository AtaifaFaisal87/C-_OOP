#include <iostream>
using namespace std;

template <class T>
T Power(T x, int y)
{
    T result = 1;

    for(int i = 0; i < y; i++)
    {
        result = result * x;
    }

    return result;
}

int main()
{
    cout <<"2 raised to the 3 equals: "<<Power(2, 3) << endl;
    cout <<"2.5 raised to the 2 equals: "<<Power(2.5, 2);
    return 0;
}