#include <iostream>
using namespace std;

class student
{

    int roll_no;
    string name;
    int semester;
    float gpa;
    static int count;

public:
    int getrollno()
    {
        return roll_no;
    }

    void input();
    void display();
};

int student ::count = 0;

void student::input()
{

    cout << "ENTER THE INFO OF STUDENT " << count + 1 << endl;
    cout << "ENTER ROLLNO=";
    cin >> roll_no;
    cout << "ENTER NAME=";
    cin >> name;
    cout << "ENTER SEMESTER=";
    cin >> semester;
    cout << "ENTER GPA=";
    cin >> gpa;
    cout << "----------------------" << endl;
    count++;
}

void student::display()
{
    cout << "| NAME:" << name << "|" << "| ROLL NO:" << roll_no << "|" << "| SEMESTER:" << semester << "|" << "| GPA:" << gpa << "|" << endl;
}

int main()
{

    student s[10];

    for (int i = 0; i < 1; i++)
    {
        s[i].input();
    }

    cout << "STUDENT INFORMATION" << endl
         << "-------------------" << endl;

    for (int i = 0; i < 1; i++)
    {
        s[i].display();
    }

    student *ptr;
    ptr = s;

    int found = 0;
    int findno;
    cout << "ENTER THE ROLL NO YOU WANNA FIND=";
    cin >> findno;

    for (int i = 0; i < 10; i++)
    {
        if ((ptr + i)->getrollno() == findno)
        {
            found = 1;
            (ptr + i)->display();
            break;
        }
    }

    if (found)
    {
        cout << "STUDENT FOUND!";
    }

    else
    {
        cout << "STUDENT NOT FOUND!";
    }
}