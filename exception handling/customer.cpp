#include <iostream>
#include <stdexcept>
using namespace std;

class Myexception
{
protected:
    string msg;

public:
    Myexception(string msg)
    {
        this->msg = msg;
    }

    string what()const
    {
        return msg;
    }
};

class Myruntime_error : public Myexception
{
public:
    Myruntime_error(const string &msg) : Myexception(msg) {}
};

class Account
{

    string name;
    double balance;

public:
    Account(string n = "unknown", double b = 1) : name(n), balance(b) {}

    void setname(string n) { name = n; }
    void setbalance(double b) { balance = b; }

    string getname() { return name; }
    double getbalance() { return balance; }

    void deposit(double b)
    {
        if (b < 0)
        {
            throw Myruntime_error("AMOUNT LESS THAN ZERO");
            // throw "AMOUNT LESS THAN ZERO";
        }

        balance += b;
        cout << "AMOUNT DEPOSITED" << endl;

        // else
        // {
        //     cout << "AMOUNT LESS THAN ZERO" << endl;
        // }
    }
    void withdraw(double b)
    {
        if (b < 0)
        {
            throw Myruntime_error("AMOUNT LESS THAN ZERO");
            // throw "AMOUNT LESS THAN ZERO";
        }

        if (b > balance)
        {
            throw(0);
            // throw Myruntime_error("INSUFFICIENT BALANCE");
            // throw "INSUFFICIENT BALANCE";
        }

        balance -= b;
        cout << "AMOUNT WITHDRAWN" << endl;

        // else
        // {
        //     cout << "AMOUNT LESS THAN ZERO" << endl;
        // }
    }
};

int main()
{
    Account a1("ATAIFA", 500);
    // a1.deposit(300);
    // a1.withdraw(4000);

    // try
    // {
    //     a1.deposit(300);
    //     a1.withdraw(4000);
    // }

    try
    {
        a1.deposit(-23);
    }
    catch (const Myruntime_error &e)
    {
        cout << "EXCEPTION:" << e.what() << endl;
    }
    // catch (const char *msg)
    // {
    //     cout << "EXCEPTION:" << msg << endl;
    // }

    try
    {

        a1.withdraw(4000);
    }

    catch (const Myruntime_error &e)
    {
        cout << "EXCEPTION:" << e.what() << endl;
    }

    // catch (const char *msg)
    // {
    //     cout << "EXCEPTION:" << msg << endl;
    // }

    //DEFAULT CATCH BLOCK
    catch(...)
    {
        cout<<"Exception occured!"<<endl;
    }
}