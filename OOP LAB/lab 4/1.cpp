
#include <iostream>
#include <string.h>
using namespace std;

class student
{
    char *name;
    int rollno;
    double marks[5];
    float percentage;

    static int counter;

public:
    // CONSTRUCTORS
    student()
    {
        counter++;
        cout << "===============ENTER DETAILS OF STUDENT NO " << counter
             << "===============" << endl;

        char temp[50];
        cout << "ENTER THE NAME:";
        cin.ignore();
        cin.getline(temp,50);
        name = new char[strlen(temp) + 1];
        strcpy(name, temp);
        cout << "ENTER ROLL NO=";
        cin >> rollno;

        for (int i = 0; i < 5; i++)
        {
            cout << "ENTER MARKS FOR QUIZ " << i + 1 << ":";
            cin >> marks[i];
        }

        percent();
    }

    student(char *s, int r, double m[])
    {
        name = new char[strlen(s) + 1];
        strcpy(name, s);
        rollno = r;
        for (int i = 0; i < 5; i++)
        {
            marks[i] = m[i];
        }
        percent();
    }

    student(const student &s)
    {
        name = new char[strlen(s.name) + 1];
        strcpy(name, s.name);
        rollno = s.rollno;
        for (int i = 0; i < 5; i++)
        {
            marks[i] = s.marks[i];
        }
        percentage = s.percentage;
    }

    // DESTRUCTOR
    ~student() { delete[] name; }

    // SETTER
    void setname(char *s)
    {
        delete[] name;
        name = new char[strlen(s) + 1];
        strcpy(name, s);
    }
    void setrollno(int r) { rollno = r; }
    void setmarks(double m[])
    {
        for (int i = 0; i < 5; i++)
        {
            marks[i] = m[i];
        }
    }

    // GETTER
    char *getname() { return name; }
    int getrollno() { return rollno; }
    double getmarks(int i) { return marks[i]; }
    float getpercentage() { return percentage; }

    // FUNCTIONS
    void percent();
    void display();
    double highestmark();
};

int student::counter = 0;

void student::percent()
{
    double sum = 0;
    for (int i = 0; i < 5; i++) { sum += marks[i]; }
    percentage = (sum / 500) * 100;
}

void student::display()
{
    cout << "---------------------------------------------" << endl;
    cout << "| STUDENT NAME  : " << name << endl;
    cout << "| ROLL NUMBER   : " << rollno << endl;
    cout << "| MARKS         : ";
    for (int i = 0; i < 5; i++)
    {
        cout << marks[i];
        if (i != 4) cout << " | ";
    }
    cout << endl;
    cout << "| PERCENTAGE    : " << percentage << "%" << endl;

    cout << "| GRADE         : ";
    if (percentage >= 80) cout << "A";
    else if (percentage >= 70) cout << "B";
    else if (percentage >= 50) cout << "C";
    else cout << "F";
    cout << endl;

    cout << "| HIGHEST MARK  : " << highestmark() << endl;
    cout << "---------------------------------------------" << endl;
}

double student::highestmark()
{
    double max = marks[0];
    for (int i = 1; i < 5; i++)
    {
        if (marks[i] > max) { max = marks[i]; }
    }
    return max;
}

int main()
{
    cout << "============STUDENT DETAILS==============" << endl;
    int n;
    cout << "ENTER THE NUMBER OF STUDENTS:";
    cin >> n;

    student *s;
    s = new student[n];

    cout << "================DISPLAYING THE LIST===============" << endl;
    for (int i = 0; i < n; i++)
    {
        s[i].display();
    }

    delete[] s;
    return 0;
}    