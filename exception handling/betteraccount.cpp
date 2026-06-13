#include <iostream>
#include <stdexcept>
using namespace std;

class invalid_amount:public runtime_error
{
public:
    invalid_amount(const string &msg):runtime_error(msg) { }
};
class insufficient_balance:public runtime_error
{
public:
    insufficient_balance(const string &msg):runtime_error(msg) { }
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
            throw invalid_amount("AMOUNT LESS THAN ZERO");
        }

        balance += b;
        cout << "AMOUNT DEPOSITED" << endl;

    }
    void withdraw(double b)
    {
        if (b < 0)
        {
            throw invalid_amount("AMOUNT LESS THAN ZERO");
        }

        if (b > balance)
        {
          throw insufficient_balance("INSUFFICIENT BALANCE");
        }

        balance -= b;
        cout << "AMOUNT WITHDRAWN" << endl;
    }
};

int main()
{
    Account a1("ATAIFA", 500);

    try
    {
        a1.deposit(3);
    }
    catch (const invalid_amount &e)
    {
        cout << "EXCEPTION:" << e.what() << endl;
    }
    
    try
    {
       
        a1.withdraw(4000);
    }

    catch (const insufficient_balance &e)
    {
        cout << "EXCEPTION:" << e.what() << endl;
    }
   catch (const invalid_amount &e)
    {
        cout << "EXCEPTION:" << e.what() << endl;
    }
    catch(...)
    {
        cout<<"Exception occured!"<<endl;
    }
}