#include <iostream>
using namespace std;

// BASE-CLASS
class person
{
private:
    string name;
    string CNIC;

protected:
    int age;

public:
    // DEFAULT CONSTRUCTOR
    person()
    {
        name = "UNKNOWN";
        CNIC = "N/A";
        age = 0;
    }
    // PARAMETERIZED CONSTRUCTOR
    person(const string n, const string cnic, int a)
    {
        name = n;
        CNIC = cnic;
        age = a;
    }

    void input()
    {
        int a;
        cout << "ENTER NAME:";
        getline(cin, name);
        cout << "ENTER CNIC:";
        getline(cin, CNIC);

        do
        {
            cout << "ENTER AGE(0-150):";
            cin >> a;
        } while (a <= 0 || a >= 150);
        age = a;

        cin.ignore();
    }

    void display() const
    {
        cout << "NAME:" << name << endl
             << "CNIC:" << CNIC << endl
             << "AGE:" << age << endl;
    }
};

// DERIVED-CLASS
class student : public person
{
private:
    string regno;
    double gpa;

public:
    // DEFAULT CONSTRUCTOR
    student() : person()
    {
        regno = "N/A";
        gpa = 0.0;
    }
    // PARAMETERIZED CONSTRUCTOR
    student(const string n, const string c, int a, const string r, double g) : person(n, c, a)
    {
        regno = r;
        gpa = g;
    }
    // METHOD OVERIDING SAME FUNCTION NAME SAME PARAMTER
    // METHOD OVERLOADING SAME FN NAME DIFFERENT PARAMETERS
    void input()
    {
        // CALLING THE FUNCTION FROM BASE CLASS
        person::input();

        double g;

        cout << "ENTER REGNO. :";
        getline(cin, regno);

        do
        {
            cout << "ENTER GPA (0.0-4.0):";
            cin >> g;
        } while (g <= 0.0 || g >= 4.0);
        gpa = g;
        // CLEARING BUFFER
        cin.ignore();
    }

    void display() const
    {
        cout << "---STUDENT-INFO---" << endl;
        person::display();

        cout << "REG.NO:" << regno << endl
             << "GPA:" << gpa << endl
             << "---------------" << endl;
    }
};

int main()
{

    student cis[5];

    cout << "=====INPUT INFO OF STUDENTS OF CIS=====" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "INPUT INFO OF STUDENTS NO:" << i + 1 << endl;
        cis[i].input();
    }

    cout << "====== STUDENTS OF CIS ======" << endl;
    for (int i = 0; i < 5; i++)
    {
        cis[i].display();
    }

    return 0;
}