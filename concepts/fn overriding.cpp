#include<iostream>
using namespace std;
class Animal{
    public:
    void sound()
    {
        cout<<"ANIMAL MAKES SOUND!"<<endl;
    }
};

class dog:public Animal{
    public:
    void sound()   //OVERRIDING
    {
        cout<<"DOG BARKS!"<<endl;
    }

};

class cat :public Animal{
    public:
       void sound()    //OVERRIDING
    {
        Animal::sound();   //USING BASE CLASS FN TOO THROUGH RESOLUTION OPERATOR
        cout<<"CAT MEOWS!"<<endl;
    }
};

class ladybug :public Animal{
  //NO OVERRIDING USES THE BASE CLASS FUNCTION
};

int main()
{
    Animal a;
    a.sound();       //ANIMAL MAKES SOUND
    dog d;
    d.sound();     //DOG BARKS
    cat c;
    c.sound();  // ANIMAL MAKES SOUND.....CAT MEOWS
    ladybug l;
    l.sound();  // ANIMAL MAKES SOUND
}
