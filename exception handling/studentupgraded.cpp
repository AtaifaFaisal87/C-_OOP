#include <iostream>
#include <stdexcept>
using namespace std;

class Student
{
    int age;
    float marks[3];

public:
    Student(int age, float m[])
    {
        this->age = age;

        for (int i = 0; i < 3; i++)
        {
            marks[i] = m[i];
        }
    }

    friend ostream &operator<<(ostream &o, const Student &s)
    {
        o << "STUDENT AGE:" << s.age << endl;
        for (int i = 0; i < 3; i++)
        {
            o << "MARKS OF SUBJECT " << i + 1 << ":" << s.marks[i] << endl;
        }
        return o;
    }
};

int main()
{
    int age;
    float m[3];

    cout << "ENTER AGE:";
    cin >> age;
    try
    {
        if (age < 0)
        {
            throw logic_error("AGE CANT BE LESS THAN ZERO");
        }

        for (int i = 0; i < 3; i++)
        {
            cout << "ENTER MARKS FOR SUBJECT" << i + 1 << ":";
            cin >> m[i];

            if (m[i] < 0 || m[i] > 100)
            {
                throw out_of_range("INVALID MARKS!");
            }
        }

        Student s1(age, m);
        cout << s1;
    }

    catch (const out_of_range &r)
    {
        cout << "EXCEPTION:" << r.what() << endl;
    }
     
    catch (const logic_error &l)
    {
        cout << "EXCEPTION:" << l.what() << endl;
    }
}
