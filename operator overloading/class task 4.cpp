#include <iostream>
using namespace std;

class Time {
private:
    int hours;
    int minutes;

    void normalize() {
        if (minutes >= 60) {
            hours += minutes / 60;
            minutes = minutes % 60;
        }

        if (minutes < 0) {
            hours -= 1 + (-minutes / 60);
            minutes = 60 + (minutes % 60);
        }

        if (hours < 0) {
            hours = minutes = 0;
        }
    }

public:
    // Constructor
    Time(int h = 0, int m = 0) {
        hours = h;
        minutes = m;
        normalize();
    }

    // + operator 
    Time operator+(const Time& t) {
        this->hours += t.hours;
        this->minutes += t.minutes;
        this->normalize();
        return *this;
    }

    // - operator 
    Time operator-(const Time& t) {
        int total1 = this->hours * 60 + this->minutes;
        int total2 = t.hours * 60 + t.minutes;

        int diff = (total1 > total2) ? (total1 - total2) : (total2 - total1);

        this->hours = diff / 60;
        this->minutes = diff % 60;

        return *this;
    }

    // > operator
    bool operator>(const Time& t) {
        if (hours == t.hours)
            return minutes > t.minutes;
        return hours > t.hours;
    }

    // << operator
    friend ostream& operator<<(ostream& out, const Time& t) {
        out << (t.hours < 10 ? "0" : "") << t.hours << ":"
            << (t.minutes < 10 ? "0" : "") << t.minutes;
        return out;
    }
};

// Driver Code
int main() {
    Time t1(2, 50);
    Time t2(1, 30);

    cout << "T1: " << t1 << endl;
    cout << "T2: " << t2 << endl;

    cout << "Sum: " << (t1 + t2) << endl;
    cout << "Difference: " << (t1 - t2) << endl;

    if (t1 > t2)
        cout << "T1 is greater\n";
    else
        cout << "T2 is greater\n";

    return 0;
}