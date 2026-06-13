#include<iostream>
using namespace std;

template <class T>
T power(T x,int times)
{
    T product=1;
    for(int i=0;i<times;i++)
    {
      product=product*x;
    }

    return product;
}

int main( )
{
    int a=4;
    cout<<"THE POWER OF a ^ 3:"<<power(a,3)<<endl;
    
    float b=5.7;
    cout<<"THE POWER OF b^ 3:"<<power(b,3)<<endl;

}
