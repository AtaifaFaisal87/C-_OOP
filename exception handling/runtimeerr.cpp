#include <iostream>
using namespace std;

int main()
{
    int a, b, c;

    cout << "ENTER VALUE OF A:";
    cin >> a;
    cout << "ENTER VALUE OF B:";
    cin >> b;

    // if (b == 0)
    // {
    //     cout << "dividion by zero not possible" << endl;
    // }

    // else
    // {
    //     c = a / b;
    //     cout << c;
    // }

    try{
        if(b==0)
        {
            throw "DIVISION BY ZERO NOT POSSIBLE";
        }
        c=a/b;
        cout<<c;
    }
    catch(const char *msg)
    {
        cout<<msg<<endl;
    }
}