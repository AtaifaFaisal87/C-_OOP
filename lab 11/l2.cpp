#include <iostream>
using namespace std;

// ======================================================
// BASE CLASS
// ======================================================
class Person
{
protected:
    string name;

public:
    // Constructor of Person
    Person(string n)
    {
        name = n;
    }

    // Virtual function so child class can override it
    virtual void introduce()
    {
        cout << "Name: " << name << endl;
    }
};

// ======================================================
// STUDENT CLASS
// ======================================================

// CHANGE:
// virtual inheritance is used
// so TeachingAssistant gets ONLY ONE copy of Person

class Student : virtual public Person
{
protected:
    int studentID;

public:
    Student(string n, int sid) : Person(n)
    {
        studentID = sid;
    }
};

// ======================================================
// TEACHER CLASS
// ======================================================

// CHANGE:
// virtual inheritance again prevents
// duplicate Person sub-objects

class Teacher : virtual public Person
{
protected:
    int employeeID;

public:
    Teacher(string n, int eid) : Person(n)
    {
        employeeID = eid;
    }
};

// ======================================================
// TEACHING ASSISTANT CLASS
// ======================================================

// TeachingAssistant inherits from BOTH
// Student and Teacher

class TeachingAssistant : public Student, public Teacher
{
public:
    // CHANGE:
    // Since Person is a virtual base class,
    // ONLY the most derived class
    // (TeachingAssistant) initializes Person

    TeachingAssistant(string n, int sid, int eid)
        : Person(n), Student(n, sid), Teacher(n, eid)
    {
    }

    // CHANGE:
    // introduce() is overridden
    // to display all information

    void introduce() override
    {
        cout << "===== Teaching Assistant Details =====" << endl;

        cout << "Name: " << name << endl;
        cout << "Student ID: " << studentID << endl;
        cout << "Employee ID: " << employeeID << endl;
    }
};

// ======================================================
// MAIN FUNCTION
// ======================================================

int main()
{
    // Creating TeachingAssistant object
    TeachingAssistant ta("Ataifa", 101, 5001);

    // Calling overridden function
    ta.introduce();

    return 0;
}