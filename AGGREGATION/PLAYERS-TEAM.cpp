#include <iostream>
using namespace std;

class Player
{
    string name;
    int age;

public:
    Player() : name("UNKNOWN"), age(1) {}
    Player(string n, int i) : name(n), age(i) {}

    void setname(string n) { name = n; }
    void setage(int a) { age = a; }

    string getname() const { return name; }
    int getage() const { return age; }

    void display()
    {
        cout << "|NAME:" << name << "|AGE:" << age << "|" << endl;
    }
};

class Team
{
    string team;
    Player *players[2];
    int playercount;

public:
    Team() : team("UNKNOWN"), playercount(0)
    {
        for (int i = 0; i < playercount; i++)
        {
            players[i] = nullptr;
        }
    }

    Team(string n)
    {
        playercount = 0;
        for (int i = 0; i < playercount; i++)
        {
            players[i] = nullptr;
        }
    }

    void addplayers(Player *p)
    {
        if (playercount < 2)
        {
            players[playercount] = p;
            playercount++;
            cout<<"PLAYER ADDED!"<<endl;
        }
        else
        {
            cout << "PLACE FULLED!" << endl;
        }
    }

    void removeplayer(string name)
    {
        if (playercount == 0)
        {
            cout << "VACANCY FULL" << endl;
            return;
        }

        for (int i = 0; i < playercount; i++)
        {
            if (players[i]->getname() == name)
            {
                for (int j = i; j < playercount - 1; j++)
                {
                    players[j] = players[j + 1];
                }
                players[--playercount] = nullptr;
                cout<<"PLAYER REMOVED!"<<endl;
                return;
            }
        }
    }

    void display()
    {
        if (playercount == 0)
        {
            cout << "VACANCY FULL" << endl;
            return;
        }

        for (int i = 0; i < playercount; i++)
        {
            players[i]->display();
        }
    }
};

int main()
{
    Player p1("SHAHID",27);
    Player p2("ZAIN",25);
    Player p3("MOHIB",22);

    Team t1("PAKISTAN");

    t1.addplayers(&p1);
    t1.addplayers(&p2);
    t1.addplayers(&p3);

    t1.display();
    t1.removeplayer("ZAIN");
    t1.display();
}