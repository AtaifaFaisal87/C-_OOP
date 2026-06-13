#include <iostream>
using namespace std;

class Item
{
    string name;
    double price;

public:
    Item() : name("UNKNOWN"), price(0.0) {}
    Item(string n, double p) : name(n), price(p) {}

    void setname(string n) { name = n; }
    void setprice(double p) { price = p; }

    string getname() { return name; }
    double getprice() { return price; }

    friend ostream &operator<<(ostream &o, const Item &i)
    {
        o << "|NAME:" << i.name << "|PRICE:" << i.price << "|" << endl;
        return o;
    }
};

class Order
{
    string customer;
    Item items[5];
    int itemcount;

public:
    Order() : customer("UNKNOWN"), itemcount(0) {}
    Order(string c) : customer(c), itemcount(0) {}

    void additem(string name, double price)
    {
        if (itemcount < 5)
        {
            items[itemcount] = Item(name, price);
            itemcount++;
            cout << "ITEM ADDED!" << endl;
        }
        else
        {
            cout << "ORDER CANT BE TAKEN!" << endl;
        }
    }

    void removeitem(string name)
    {
        if (itemcount == 0)
        {
            cout << "NO ITEMS ORDERED!";
            return;
        }
        for (int i = 0; i < itemcount; i++)
        {
            if (items[i].getname() == name)
            {
                for (int j = i; j < itemcount - 1; j++)
                {
                    items[j] = items[j + 1];
                }
                --itemcount;
                cout << "ITEM REMOVED" << endl;
                return;
            }
        }
        cout << "ITEM NOT FOUND!" << endl;
    }

    int getitemcount( )const {return itemcount;}

    void calculatetotal( )
    {
        double sum=0;

        for(int i=0;i<itemcount;i++)
        { 
            sum+=items[i].getprice();
        }
        cout<<"THE TOTAL IS:"<<sum<<endl;
    }

    friend ostream& operator<<(ostream& o,const Order &r)
    {
     o<<"CUSTOMER:"<<r.customer<<endl;
     for(int i=0;i<r.getitemcount();i++)
     {
          o<<r.items[i];
     }
     
     return o;
    }
};

int main( )
{
    Order c1("hamza");
    c1.additem("chocolate",3.4);
    c1.additem("ICECREAM",124);
    c1.additem("SHAKE",30.3);
    c1.additem("RUBBER",356);
    c1.additem("WIG",39.4);
    c1.additem("SHARPNER",53.4);

    cout<<c1;
    c1.calculatetotal();
    
    c1.removeitem("chocolate");
    cout<<c1;
}