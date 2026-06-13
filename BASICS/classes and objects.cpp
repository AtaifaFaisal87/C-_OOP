#include<iostream>
using namespace std;

class Employee{
public:                       // allows the user to make chnages to the attributes and call the functions

//attributes
    string name;
    string company;
    int age;

//function
    void introduction(){
        cout<<"NAME="<< name<<"\n";
        cout<<"AGE="<< age<<"\n";
        cout<<"COMPANY="<< company<<"\n";
    }
//costructor
Employee(string name,string company,int age)
{
    name=name;
    company=company;
    age=age;
}

};

int main()
{
    int number;
    Employee employee1=Employee("ATAIFA","Microsoft",23);
    // employee1.name="ATAIFA";
    // employee1.age=23;
    // employee1.company="Microsoft";
    employee1.introduction();


    return 0;
}