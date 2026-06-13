#include<iostream>
using namespace std;

class date{
public:
    int day;
    int year;

    void display()
    {
        cout<<day<<"-"<<year<<endl;
    }
};

class month{

    public:
    date first;

    void display()
    {
        first.display();
    }
};

int main(){
   
    month m1;
    m1.first.day=9;
    m1.first.year=2007;
    m1.display();


    return 0;
}


