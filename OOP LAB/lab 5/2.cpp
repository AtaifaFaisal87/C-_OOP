#include <iostream>
#include <string>
using namespace std;

class POST
{
protected:
    string name;
    string to;
    float stampcost;

public:
    POST()
    {
        stampcost = 1;
        to = "";
    }

    void READ()
    {
        cout << "ENTER NAME:";
        getline(cin, name);

        cout << "ENTER RECEIVER ADDRESS:";
        getline(cin, to);

        cout << "ENTER STAMPCOST:";
        cin >> stampcost;
    }

    void PRINT()
    {
        cout << "---------------------------------------------\n";
        cout << "| NAME  : " << name << endl;
        cout << "| ADDRESS   : " << to << endl;
        cout << "| STAMP-COST  :" << stampcost << endl;
    }

    float TOTALCOST()
    {
        return stampcost;
    }
};

class RegisteredPost : public POST
{
protected:
    float weight;
    float regcost;

public:
    RegisteredPost()
    {
        weight = 20;
        regcost = 10;
    }

    void READ()
    {
        POST::READ();

        cout << "ENTER WEIGHT OF POST:";
        cin >> weight;

        cout << "ENTER REGISTRATION COST:";
        cin >> regcost;
    }

    void PRINT()
    {
        POST::PRINT();

        cout << "---------------------------------------------\n";
        cout << "| WEIGHT OF POST  : " << weight << endl;
        cout << "| REGISTRATION COST   : " << regcost << endl;
    }

    float TOTALCOST()
    {
        return stampcost + regcost;
    }
};

class InsuredRegisteredPost : public RegisteredPost
{
protected:
    float AMTinsured;

public:
    InsuredRegisteredPost()
    {
        AMTinsured = 20;
    }

    void READ()
    {
        RegisteredPost::READ();

        cout << "ENTER INSURED VALUE OF POST:";
        cin >> AMTinsured;
    }

    void PRINT()
    {
        RegisteredPost::PRINT();

        cout << "---------------------------------------------\n";
        cout << "| INSURED VALUE OF POST : " << AMTinsured << endl;
        cout << "---------------------------------------------\n";
        cout << "| TOTAL COST : " << TOTALCOST() << endl;
    }

    float TOTALCOST()
    {
        return stampcost + regcost + AMTinsured;
    }
};

int main()
{
    InsuredRegisteredPost envelope;

    envelope.READ();

    cout << "Post Details.."<<endl;
    envelope.PRINT();

    return 0;
}
