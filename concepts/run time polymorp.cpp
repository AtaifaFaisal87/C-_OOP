//runtime binding
#include <iostream>
using namespace std;

class Animal
{
public:
    virtual void sound() // runtime polymorphism
    {
        cout << "ANIMAL MAKES SOUND!" << endl;
    }
};

class dog : public Animal
{
public:
    void sound ()override // OVERRIDING  //adding override or not doesnt matter cause it wll automatically become overridden fn
    {
        cout << "DOG BARKS!" << endl;
    }
};

int main()
{
    Animal *ptr;
    dog d;
    ptr = &d;
    ptr->sound();
}
