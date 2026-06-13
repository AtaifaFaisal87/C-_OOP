#include<iostream>
using namespace std;

class Teacher{
    string name;
    string subject;
    public:
    Teacher(string n="UNKNOWN",string s="UNKNOWN"):name(n),subject(s) { }
    
    void display( )
    {
        cout<<"|NAME:"<<name<<"|SUBJECT:"<<subject<<"|"<<endl;
    }
};

class Department{
    string deptname;
    Teacher *T;
    public:
    Department(string d,Teacher *t)
    {
      deptname=d;
      T=t;
    }

    void display()
    {
        cout<<"|DEPARTMENT NAME:"<<deptname;
        T->display();
        cout<<endl;
    }
};

int main()
{
    Teacher t1("SARA","PHYSICS");
    Department d2("AP",&t1);
    d2.display();
}