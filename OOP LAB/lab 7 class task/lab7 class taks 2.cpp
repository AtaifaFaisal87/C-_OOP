#include <iostream>
using namespace std;

class DateTime
{

    int day, month;
    int year;
    int hours, minutes, seconds;

public:
    void setvalue(int d = 7, int m = 1, int y = 2026, int hrs = 00, int min = 00, int sec = 00)
    {
        day = d;
        month = m;
        year = y;
        hours = hrs;
        minutes = min;
        seconds = sec;
    }

    void display()
    {
        cout << day << "/" << month << "/" << year << " " << hours << ":" << minutes << ":" << seconds<<endl;
        cout<<"---------------------------------------"<<endl;
    }

    bool isEarlier(DateTime d)
    {
        if (year < d.year)
            return true;
        if (year > d.year)
            return false;

        if (month < d.month)
            return true;
        if (month > d.month)
            return false;

        if (day < d.day)
            return true;
        if (day > d.day)
            return false;

        if (hours < d.hours)
            return true;
        if (hours > d.hours)
            return false;

        if (minutes < d.minutes)
            return true;
        if (minutes > d.minutes)
            return false;

        return seconds < d.seconds; 
}
};

int main() {
   
    DateTime d1, d2;

  
    d1.setvalue(15, 3, 2026);              
    d2.setvalue(14, 3, 2026, 10, 30, 0);   

    cout<<"======DATE-TIME COMPARISION======"<<endl;
    
    cout << "FIRST DATE-TIME:  "; d1.display();
    cout << "SECOND DATE-TIME: "; d2.display();

    
    if (d1.isEarlier(d2))
        cout << "FIRST DATE-TIME EARLIER THAN SECOND DATE-TIME !" << endl;
    else if (d2.isEarlier(d1))
        cout << "SECOND DATE-TIME EARLIER THEN FIRST DATE-TIME !" << endl;
    else
        cout << "BOTH HAVE EQUAL DATE-TIME !" << endl;

    return 0;
}