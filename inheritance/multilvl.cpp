#include <iostream>
using namespace std;

// 🔹 Base Class
class Person {
protected:
    string name;
    int age;

public:
    Person(string n, int a) {
        name = n;
        age = a;
        cout << "Person Constructor\n";
    }

    virtual void show() {
        cout << "Person: " << name << ", " << age << endl;
    }

    ~Person() {
        cout << "Person Destructor\n";
    }
};

// 🔹 Level 2
class Employee : public Person {
protected:
    string id;

public:
    Employee(string n, int a, string i)
        : Person(n, a) {
        id = i;
        cout << "Employee Constructor\n";
    }

    void show() override {
        cout << "Employee ID: " << id << endl;
    }

    ~Employee() {
        cout << "Employee Destructor\n";
    }
};

// 🔹 Level 3
class Faculty : public Employee {
    string subject;

public:
    Faculty(string n, int a, string i, string sub)
        : Employee(n, a, i) {
        subject = sub;
        cout << "Faculty Constructor\n";
    }

    void show() final {
        cout << name << " teaches " << subject << endl;
    }

    ~Faculty() {
        cout << "Faculty Destructor\n";
    }
};

// 🔹 MAIN
int main() {
    Person* ptr;
    ptr = new Faculty("Ataifa", 20, "F123", "OOP");

    ptr->show();   // Runtime polymorphism

    delete ptr;
}