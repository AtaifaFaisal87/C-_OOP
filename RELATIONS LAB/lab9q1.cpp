#include <iostream>
using namespace std;

class Node
{
public:
    string data;
    int priority;

    Node() : data(""), priority(0) {}
    Node(string d, int p) : data(d), priority(p) {}
};

class Priority_Queue
{
    Node arr[5];
    int size;

public:
    Priority_Queue() : size(0) {}

    void Enqueue(string d, int p)
    {
        if (size >= 5)
        {
            cout << "QUEUE FULL\n";
            return;
        }

        Node newNode(d, p);

        int i = size - 1;
        while (i >= 0 && arr[i].priority < p)
        {
            arr[i + 1] = arr[i];
            i--;
        }

        arr[i + 1] = newNode;
        size++;

        cout << "INSERTED\n";
    }

    void Dequeue()
    {
        if (size == 0)
        {
            cout << "QUEUE EMPTY\n";
            return;
        }

        cout << "REMOVED: " << arr[0].data
             << " | Priority: " << arr[0].priority << endl;

        for (int i = 0; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }

        size--;
    }

    void display()
    {
        if (size == 0)
        {
            cout << "QUEUE EMPTY\n";
            return;
        }

        cout << "PRIORITY QUEUE:\n";
        for (int i = 0; i < size; i++)
        {
            cout << arr[i].data << " (" << arr[i].priority << ")\n";
        }
    }
};

int main()
{
    Priority_Queue pq;

    pq.Enqueue("Task A", 2);
    pq.Enqueue("Task B", 5);
    pq.Enqueue("Task C", 1);
    pq.Enqueue("Task D", 4);

    pq.display();

    pq.Dequeue();
    pq.display();

    return 0;
}