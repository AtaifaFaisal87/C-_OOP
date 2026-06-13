#include <iostream>
using namespace std;

template <class T>
T findMax(T arr[], int size)
{
    T max = arr[0];

    for(int i = 1; i < size; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }

    return max;
}

int main()
{
    int arr[] = {4, 7, 2, 9, 5};

    cout << "Maximum Value = "
         << findMax(arr, 5);

    return 0;
}