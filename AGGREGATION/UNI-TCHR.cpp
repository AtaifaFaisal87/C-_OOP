#include <iostream>
using namespace std;

class Teacher
{
    string name;
    string subject;

public:
    Teacher()
    {
        name = "UNKNOWN";
        subject = "UNKNOWN";
    }
    Teacher(string n, string s) : name(n), subject(s) {}

    string getname(){return name;}
    string getsub(){return subject;}

    void display()
    {
        cout << "|NAME:" << name << "|SUBJECT:" << subject <<"|"<< endl;
    }
};

class University
{
    string uniname;
    Teacher *teachers[5];
    int tcount;

public:
    University() { uniname = "UNKNOWN"; tcount=0; }
    University(string u) : uniname(u), tcount(0) {}

    void addteacher(Teacher *t)
    {
        if (tcount < 5)
        {
            teachers[tcount] = t;
            tcount++;
        }


        else
        {
            cout << "VACANCY FULL!" << endl;
        }
    }

    void display()
    {
        cout << "TEACHERS LIST" << endl;
        for (int i = 0; i < tcount; i++)
        {
            teachers[i]->display();
        }
    }
};

int main()
{
    string u;
    cout << "ENTER UNIVERSITY NAME:";
    cin >> u;
    University U1(u);

    int n;
    do
    {
        cout << "ENTER NUMBER OF TEACHERS(1-5):";
        cin >> n;
        if (n > 5 || n <= 0)
        {
            cout << "INVALID!" << endl;
        }

    } while (n > 5 || n <= 0);

    Teacher t[n];
    string tname;
    string tsub;

    for (int i = 0; i < n; i++)
    {
        cout << "ENTER TEACHER NAME:";
        cin >> tname;
        cout << "ENTER SUBJECT:";
        cin >> tsub;

        t[i] = Teacher(tname, tsub);
        U1.addteacher(&t[i]);
    }

    U1.display();
    return 0;
}