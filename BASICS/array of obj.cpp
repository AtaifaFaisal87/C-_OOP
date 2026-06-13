#include<iostream>
using namespace std;

class employee{

    int id;
    string name;
    string job;
    static int empcount;

    public:

    void setemployee(int eid,string ename,string ejob)
    {
        id=eid;
        name=ename;
        job=ejob;
    }

    void addemployee(employee o[]);
    void displayemployee(employee o[]);
    void getcount(){

        cout<<"THE TOTAL EMPLOYEE COUNT IS="<<empcount;
    }


};

int employee:: empcount=0;

    void employee:: addemployee(employee o[])
    {
        int num;
        cout<<"ENTER NUMBER OF EMPLOYEES YOU WANNA ADD=";
        cin>>num;
        int eid;
        string n;
        string job;

        for(int i=0;i<num;i++)
        {
            cout<<"ENTER EMPLOYEE ID=";
            cin>>eid;
            cout<<"ENTER EMPLOYEE NAME=";
            cin>>n;
            cout<<"ENTER EMPLOYEE JOB=";
            cin>>job;

            o[i].setemployee(eid,n,job);
            empcount++;

        }
        
    }

void employee:: displayemployee(employee o[]){

    cout<<"---EMPLOYEE LIST---"<<endl;
    for(int i=0;i<empcount;i++)
    {
        cout<<"ID:"<<o[i].id<<endl<<"NAME:"<<o[i].name<<endl<<"-------------"<<endl;
        
    }
 getcount();   
}

int main()
{

    employee e[50];
    employee obj;
    obj.addemployee(e);
    obj.displayemployee(e);

  return 0;
}