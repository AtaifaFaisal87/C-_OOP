#include <iostream>
#include <vector>
using namespace std;

template <class T>
void display(vector<T> &v)
{
    cout << "DISPLAYING THIS VECTOR" << endl;
    for (int i = 0; i < v.size(); i++) // SIZE( ) TELSS WHAT THE NAME SUGGESTS
    {
        cout << v[i] << " ";    // 1 2 3 4
        // cout << v.at(i) << " "; // PRINTS ONE ELEMENT TWICE 1 1 2 2 3 3 4 4
    }
    cout << endl;
}
int main()
{
    //================WAYS TO CREATE VECTOR=================
    int ele, size;
    vector<int> vect1;
     display(vect1);

    vector<char> vec2(4);    // 4 element character vector
    vec2.push_back('5');
    display(vec2);
    vector<char> vec3(vec2); // 4 element character vector from vec2
    display(vec3);
    vector<int> vec4(6, 3);     // 6-element vector of 3s
   display(vec4);
    
    // cout<<"ENTER THE SIZE OF YOUR VECTOR:";
    // cin>>size; //WE CAN ALSO SET OUR OWN SIZE

    // for (int i=0; i < size; i++)
    // {
    //     cout<<"ENTER ELEMENTS TO ADD TO THIS VECTOR:";
    //     cin>>ele;
    //      vect1.push_back(ele); //TO ENTER ELEMENTS IN THE VECTOR
    // }

    // display(vect1);
    // // vect1.pop_back();  //TO REMOVE AN ELEMENT (LIFO)
    // vector<int>::iterator iter = vect1.begin();
    // vect1.insert(iter, 3, 566); // TO ENTER AN ELEMENT BEFORE FIRST ELEMENT
    // // WE NEED TO UPDATE ITER EVERY TIME
    // //  vect1.insert(iter+1,566);  //TO ENTER AN ELEMENT BEFORE SECOND ELEMENT
    // //  vect1.insert(iter+2,566);  //TO ENTER AN ELEMENT BEFORE THIRD ELEMENT
    // display(vect1);
}