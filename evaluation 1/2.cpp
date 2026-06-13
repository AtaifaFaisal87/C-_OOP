#include <iostream>
using namespace std;

class car
{

    string owner_name;
    string model;
    double monthlyexpense[3];
    float avgexpense;

public:
    // DEFAULT CONSTRUCTOR
    car()
    {

        owner_name = "DEFAULT";
        model = "DEFAULT";
        avgexpense = 0;

        for (int i = 0; i < 3; i++)
        {
            monthlyexpense[i] = 0;
        }
    }

    // PARAMETRIZED CONSTRUCTOR
    car(string name, string m, double r[])
    {

        owner_name = name;
        model = m;

        for (int i = 0; i < 3; i++)
        {
            monthlyexpense[i] = r[i];
        }

        average();
    }

    // COPY CONSTRUCTOR
    car(const car &x)
    {
        owner_name = x.owner_name;
        model = x.model;
        avgexpense = x.avgexpense;

        for (int i = 0; i < 3; i++)
        {
            monthlyexpense[i] = x.monthlyexpense[i];
        }
    }

    // SETTER FUNCTIONS
    void setname(string name) { owner_name = name; }
    void setmodel(string m) { model = m; }
    void setname(double r[])
    {
        for (int i = 0; i < 3; i++)
        {
            monthlyexpense[i] = r[i];
        }
    }

    // GETTER FUNCTIONS
    string getname() { return owner_name; }
    string getmodel() { return model; }
    float getavgexpense() { return avgexpense; }

    // METHODS

    // AVERAGE
    void average()
    {

        float sum = 0;
        for (int i = 0; i < 3; i++)
        {
            sum += monthlyexpense[i];
        }

        avgexpense = sum / 6;
    }

    // DISPLAY BY CATEGORY
    void displaybycategory()
    {

        if (avgexpense <= 5000)
        {
            cout << "THE CAR HAS LOW EXPENSE!" << endl;
        }
        else if (5000 < avgexpense && avgexpense < 15000)
        {
            cout << "THE CAR HAS MEDIUM EXPENSE!" << endl;
        }
        else if (avgexpense >= 15000)
        {
            cout << "THE CAR HAS HIGH EXPENSE!" << endl;
        }
    }

    // DISPLAY INFO
    void display()
    {

        cout << "OWNER NAME:" << owner_name << endl
             << "MODEL:" << model << endl
             << "AVERAGE EXPENSE:" << avgexpense << endl;
        displaybycategory();
        cout << "--------------------------------------------" << endl;
    }
};

int main()
{

    cout << "============CAR RECORD LIST==============" << endl;

    int n;
    cout << "ENTER THE NUMBER OR CAR OWNERS:";
    cin >> n;

    car *c;
    c = new car[n];

    cout << "---------------INFO RECORDING--------------" << endl;
    for (int i = 0; i < n; i++)
    {
        string name;
        string model;
        double expense[3];

        cout << "ENTER OWNER NAME:";
        cin >> name;
        cout << "ENTER MODEL NAME:";
        cin >> model;

        for (int j = 0; j < 3; j++)
        {
            cout << "ENTER EXPENSE FOR " << j + 1 << " MONTH:";
            cin >> expense[i];
        }
        cout << "----------------------------" << endl;
        c[i] = car(name, model, expense);
    }

    cout << "================DISPLAYING THE LIST===============" << endl;

    for (int i = 0; i < n; i++)
    {
        c[i].display();
    }

    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (c[i].getavgexpense() > c[max].getavgexpense())
        {
            max = i;
        }
    }

    cout << "==========THE CAR WITH HIGHEST AVERAGE EXPENSE IS========" << endl;
    c[max].display();

    return 0;
}