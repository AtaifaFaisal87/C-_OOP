#include <iostream>
using namespace std;

class Book
{

    string title;
    int pages;

public:
    Book() : title("N/R"), pages(1) {}
    Book(string t, int p)
    {
    
            if (t == "" || p<=0)
            {
                throw invalid_argument("INVALID!");
            }

            title = t;
            pages = p;
        
    }

    int getpages() { return pages; }
    string gettitle() { return title; }

    void display()
    {
        cout << "|BOOK-TITLE:" << title << "|" << "PAGES:" << pages << "|" << endl;
    }
};

class librarian
{
    string name;

public:
    librarian() = default;
    librarian(string name)
    {
        try
        {
            if (name == "")
            {
                throw invalid_argument("INVALID!");
            }
        }
        catch (const invalid_argument &i)
        {
            cout << "EXCEPTION:" << i.what() << endl;
        }

        this->name = name;
    }

    void displaylib()
    {
        cout << "|LIBRARIAN NAME:" << name << "|" << endl;
    }
};

class library
{
    string lname;
    librarian *libptr;
    Book bk[5];
    int bookcount;

public:
    library() : libptr(nullptr), bookcount(0) {}
    library(string name, librarian *l)
    {
        bookcount=0;
        lname = name;
        libptr = l;
    }

    void addbooks(string t, int p)
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
            {    cout << "===LIBRARIAN===" << endl;
            libptr->displaylib();
            throw runtime_error("EMPTY!");
            }
        }
        catch (const runtime_error &r)
        {
            cout << "EXCEPTION:" << r.what() << endl;
        }

        cout<<"====LIBRARY DETAILS===="<<endl;
        cout<<"----LIBRARIAN----"<<endl;
        libptr->displaylib();
        cout<<"----BOOK LIST-----"<<endl;
        for(int i=0;i<bookcount;i++)
        {
            bk[i].display();
        }
    }
};

int main()
{
    librarian l("ANWAR");
    library L1("NED UNIVERSITY",&l);
    L1.addbooks("LOR",2);
    L1.addbooks("HP",5);
    L1.addbooks("NR",8);
    L1.addbooks("",2);
    L1.display();
    
}

