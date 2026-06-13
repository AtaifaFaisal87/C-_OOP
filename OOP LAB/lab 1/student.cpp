#include <iostream>
using namespace std;

class student
{
private:
    string name;
    int rollno;
    int marks[3];

public:
    // INLINE SETTERS AND GETTERS
    void set_name(string n)
    {
        name = n;
    }

    string get_name()
    {
        return name;
    }

    void set_rollno(int r)
    {
        rollno = r;
    }

    int get_rollno()
    {
        return rollno;
    }

    void set_marks()
    {
        for (int i = 0; i < 3; i++)
        {
            cout << "ENTER QUIZ " << i + 1 << " MARKS: ";
            cin >> marks[i];
        }
    }

     void get_marks()
    {
        int quiz;
        cout << "ENTER QUIZ NUMBER TO VIEW MARKS: ";
        cin >> quiz;

        if (quiz >= 1 && quiz <= 3)
        {
            cout << "QUIZ " << quiz << " MARKS: " << marks[quiz - 1] << endl;
        }
        else
        {
            cout << "INVALID QUIZ NUMBER" << endl;
        }
    }

    void print_avg()
    {
        int sum = 0;

        for (int i = 0; i < 3; i++)
        {
            sum += marks[i];
        }

        float average = (float)sum / 3;
        cout << "AVERAGE: " << average << endl;
    }

    // OUT OF LINE FUNCTION
    void display();
};


void student::display()
{
    cout << "\nSTUDENT NAME: " << get_name() << endl;
    cout << "ROLL NUMBER: " << get_rollno() << endl;
    cout << "MARKS" << endl;

    for (int i = 0; i < 3; i++)
    {
        cout << "QUIZ " << i + 1 << ": " << marks[i] << endl;
    }

    print_avg();
}

int main()
{
    student s1;

    s1.set_name("ATAIFA FAISAL");
    s1.set_rollno(21);
    s1.set_marks();
    s1.display();

    return 0;
}
