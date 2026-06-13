#include<iostream>
using namespace std;

template<class T>
T findmax(T arr[],int size)
{
    T max=arr[0];
    for(int i=0;i<size;i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
        }
    }

    return max;

}

int main()
{
    int intarr[5]={1,2,3,4,5};
    cout<<"MAXIMUM VALUEIN ARRAY IS:"<<findmax(intarr,5)<<endl;
    float floatarr[5]={1.1,2.2,3.3,4.4,5.5};
    cout<<"MAXIMUM VALUEIN ARRAY IS:"<<findmax(floatarr,5)<<endl;
}