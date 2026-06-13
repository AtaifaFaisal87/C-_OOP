#include <iostream>
using namespace std;

class Patient
{
    string name;
    int age;

public:
    Patient() : name("N/R"), age(1) {}
    Patient(string n, int a)
    {
        if (n == "" || a < 0)
        {
            throw logic_error("INVALID!");
        }
        name = n;
        age = a;
    }

    string getname() { return name; }
    int getage() { return age; }

    void display()
    {
        cout << "|PATIENT:" << name << "|AGE:" << age << "|" << endl;
    }
};

class Doctor
{
    string name;

public:
    Doctor() : name("N/R") {}
    Doctor(string n)
    {
        try
        {
            if (n == "")
            {
                throw logic_error("INVALID!");
            }
            name = n;
        }
        catch (const logic_error &l)
        {
            cout << "EXCEPTION:" << l.what() << endl;
        }
    }

    void display()
    {
        cout << "----DOCTOR DETAILS-----" << endl;
        cout << "|DOCTOR:" << name << "|" << endl;
    }
};

class Clinic
{

    string Cname;
    Doctor *dr;
    Patient patients[5];
    int patientcount;

public:
    Clinic() : Cname("N/R"), patientcount(0)
    {
        dr = nullptr;
    }
    Clinic(string n, Doctor *d)
    {
        dr=d;
        patientcount=0;
        try
        {
            if (n == "")
            {
                throw logic_error("INVALID!");
            }
            Cname = n;
        }
        catch (const logic_error &l)
        {
            cout << "EXCEPTION:" << l.what() << endl;
        }
    }

    void addpatients(string name, int age)
    {
        try
        {
            if (patientcount >= 5)
            {
                throw runtime_error("CAPACITY FULL!");
            }

            patients[patientcount] = Patient(name, age);
            patientcount++;
            cout << "PATIENT ADDED!" << endl;
        }
        catch (const runtime_error &r)
        {
            cout << "EXCEPTION:" << r.what() << endl;
        }
        catch (const logic_error &l)
        {
            cout << "EXCEPTION:" << l.what() << endl;
        }
    }

    void display()
    {
        try
        {
            if (patientcount == 0)
            {
                throw runtime_error("EMPTY!");
            }
        }
        catch (const runtime_error &r)
        {
            cout << "EXCEPTION:" << r.what() << endl;
        }

        cout<<"====HOSPITAL DETAILS===="<<endl;
        dr->display();
        cout<<"-------PATIENT LIST-------"<<endl;
        for(int i=0;i<patientcount;i++)
        {
            patients[i].display();
        }

    }
};

int main()
{
    Doctor dr("DR. HAMID");
    Clinic C1("CHILDREN CLINIC",&dr);
    C1.addpatients("a",45);
    C1.addpatients("b",34);
    C1.addpatients("c",42);
    C1.addpatients("",-5);
    C1.display();
}