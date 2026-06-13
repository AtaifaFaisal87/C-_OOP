#include <iostream>
using namespace std;

class Counter
{
private:
    int value;

public:
   
    Counter();

 
    void Increment() { value++; }
    void Decrement() { value--; }

    void SetValue(int v) { value = v; }
    int GetValue() { return value; }

    // FRIEND FUNCTION
    friend void Reset(Counter &c);
};


Counter::Counter()
{
    value = 0;
}

// FRIEND FUNCTION (QUESTION 3)
void Reset(Counter &c)
{
    c.value = 0;
}

int main()
{
    Counter c;

    c.Increment();
    c.Increment();
    c.Decrement();

    cout << "VALUE: " << c.GetValue() << endl;

    Reset(c);

    cout << "AFTER RESET: " << c.GetValue();

    return 0;
}
