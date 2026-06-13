#include <iostream>
#include <vector>
using namespace std;

class Employee
{
    string name;
    int id;

public:
    Employee() : name("N/A"), id(0) {}
    Employee(string n, int i) : name(n), id(i) {}

    int getid() { return id; }
    string getname() { return name; }

    void display()
    {
        cout << "|EMPLOYEE NAME:" << name << "|ID:" << id << "|" << endl;
    }

    void input()
    {
        cout << "ENTER NAME:";
        cin >> name;
        cout << "ENTER ID:";
        cin >> id;
    }
};

class department
{
    string name;
    vector<Employee> emp;

public:
    department() : name("N/A") {}
    department(string n) : name(n) {}

    void add(string name, int id)
    {
        emp.push_back(Employee(name, id));
        cout << "EMPLOYEE ADDED" << endl;
    }

    void remove(int id)
    {
        for (int i = 0; i < emp.size(); i++)
        {
            if (emp[i].getid() == id)
            {
                emp.erase(emp.begin() + i);
                cout << "EMPLOYEE REMOVED!" << endl;
                return;
            }
        }
        cout << "EMPLOYEE NOT FOUND!" << endl;
    }

    void search(string name)
    {
        for (int i = 0; i < emp.size(); i++)
        {
            if (emp[i].getname() == name)
            {
                emp[i].display();
                return;
            }
        }
        cout << "EMPLOYEE NOT FOUND!" << endl;
    }

    void update(string name)
    {
        for (int i = 0; i < emp.size(); i++)
        {
            if (emp[i].getname() == name)
            {
                emp[i].input();
                return;
            }
        }
        cout << "EMPLOYEE NOT FOUND!" << endl;
    }

    void display()
    {
        if (emp.size() == 0)
        {
            cout << "NO EMPLOYEES" << endl;
            return;
        }

        for (auto it = emp.begin(); it != emp.end(); it++)
        {
            it->display();
        }
    }
};

int main()
{
    department d1("IT");
    d1.add("anwar", 18);
    d1.add("sara", 34);
    d1.add("ali", 25);

    d1.display();
    d1.remove(18);
    d1.display();
    d1.update("ali");
    d1.display();
    d1.search("anwar");
}
