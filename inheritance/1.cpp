#include<iostream>
using namespace std;

class employee{

    int id;
    string name;
    static int count;

    public:

    employee(string n)
    {
        id=count+1;
        count++;
        name=n;
    }

    void display()
    {
        cout<<"NAME:"<<name<<endl;
        cout<<"ID:"<<id<<endl;
    }
};

int employee:: count=0;

class programmer: employee
{

    public:
    int languagecode=9;
};

int main()
{
    employee e("harry");

}