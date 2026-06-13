#include <iostream>
#include<string.h>
using namespace std;
class A
{
private:
    int x;
    char *title;

public:
    A(const char*t)
    {
        title=new char[strlen(t)+1];
        strcpy(title,t);
        cout << "ENTER THE VALUE OF X:";
        cin >> x;
    }

    void display( )
    {
        cout<<"value of x is:"<<x<<endl
        <<"the title is:"<<title<<endl;
    }

    ~A( )
    { 
        delete[ ] title;
        cout<<"DESTRPYED!"<<endl;
    }
};

int main()
{
    A a1("kiki");  //CONSTRUCTOR INVOKED AUTOMATICALLY
    a1.display();
    return 0;
}