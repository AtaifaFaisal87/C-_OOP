#include <iostream>
using namespace std;

// Grandparent
class Person {
public:
    void display() {
        cout << "Person display\n";
    }
};

// Parent 1
class Student : virtual public Person {
public:
    void display() {
        cout << "Student display\n";
    }
};

// Parent 2
class Teacher : virtual public Person {
public:
    void display() {
        cout << "Teacher display\n";
    }
};

// Child
class TA : public Student, public Teacher {
public:
    void display() {
        cout << "TA display\n";
    }

    void showAll() {
        cout << "\n--- Calling from TA ---\n";

        // Child version (overrides/hides both parents)
        display();

        // Parent versions (scope resolution)
        Student::display();
        Teacher::display();

        // Grandparent version (now safe due to virtual inheritance)
        Person::display();
    }
};

int main() {
    TA obj;

    cout << "--- Direct calls ---\n";

    obj.display();           // TA version

    // Ambiguity resolution
    obj.Student::display();  // Student version
    obj.Teacher::display();  // Teacher version

    // Grandparent access (works safely due to virtual inheritance)
    obj.Person::display();

    // Full demonstration
    obj.showAll();

    return 0;
}