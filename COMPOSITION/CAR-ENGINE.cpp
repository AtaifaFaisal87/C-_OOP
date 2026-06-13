#include <iostream>
using namespace std;

class Engine
{
    string type;

public:
    Engine() : type("UNKNOWN") {}
    Engine(string t) : type(t) {}

    void Start()
    {
        cout << "ENGINE STARTED! BRRRR" << endl;
    }
    void Stop()
    {
        cout << "ENGINE STOPPED! PSSSS" << endl;
    }

    friend ostream& operator<<(ostream &o,const Engine &e)
    {
        o<<"TYPE:"<<e.type;
    }
};

class Car
{
    string name;
    string model;
    string numberplate;
    Engine e;

public:
    Car() : name("UNKNOWN"), model("UNKNOWN"), numberplate("UNKNOWN"), e("UNKNOWN") {}
    Car( string n,string m,string np,string t)
    {
        name=n;
        model=m;
        numberplate=np;
        e=Engine(t);
    }

    void putinkey()
    {
        e.Start();
        cout<<"CAR STARTED!"<<endl;
    }

    void removekey()
    {
        e.Stop();
        cout<<"CAR STOPPED!"<<endl;
    }

    void display()
    {
        cout<<"OWNER-NAME:"<<name<<endl
        <<"MODEL:"<<model<<endl
        <<"NUMBER-PLATE:"<<numberplate<<endl
        <<"ENGINE:"<<e;
        
    }
};

int main()
{
    Car c1("ALI","AUDI","AR459","HYBIRD");
    c1.putinkey();
    c1.removekey();
    c1.display();

}