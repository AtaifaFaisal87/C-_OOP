#include <iostream>
#include <string.h>
using namespace std;

class student
{
protected:
    char *name;
    int rollno;
    double marks[5];
    float percentage;

public:
    student() {}

    student(char *s, int r, double m[])
    {
        name = new char[strlen(s) + 1];
        strcpy(name, s);
        rollno = r;

        for (int i = 0; i < 5; i++)
            marks[i] = m[i];
    }

    virtual void CalculatePercentage()
    {
        double sum = 0;
        for (int i = 0; i < 5; i++)
            sum += marks[i];

        percentage = (sum / 500) * 100;
    }

    virtual void display()
    {
        cout << "---------------------------------------------" << endl;
        cout << "| STUDENT NAME  : " << name << endl;
        cout << "| ROLL NUMBER   : " << rollno << endl;
        cout << "| MARKS         : ";
        for (int i = 0; i < 5; i++)
        {
            cout << marks[i];
            if (i != 4)
                cout << " | ";
        }
        cout << endl;
        cout << "| PERCENTAGE    : " << percentage << "%" << endl;
        cout << "---------------------------------------------" << endl;
    }

    virtual ~student()
    {
        delete[] name;
    }
};

// ================= SCIENCE STUDENT =================
class scienceStudent : public student
{
    double practical;

public:
    scienceStudent() : student() {}

    scienceStudent(char *s, int r, double m[], double p) : student(s, r, m)
    {
        practical = p;
        CalculatePercentage();
    }

    void CalculatePercentage() override
    {
        double sum = practical;
        for (int i = 0; i < 5; i++)
            sum += marks[i];

        percentage = (sum / 650) * 100;
    }

    void display() override
    {
        cout << "---------------------------------------------" << endl;
        cout << "| SCIENCE STUDENT" << endl;
        cout << "| STUDENT NAME  : " << name << endl;
        cout << "| ROLL NUMBER   : " << rollno << endl;
        cout << "| MARKS         : ";
        for (int i = 0; i < 5; i++)
        {
            cout << marks[i];
            if (i != 4)
                cout << " | ";
        }
        cout << endl;
        cout << "| PRACTICAL     : " << practical << endl;
        cout << "| PERCENTAGE    : " << percentage << "%" << endl;
        cout << "---------------------------------------------" << endl;
    }
};

// ================= ARTS STUDENT =================
class artsStudent : public student
{
    double optional;

public:
    artsStudent() : student() {}

    artsStudent(char *s, int r, double m[], double o) : student(s, r, m)
    {
        optional = o;
        CalculatePercentage();
    }

    void CalculatePercentage() override
    {
        double sum = optional;
        for (int i = 0; i < 5; i++)
            sum += marks[i];

        percentage = (sum / 600) * 100;
    }

    void display() override
    {
        cout << "---------------------------------------------" << endl;
        cout << "| ARTS STUDENT" << endl;
        cout << "| STUDENT NAME  : " << name << endl;
        cout << "| ROLL NUMBER   : " << rollno << endl;
        cout << "| MARKS         : ";
        for (int i = 0; i < 5; i++)
        {
            cout << marks[i];
            if (i != 4)
                cout << " | ";
        }
        cout << endl;
        cout << "| OPTIONAL      : " << optional << endl;
        cout << "| PERCENTAGE    : " << percentage << "%" << endl;
        cout << "---------------------------------------------" << endl;
    }
};

// ================= DRIVER =================
int main()
{
    int n;

    cout << "Enter number of Science Students: ";
    cin >> n;

    scienceStudent *sArr = new scienceStudent[n];

    for (int i = 0; i < n; i++)
    {
        char tempName[50];
        int r;
        double m[5], p;

        cout << "\nEnter Name of Science Student " << i + 1 << ": ";
        cin.ignore();
        cin.getline(tempName, 50);
        cout << "Enter Roll No: ";
        cin >> r;

        for (int j = 0; j < 5; j++)
        {
            cout << "Enter Quiz " << j + 1 << " Marks: ";
            cin >> m[j];
        }

        cout << "Enter Practical Marks (150): ";
        cin >> p;

        sArr[i] = scienceStudent(tempName, r, m, p);
    }

    cout << "\n--- DISPLAYING SCIENCE STUDENTS ---\n";
    for (int i = 0; i < n; i++)
        sArr[i].display();

    cout << "\nEnter number of Arts Students: ";
    cin >> n;

    artsStudent *aArr = new artsStudent[n];

    for (int i = 0; i < n; i++)
    {
        char tempName[50];
        int r;
        double m[5], o;

        cout << "\nEnter Name of Arts Student " << i + 1 << ": ";
        cin.ignore();
        cin.getline(tempName, 50);
        cout << "Enter Roll No: ";
        cin >> r;

        for (int j = 0; j < 5; j++)
        {
            cout << "Enter Quiz " << j + 1 << " Marks: ";
            cin >> m[j];
        }

        cout << "Enter Optional Marks (100): ";
        cin >> o;

        aArr[i] = artsStudent(tempName, r, m, o);
    }

    cout << "\n--- DISPLAYING ARTS STUDENTS ---\n";
    for (int i = 0; i < n; i++)
        aArr[i].display();

    delete[] sArr;
    delete[] aArr;

    return 0;
}
