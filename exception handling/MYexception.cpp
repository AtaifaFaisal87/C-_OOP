#include <iostream>
using namespace std;

class Myexception
{
    string msg;
    int value;

public:
    Myexception(string m, int v) : msg(m), value(v) { };

    string what() const
    {
        return msg;
    }

    int getvalue( ) const
    {return value;}
};

int main()
{
    int i;

    cout << "ENTER VALUE OF INTEGER:";
    cin >> i;

    try
    {
        if (i < 0)
        {
            throw Myexception("NOT POSITIVE", i);
        }

        if (i == 0)
        {
            throw Myexception("ZERO NOT ALLOWED", i);
        }

        if (i > 100)
        {
            throw Myexception("VALUE TOO LARGE", i);
        }

        cout<<"VALID VALUE:"<<i;
    }

    catch(const Myexception&e)
    {
        cout<<e.what()<<endl;

        if(e.getvalue() != 0)
        {
            cout<<"THE VALUE IS:"<<e.getvalue()<<endl;
        }
    }

    catch(...)
    {
        cout<<"UNEXPECTED EXCEPTION"<<endl;
    }
}