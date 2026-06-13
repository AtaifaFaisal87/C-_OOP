#include <iostream>
using namespace std;

class Employee
{
    string name;
    int id;

public:
    Employee()
    {
        name = "UNKNONW";
        id = 0;
    }
    Employee(string name, int id) : name(name), id(id) {}

    void setname(string n) { name = n; }
    void setid(int i) { id = i; }

    string getname() { return name; }
    int getid() { return id; }

    void display()
    {
        cout << "|ID:" << id << "|NAME:" << name << "|" << endl;
    }
};

class Department
{
    string deptname;
    int empcount;
    Employee *emp[5];

public:
    Department()
    {
        deptname = "UNKNONW";
        empcount = 0;
        for (int i = 0; i < 5; i++)
        {
            emp[i] = nullptr;
        }
    }
    Department(string dn) : deptname(dn), empcount(0)
    {
        for (int i = 0; i < 5; i++)
        {
            emp[i] = nullptr;
        }
    }

    void addemployee(Employee *e)
    {
        if (empcount < 5)
        {
            emp[empcount] = e;
            empcount++;
        }
        else
        {
            cout << "EMPLOYEE COUNT REACHED!" << endl;
        }
    }

    void removeemployee(string ename)
    {
        for (int i = 0; i < empcount; i++)
        {
            if (emp[i]->getname() == ename)
            {
                for (int j = i; j < empcount - 1; j++)
                {
                    emp[j] = emp[j + 1];
                }
                emp[--empcount] = nullptr;
                return;
            }
        }
    }

    void display()
    {
        if (empcount == 0)
        {
            cout << "NO EMPLOYEE IN DEPARTMENT!" << endl;
        }

        else
        {
            cout << "DEPARTMENT NAME:" << deptname << endl;
            for (int i = 0; i < empcount; i++)
            {
                emp[i]->display();
            }
        }
    }
};

int main()
{
    string dname;
    cout << "ENTER DEPARTMENT NAME:";
    cin >> dname;

    Department D1(dname);

    cout << "====ENTER EMPLOYEE INFO====" << endl;
    int n;
    do
    {
        cout << "ENTER THE NUMBER OF EMPLOYEES:";
        cin >> n;
        if (n > 5 || n <= 0)
        {
            cout << "INVALID!" << endl;
        }
    } while (n > 5 || n <= 0);
    Employee e[n];
    string ename;
    int id;

    for (int i = 0; i < n; i++)
    {

        cout << "ENTER EMPLOYEE ID:";
        cin >> id;
        cout << "ENTER EMPLOYEE NAME:";
        cin >> ename;

        e[i] = Employee(ename, id);
        D1.addemployee(&e[i]);
    }

    cout << "DISPLAYING EMPLOYEES" << endl;
    D1.display();

    // int choice;
    // string en;
    // char exitKey = 'y';

    // cout << "\nDO YOU WANT TO REMOVE EMPLOYEES?\n";
    // cout << "PRESS 1: YES\n";
    // cout << "PRESS 2: NO\n";
    // cout << "ENTER YOUR CHOICE: ";
    // cin >> choice;

    // switch (choice)
    // {
    // case 1:
    //     while (true)
    //     {
    //         D1.display();

    //         cout << "\nENTER EMPLOYEE NAME TO REMOVE: ";
    //         cin >> en;

    //         D1.removeemployee(en);

    //         cout << "\nPRESS 'x' TO STOP REMOVING OR ANY KEY TO CONTINUE: ";
    //         cin >> exitKey;

    //         if (exitKey == 'x' || exitKey == 'X')
    //         {
    //             break;
    //         }
    //     }
    //     break;

    // case 2:
    //     cout << "OK, NO CHANGES MADE." << endl;
    //     break;

    // default:
    //     cout << "INVALID CHOICE! ENTER 1 OR 2 ONLY." << endl;
    //     break;
    // }
}