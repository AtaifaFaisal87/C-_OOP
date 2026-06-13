#include <iostream>
using namespace std;

// Base Class
class Account {
protected:
    double balance;

public:
    // Constructor 
    Account(double b = 1) {
        if (b < 0)
            balance = 1;
        else
            balance = b;
    }

    // Pure Virtual Function
    virtual double calculate_interest() = 0;

    // Deposit
    Account& operator+=(double amount) {
        if (amount > 0)
            balance += amount;
        return *this;
    }

    // Withdraw
    Account& operator-=(double amount) {
        if (amount > 0 && balance >= amount)
            balance -= amount;
        else
            cout << "Not enough balance\n";
        return *this;
    }

    // Comparison Operators
    bool operator>(const Account& other) {
        return balance > other.balance;
    }

    bool operator<(const Account& other) {
        return balance < other.balance;
    }

    bool operator==(const Account& other) {
        return balance == other.balance;
    }

    // Display
    void display() {
        cout << "Balance: " << balance << endl;
    }
};

// Derived Class
class SavingAccount : public Account {
private:
    double rate;

public:
    // Constructor
    SavingAccount(double b, double r) : Account(b) {
        rate = r;
    }

    // Override
    double calculate_interest() override {
        return balance * rate;
    }
};

// Driver 
int main() {
    SavingAccount a1(5000, 0.05);
    SavingAccount a2(3000, 0.04);

    a1 += 1000;   
    a1 -= 2000;   
    a1.display();

    cout << "INTEREST: " << a1.calculate_interest() << endl;

    if (a1 > a2)
        cout << "A1 HAS MORE BALANCE\n";
    else
        cout << "A2 HAS MORE BALANCE\n";

    return 0;
}