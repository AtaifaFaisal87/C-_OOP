#include <iostream>
#include <stdexcept>
using namespace std;

class Stack
{
    // int arr[5];
    int *arr;
    int top;

public:
    Stack() { 
        top = -1; 
       arr=new int[5];
    }

    void Push(int x)
    {
        if (top == 4)
        {
            throw overflow_error("STACK OVERFLOW!");
        }
        // top++;
        // arr[top]=x;    ghlt hai segmentation fault
        // top++;
        top++;    //DOBARA CALL KRNE PR AUTOMATIC ++ AND NEW INDEX PR VALUE SAVE
        arr[top] = x;
        cout << "THE PUSHED ELEMENT IN STACK IS:" << x << endl;
    }

    void Pop( )
    {
        if (top == -1)
        {
            throw underflow_error("STACK UNDER-FLOW!");
        }

        int deletevalue = arr[top];
        top--;

        cout << "THE ELEMENT POPED OUT OF STACK IS:" << deletevalue << endl;
    }

    void display( )
    {
        if(top==-1)
        {
            throw underflow_error("STACK EMPTY");
        }
           
        cout<<"STACK ELEMENTS"<<endl;
        for(int i=top;i>0;i--)
        {
            cout<<arr[top]<<endl;
        }

    }

    ~Stack( ){
        delete[ ] arr;
    }
};

int main( )
{
    Stack s;
    try{
       s.Push(1);
       s.Push(2);
       s.Push(3);
       s.Push(4);
       s.Push(5);

       s.Push(6);//over flow
    }
    catch(const overflow_error &l)
    {
        cout<<"EXCEPTION:"<<l.what( )<<endl;
    }
    
    try{
       s.Pop();
       s.Pop();
       s.Pop();
       s.Pop();
       s.Pop();

       s.Pop();//under flow
    }
    catch(const underflow_error &l)
    {
        cout<<"EXCEPTION:"<<l.what( )<<endl;
    }
    
    return 0;
}