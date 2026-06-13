#include <iostream>
#include <stdexcept>
using namespace std;

class outofbounds :public runtime_error
{
public:
    outofbounds(const string &msg) : runtime_error(msg) {}

};

class invalid_input :public runtime_error
{
public:
    invalid_input(const string &msg) : runtime_error(msg) {}
};

int main()
{
    double arr[4] = {0.0, 0.0, 0.0, 0.0};
    double numerator, denominator;
    int index;

    cout << "ENTER INDEX:";
    cin >> index;

    try
    {

        // if (index >= 4)
        // {
        //     throw outofbounds("ERROR: Array out of bounds!");
        //     // throw "ERROR: Array out of bounds!";
        // }

        // if (index < 0)
        // {
        //     throw outofbounds("ERROR: Array out of bounds!");
        //     // throw "ERROR: Array out of bounds!";
        // }

        if (index < 0 || index>=4)
        {
            throw outofbounds("ERROR: Array out of bounds!");
            // throw "ERROR: Array out of bounds!";
        }

        cout << "ENTER NUMERATOR:";
        cin >> numerator;

        cout << "ENTER DENOMINATOR:";
        cin >> denominator;

        if (denominator == 0)
        {
            throw invalid_input("ZERO CANT BE IN DENOMINATOR");
            // throw "ERROR";

        }

        
            arr[index] = numerator / denominator;
            cout << "THE ANSWER IS:" << arr[index];
    }

    catch(const outofbounds &o)
    {
        cout<<o.what();
    }
    catch(const invalid_input  &i)
    {
        cout<<i.what();
    }
}

class AbsoluteZeroViolation : public invalid_argument {
    string msg;
public:
    AbsoluteZeroViolation(string msg)
        : invalid_argument(msg) {}

        const char* what( ) const noexcept override {
            return msg.c_str(); 
        }
};
