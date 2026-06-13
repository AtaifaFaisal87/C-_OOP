#include <iostream>
using namespace std;

class MyClass {
private:
    int value;

public:
    MyClass(int v = 0) {
        value = v;
    }

    // =====================================================
    // ✔ PREFIX ++ (best: returns reference)
    // =====================================================
    MyClass& operator++() {
        value++;
        return *this;
    }

    // =====================================================
    // ✔ POSTFIX ++ (correct standard: returns old copy)
    // =====================================================
    MyClass operator++(int) {
        MyClass temp = *this;  // store old value
        value++;               // increment current
        return temp;           // return old value
    }

    // =====================================================
    // ✔ RETURN USING MyClass(value) STYLE
    // =====================================================
    MyClass operator--() {
        value--;
        return MyClass(value);   // new temporary object
    }

    void display() {
        cout << "Value: " << value << endl;
    }
};

int main() {

    MyClass obj(10);

    cout << "Initial:\n";
    obj.display();
    // Output: Value: 10

    // =====================================================
    // ✔ PREFIX ++
    // =====================================================
    cout << "\nPrefix ++:\n";
    ++obj;
    obj.display();
    // Output: Value: 11

    // =====================================================
    // ✔ POSTFIX ++
    // =====================================================
    cout << "\nPostfix ++:\n";
    MyClass old = obj++;
    old.display();
    // Output (old value):
    // Value: 11

    obj.display();
    // Output (new value after increment):
    // Value: 12

    // =====================================================
    // ✔ PREFIX using MyClass(value) style (-- operator demo)
    // =====================================================
    cout << "\nPrefix -- (returns MyClass(value)):\n";
    --obj;
    obj.display();
    // Output:
    // Value: 11

    // =====================================================
    // ✔ CHAINING TEST (works only with reference return)
    // =====================================================
    cout << "\nChaining ++(++obj):\n";
    ++(++obj);
    obj.display();
    // Output:
    // Value: 13

    return 0;
}