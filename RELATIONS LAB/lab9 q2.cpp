#include <iostream>
#include <string.h>
using namespace std;

class Salary
{
    float Grosspay;
    float deductions;
    float Netpay;

public:
    Salary() : Grosspay(0), deductions(0), Netpay(0) {}
    Salary(float g, float d, float n) : Grosspay(g), deductions(d), Netpay(Grosspay - deductions) {}

    void input()
    {
        cout << "ENTER GROSS PAY:";
        cin >> Grosspay;
        cout << "ENTER DEDUCTIONS:";
        cin >> deductions;
        Netpay = Grosspay - deductions;
    }

    void display()
    {
        cout << "GROSS-PAY:" << Grosspay << endl
             << "DEDUCTIONS:" << deductions << endl
             << "NET-PAY:" << Netpay << endl;
    }

    friend ostream &operator<<(ostream &o, const Salary &s)
    {
        o << "GROSS-PAY:" << s.Grosspay << endl
          << "DEDUCTIONS:" << s.deductions << endl
          << "NET-PAY:" << s.Netpay << endl;
    }
};

class Date
{
    int day;
    int month;
    int year;

public:
    Date() : day(1), month(1), year(2000) {}
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    void setday(int d) { day = d; }
    void setmonth(int m) { month = m; }
    void setyear(int y) { year = y; }

    int getday() const { return day; }
    int getmonth() const { return month; }
    int getyear() const { return year; }

    void input()
    {
        cout << "ENTER DAY:";
        cin >> day;
        if (day <= 0 || day > 31)
        {
            cout << ("INVALID DATE!")<<endl;
            return;
        }

        cout << "ENTER MONTH:";
        cin >> month;

        if (month <= 0 || month > 12)
        {
            cout << ("INVALID MONTH!")<<endl;
            return;
        }

        cout << "ENTER YEAR:";
        cin >> year;
        if (year <= 0)
        {
            cout << ("INVALID YEAR!")<<endl;
            return;
        }
    }

    void display()
    {
        cout << day << ":" << month << ":" << year << endl;
    }

    friend ostream &operator<<(ostream &o, const Date &d)
    {
        o << d.day << ":" << d.month << ":" << d.year << endl;
    }
};

class Employee
{
    int employeeno;
    char *name;
    Salary s;
    Date d;

public:
    Employee() : employeeno(0)
    {
        name = nullptr;
    }

    Employee(int en, char *n) : employeeno(en)
    {
        name = new char[strlen(n) + 1];
        s.input();
        d.input();
    }

    void input()
    {
        cout << "ENTER EMPLOYEE NO: ";
        cin >> employeeno;

        char temp[100];
        cout << "ENTER NAME: ";
        cin >> temp;

        name = new char[strlen(temp) + 1];
        strcpy(name, temp);

        cout << "ENTER SALARY DETAILS:" << endl;
        s.input();

        cout << "ENTER JOIN DATE:" << endl;
        d.input();
    }

    void display()
    {
        cout << "NAME:" << name << endl
             << "EMPLOYEE NO:" << employeeno << endl
             << d << endl
             << s << endl;
    }

    friend ostream &operator<<(ostream &o, const Employee &e)
    {
        o << "NAME:" << e.name << endl
          << "EMPLOYEE NO:" << e.employeeno << endl
          << e.d << endl
          << e.s << endl;
    }

    ~Employee()
    {
        delete name;
        cout<<"EMPLOYEE DELETED!"<<endl;
        
    }
};

int main()
{
  Employee e1;
  e1.input();
  e1.display();
}