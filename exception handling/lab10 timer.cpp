#include <iostream>
#include <stdexcept>
using namespace std;

class Timer
{
    int hours, minutes, seconds;

public:
    Timer(int h = 0, int m = 0, int s = 0) : hours(h), minutes(m), seconds(s) {}

    void Tick()
    {
        seconds++;
        if (seconds == 60)
        {
            seconds = 0;
            minutes++;
            if (minutes == 60)
            {
                minutes = 0;
                hours++;
                if (hours == 24)
                {
                    throw overflow_error("TIMER OVERFLOW");
                }
            }
        }
    }

    void display()
    {
        cout << hours << ":" << minutes << ":" << seconds << endl;
    }
};

int main()
{
    // THE ORIGRNAL WAY THE PROGRAM WILL EXECUTE 86,000
    //  ITERATIONS AND THEN THE EXCEPTION WILL BE SHOWN
    //  Timer t;

    // try{
    //     while(true)
    //     {
    //         t.display();
    //         t.Tick();
    //     }
    // }

    // catch(const overflow_error&o)
    // {
    //     cout<<"EXCEPTION:"<<o.what();
    // }

    // //TESTING
    Timer t(23, 59, 58);

    try
    {
        t.display();
        t.Tick();

        t.display();
        t.Tick();

        t.display();
        t.Tick(); //overflow happens here
    }
    catch (const overflow_error &o)
    {
        cout << "EXCEPTION: " << o.what() << endl;
    }
}