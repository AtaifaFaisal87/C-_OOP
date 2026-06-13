#include <iostream>
using namespace std;

// *Design a class named Apartment that has the following data members: owner name (string), apartment number (int),
//  monthly rent (double array of size 6), and average rent (float).
// Implement a default constructor, parameterized constructor,
// and copy constructor for the class. Also provide suitable getter and setter functions for all data members.
// Write a member function to calculate the average rent by adding all
// six monthly rent values and dividing the sum by 6.
// Using conditional statements, display “Economical”
//  if the average rent is less than or equal to 30000, “Standard”
//   if it is greater than 30000 and less than 60000, otherwise display “Premium”.

class apartment
{

    string name;
    int apt_no;
    double monthlyrent[6];
    float avg_rent;

public:
    apartment()
    {

        name = "default";
        apt_no = 0;

        for (int i = 0; i < 6; i++)
        {
            monthlyrent[i] = 0;
        }

        avg_rent = 0;
    }

    apartment(int aptn, string n, double m[6])
    {
        apt_no = aptn;
        name = n;
        for (int i = 0; i < 6; i++)
        {
            monthlyrent[i] = m[i];
        }

        avgrent();
    }

    apartment(const apartment &x)
    {
        apt_no = x.apt_no;
        name = x.name;

        for (int i = 0; i < 6; i++)
        {
            monthlyrent[i] = x.monthlyrent[i];
        }

        avg_rent = x.avg_rent;
    }

    void setname(string oname)
    {
        name = oname;
    }

    void setaptno(int ano)
    {
        apt_no = ano;
    }

    void setmonthlyrent()
    {
        for (int i = 0; i < 6; i++)
        {
            cout << "ENTER RENT OF " << i + 1 << " MONTH:";
            cin >> monthlyrent[i];
        }

        avgrent();
    }

    string getname()
    {
        return name;
    }

    int getaptno()
    {
        return apt_no;
    }
    float getavgrent()
    {
        return avg_rent;
    }

    void avgrent()
    {
        int sum = 0;
        for (int i = 0; i < 6; i++)
        {
            sum += monthlyrent[i];
        }

        avg_rent = sum / 6;
    }

    void displaybycategory()
    {
        if (avg_rent <= 30000)
        {
            cout << "THE APARTMENT STATUS IS ECONOMICAL!" << endl;
        }
        else if (30000 < avg_rent && avg_rent < 60000)
        {
            cout << "THE APARTMENT STATUS IS STANDARD!" << endl;
        }
        else
        {
            cout << "THE APARTMENT STATUS IS PREMIUM!" << endl;
        }
    }

    void display()
    {

        cout << "APARTMENT NO:" << apt_no << endl
             << "NAME:" << name << endl
             << "AVERAGE RENT" << avg_rent << endl;

        displaybycategory();
    }
};

int main()
{

    int n;

    cout << "ENTER THE NUMBER OF APARTMENTS=";
    cin >> n;

    apartment *apt;

    apt = new apartment[n];

    for (int i = 0; i < n; i++)
    {
        string name;
        int aptno;
        double rent[6];

        cout << "ENTER NAME=";
        cin >> name;
        cout << "ENTER APARTMENT NO=";
        cin >> aptno;

        for (int j = 0; j < 6; j++)
        {
            cout << "ENTER RENT OF " << j + 1 << " MONTH:";
            cin >> rent[j];
        }

        apt[i] = apartment(aptno, name, rent);
    }

    for (int i = 0; i < n; i++)
    {
        apt[i].display();
    }

    int maxrent = 0;

    for (int i = 0; i < n; i++)
    {
        if (apt[i].getavgrent() > apt[maxrent].getavgrent())
        {
            maxrent = i;
        }
    }

    cout << "THE APARTMENT WITH MAX AVERAGE RENT IS=" << endl;
    apt[maxrent].display();

    delete[] apt;

    return 0;
}