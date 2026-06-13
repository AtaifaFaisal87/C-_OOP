#include <iostream>
using namespace std;

// ================= PARENT CLASS 1 =================
class Worker
{
public:
    void work()
    {
        cout << "Working as an employee" << endl;
    }
};

// ================= PARENT CLASS 2 =================
class Freelancer
{
public:
    void work()
    {
        cout << "Working independently" << endl;
    }
};

// ================= CHILD CLASS =================
class HybridWorker : public Worker, public Freelancer
{
public:
    // CHANGE:
    // We OVERRIDED work() in HybridWorker
    // to remove ambiguity between Worker::work()
    // and Freelancer::work()

    void work()
    {
        cout << "Working both ways" << endl;
    }
};

int main()
{
    HybridWorker h;

    // CHANGE:
    // Previously h.work() caused ambiguity error
    // because both parent classes had work()

    // Now HybridWorker has its own work()
    // so ambiguity is resolved

    h.work();

    // OPTIONAL:
    // We can still access parent versions
    // using scope resolution operator

    h.Worker::work();
    h.Freelancer::work();

    return 0;
}