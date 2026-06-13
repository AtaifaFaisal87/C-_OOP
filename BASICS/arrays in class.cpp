#include <iostream>
using namespace std;

class shop{

    int itemid[10];
    int itemprice[100];
    int counter;

    public:

    void initcounter(void){counter=0;}
    void getcounter(void)
    {
        cout<<"THE CURRENT COUNT IS="<<counter<<endl;
    }
    void setprice(void);
    void settingitems(void);
    void displayprice(void);


};

void shop::setprice(){

 cout<<"ENTER ID OF YOUR ITEM NO"<<counter+1 <<"=";
 cin>>itemid[counter];

 cout<<"ENTER YOUR PRICE=";
 cin>>itemprice[counter];

 counter++;
}

void shop :: settingitems(void){
    int num;
    cout<<"ENTER THE NUMBER OF ITEMS=";
    cin>>num;
    
    initcounter();

    for(int i=0;i<num;i++)
    {
        setprice();
        getcounter();
    }
}

void shop::displayprice(){

    for(int i=0;i<counter;i++)
    {
        cout<<"THE PRICE OF ITEM WITH ID"<<itemid[i]<<"IS ="<<itemprice[i];
    }
}

int main()
{
    shop dukaan;
    dukaan.settingitems();
    dukaan.displayprice();

    return 0;
}