#include <iostream>
using namespace std;

class Book
{
    string title;
    string author;

public:
    Book()
    {
        title = "UNKNOWN";
        author = "UNKNOWN";
    }
    Book(string a, string t)
    {
        title = t;
        author = a;
    }

    void settitle(string t) { title = t; }
    void setauthor(string a) { author = a; }

    string gettitle() { return title; }
    string getauthor() { return author; }

    void display()
    {
        cout << "|TITLE:" << title << "|AUTHOR:" << author << "|" << endl;
    }
};

class library
{
    string libname;
    Book *bk[5];
    int bookcount;

public:
    library()
    {
        libname = "unknown";
        bookcount = 0;

        for (int i = 0; i < 5; i++)
        {
            bk[i] = nullptr;
        }
    }
    library(string name) : libname(name), bookcount(0)
    {
        for (int i = 0; i < 5; i++)
        {
            bk[i] = nullptr;
        }
    }

    void addbooks(Book *b)
    {
        if (bookcount < 5)
        {
            bk[bookcount] = b;
            bookcount++;
        }
        else
        {
            cout << "LIBRARY FULL!" << endl;
        }
    }

    void removebooks(string bname)
    {
        if (bookcount == 0)
        {
            cout << "EMPTY" << endl;
        }

        else
        {
            for (int i = 0; i < bookcount; i++)
            {
                if (bk[i]->gettitle() == bname)
                {
                    for (int j = i; j < bookcount - 1; j++)
                    {
                        bk[j] = bk[j + 1];
                    }

                    bk[--bookcount] = nullptr;

                    cout << "BOOK REMOVED!" << endl;
                    return;
                }
            }
        }
    }

    void display()
    {
        cout << "BOOK LIST" << endl;
        for (int i = 0; i < bookcount; i++)
        {
            bk[i]->display();
        }
    }
};

int main()
{
    string lname;
    cout << "ENTER NAME OF LIBRARY:";
    cin >> lname;
    library L1(lname);

    int n;
    do
    {
        cout << "ENTER NUMBER OF BOOKS(1-5)";
        cin >> n;
        if (n <= 0 || n > 5)
        {
            cout << "INVALID!" << endl;
        }
    } while (n <= 0 || n > 5);

    Book B[n];
    string bauthor;
    string btitle;

    for (int i = 0; i < n; i++)
    {
        cout << "ENTER NAME OF AUTHOR:";
        cin >> bauthor;
        cout << "ENTER BOOK TITLE:";
        cin >> btitle;

        B[i] = Book(bauthor, btitle);
        L1.addbooks(&B[i]);
    }

    L1.display();

    return 0;
}