#include <iostream>
#include <string.h>
using namespace std;

class Teacher
{
public:
    Teacher()
    {
        cout << "Teacher Created\n";
    }

    ~Teacher()
    {
        cout << "Teacher Destroyed\n";
    }

    void teach()
    {
        cout << "Teaching...\n";
    }
};

class Student
{
    Teacher *t; // Association (just storing address)

public:
    Student(Teacher *temp)
    {
        t = temp;
        cout << "Student Created\n";
    }

    ~Student()
    {
        cout << "Student Destroyed\n";
    }

    void study()
    {
        t->teach();
    }
};

int main()
{
    Teacher t1;
    Student s1(&t1);

    s1.study();
}
