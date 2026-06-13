#include <iostream>
using namespace std;

class employee
{

    int id[50];
    string name[50];
    static int count;

public:
    void addemployee(int id, string name);
    void employeedata();
    void displayemployee();
};

int employee::count = 0;
void employee ::addemployee(int id, string name)
{
    this->id[count] = id;
    this->name[count] = name;
    count++;
}

void employee ::employeedata()
{
    int num;
    int empid;
    string empname;
    cout << "ENTER THE NUMBER OF EMPLOYEES YOU WANNA ADD=";
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        // cout << "ENTER THE ID=";
        // cin >> empid;

        empid = count + 1;

        cout << "ENTER THE NAME=";
        cin >> empname;

        addemployee(empid, empname);
    }
    displayemployee();
}

void employee::displayemployee()
{
    for (int i = 0; i < count; i++)
    {
        cout << "ID:" << id[i] << endl
             << "NAME:" << name[i] << endl
             << "------------" << endl;
    }
}

int main()
{
    employee e;
    e.employeedata();
}