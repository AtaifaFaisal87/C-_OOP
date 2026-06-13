#include <iostream>
#include<stdexcept>
#include <cstring>
using namespace std;

class Book
{

    char *title;
    int pages;

public:
    Book() : pages(1)
    {
        title = new char[4];
        strcpy(title, "N/R");
    }
    Book(char *t, int p)
    {

        if (t == nullptr || strlen(t) == 0 || p <= 0)
        {
            throw invalid_argument("INVALID!");
        }

        title = new char[strlen(t) + 1];
        strcpy(title, t);
        pages = p;
    }

    int getpages() { return pages; }
    char *gettitle() { return title; }

    void display()
    {
        cout << "|BOOK-TITLE:" << title << "|" << "PAGES:" << pages << "|" << endl;
    }

    ~Book()
    {
        delete[] title;
        cout << "BOOK DELETED" << endl;
    }
};

class librarian
{
    char *name;

public:
    librarian(char *n)
    {
        try
        {
            if (n == nullptr || strlen(n) == 0)
            {
                throw invalid_argument("INVALID!");
            }
        }
        catch (const invalid_argument &i)
        {
            cout << "EXCEPTION:" << i.what() << endl;
        }

        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }

    void displaylib()
    {
        cout << "|LIBRARIAN NAME:" << name << "|" << endl;
    }

    ~librarian()
    {
        delete[] name;
        cout << "LIBRARIAN DELETED" << endl;
    }
};

class library
{
    char *lname;
    librarian *libptr;
    Book bk[5];
    int bookcount;

public:
    library() : libptr(nullptr), bookcount(0)
    {
       lname = new char[4];
    strcpy(lname, "N/R");
    }
    library(char *name, librarian *l)
    {
        bookcount = 0;
        libptr = l;
        try
        {
            if (name == nullptr || strlen(name) == 0)
            {
                throw invalid_argument("INVALID!");
            }
        }
        catch (const invalid_argument &i)
        {
            cout << "EXCEPTION:" << i.what() << endl;
        }

        lname = new char[strlen(name) + 1];
        strcpy(lname, name);
    }

    void addbooks(char *t, int p)
    {
        try
        {
            if (bookcount >= 5)
            {
                throw invalid_argument("CAPCITY FULL!");
            }

            bk[bookcount] = Book(t, p);
            bookcount++;
            cout << "BOOK ADDED!" << endl;
        }
        catch (const invalid_argument &i)
        {
            cout << "EXCEPTION:" << i.what() << endl;
        }
    }

    void display()
    {
        try
        {
            if (bookcount == 0)
            {
                cout << "===LIBRARIAN===" << endl;
                libptr->displaylib();
                throw runtime_error("EMPTY!");
            }
        }
        catch (const runtime_error &r)
        {
            cout << "EXCEPTION:" << r.what() << endl;
        }

        cout << "====LIBRARY DETAILS====" << endl;
        cout << "----LIBRARIAN----" << endl;
        libptr->displaylib();
        cout << "----BOOK LIST-----" << endl;
        for (int i = 0; i < bookcount; i++)
        {
            bk[i].display();
        }
    }

    ~library()
    {
        delete lname;
        cout << "LIBRARYDELETED" << endl;
    }
};

int main()
{
    librarian l("ANWAR");
    library L1("NED UNIVERSITY", &l);
    L1.addbooks("LOR", 2);
    L1.addbooks("HP", 5);
    L1.addbooks("NR", 8);
    L1.addbooks("", 2);
    L1.display();
}
