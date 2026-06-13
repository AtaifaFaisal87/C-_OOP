#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> v;

    cout << "Initial state:\n";
    cout << "Size: " << v.size() << " Capacity: " << v.capacity() << endl;

    // ================= PUSH BACK =================
    cout << "\nAdding elements...\n";
    v.push_back(4);
    v.push_back(5);
    v.push_back(4);

    cout << "Vector: ";
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;

    // ================= INSERT =================
    cout << "\nInserting 90 at index 2...\n";
    v.insert(v.begin() + 2, 90);

    cout << "Vector: ";
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;

    // ================= ERASE =================
    cout << "\nErasing index 2...\n";
    v.erase(v.begin() + 2);

    cout << "Vector: ";
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;

    // ================= SORT ASCENDING =================
    cout << "\nSorting in increasing order...\n";
    sort(v.begin(), v.end());

    cout << "Vector: ";
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;

    // ================= SORT DESCENDING =================
    cout << "\nSorting in decreasing order...\n";
    sort(v.begin(), v.end(), greater<int>());    
    //  sort(v.rbegin(), v.rend());

    cout << "Vector: ";
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;

    // ================= POP BACK =================
    cout << "\nUsing pop_back...\n";
    v.pop_back();

    cout << "Vector: ";
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;

    // ================= UPDATE =================
    cout << "\nUpdating index 1 to 1...\n";
    if (v.size() > 1)
        v[1] = 1;

    cout << "Vector: ";
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;

    // ================= EMPTY CHECK =================
    cout << "\nChecking empty...\n";
    if (v.empty())
        cout << "Vector is empty\n";
    else
        cout << "Vector is NOT empty\n";

    // ================= CLEAR =================
    cout << "\nClearing vector...\n";
    v.clear();

    cout << "Size: " << v.size() << " Capacity: " << v.capacity() << endl;

    //FIND AND BINARY SEARCH
    return 0;
}