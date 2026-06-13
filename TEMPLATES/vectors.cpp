#include<iostream>
using namespace std;

template<class T>
class vector{
 public:
 T *arr;
 int size;

 vector(int s)
 {
   size=s;
   arr=new T[size];
 }


 T dotproduct(vector &v)
 {
    T sum=0;
    for(int i=0;i<size;i++)
    {
        sum+=this->arr[i] *v.arr[i];
    }

    return sum;
 }
};

int main()
{
    vector <float> v(3);
    v.arr[0]=1.3;
    v.arr[1]=4.3;
    v.arr[2]=2.7;
    vector <float> v1(3);
    v1.arr[0]=1.3;
    v1.arr[1]=4.3;
    v1.arr[2]=2.7;
    float sum;
    sum=v.dotproduct(v1);
    cout<<sum;

}