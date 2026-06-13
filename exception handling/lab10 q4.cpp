#include<iostream>
#include<stdexcept>
using namespace std;

class dateexception{
    string msg;
    public:

    dateexception(string msg)
    {
        this->msg=msg;
    }

    string what()const
    { return msg;}


};

class Date{
    int day;
    int month;
    int year;
    public:
    void setdate()
    {
        cout<<"ENTER DAY:";
        cin>>day;
        if(day<=0 || day>31)
        {
            throw dateexception("INVALID DATE!");
        }

        cout<<"ENTER MONTH:";
        cin>>month;

            if(month<=0 || month>12)
        {
            throw dateexception("INVALID MONTH!");
        }

        cout<<"ENTER YEAR:";
        cin>>year;
            if(year<=0)
        {
            throw dateexception("INVALID YEAR!");
        }   

        cout<<day<<":"<<month<<":"<<year<<endl;
    }
};

int main()
{
Date date; try {
date.setdate();
}
catch(const dateexception e)
{ cout << e.what();}
 return 0;
}