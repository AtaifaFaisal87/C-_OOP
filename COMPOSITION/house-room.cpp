#include <iostream>
using namespace std;

class Room
{
    float area;
    string place;

public:
    Room() : area(1.0), place("UNKNOWN") {}
    Room(string p, float a) : place(p), area(a) {}

    void setplace(string p) { place = p; }
    void setarea(float a) { area = a; }

    string getplace() const { return place; }
    float getarea() const { return area; }

    void display()
    {
        cout << "|PLACE:" << place << "|AREA:" << area << "|" << endl;
    }
};

class House
{
    string owner;
    Room rooms[3];
    int rcount;

public:
    House() : owner("UNKNOWN"), rcount(0) {}
    House(string o)
    {
        owner = o;
        rcount = 0;
    }

    void addrooms(string p, float a)
    {
        if (rcount < 3)
        {
            rooms[rcount] = Room(p, a);
            rcount++;
            cout << "ROOM ADDED" << endl;
        }
        else
        {
            cout << "HOUSE FULL!" << endl;
        }
    }

    void removeroom(string place)
    {
        if (rcount == 0)
        {
            cout << "NO ROOMS" << endl;
            return;
        }

        for (int i = 0; i < rcount; i++)
        {
            if (rooms[i].getplace() == place)
            {
                for (int j = i; j < rcount - 1; j++)
                {
                    rooms[j] = rooms[j + 1];
                }

                rcount--;
                cout << "ROOM REMOVED!" << endl;
                return;
            }
        }

        cout<<"ROOM NOT FOUND!"<<endl;
    }

    void display()
    {
        if (rcount == 0)
        {
            cout << "NO ROOMS" << endl;
            return;
        }

        cout << "====ROOM LIST=====" << endl;
        for (int i = 0; i < rcount; i++)
        {
            rooms[i].display();
        }
    }
};

int main()
{
    House h1("ATAIFA");
    h1.addrooms("livingroom", 21.3);
    h1.addrooms("diningroom", 16.3);
    h1.addrooms("bedroom", 31.3);
    h1.addrooms("washroom", 1.3);

    h1.display();

    h1.removeroom("livingroom");
    h1.display();

    return 0;
}