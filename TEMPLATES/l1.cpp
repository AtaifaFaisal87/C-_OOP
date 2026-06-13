#include <iostream>
using namespace std;

// Function template to find maximum value in an array
template <typename T>
T findMax(T arr[], int size) {
    if (size <= 0) return T();
    
    T maxVal = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

int main() {
    // Test with integer array
    int intArr[] = {10, 45, 23, 56, 34, 89, 12};
    int intSize = sizeof(intArr) / sizeof(intArr[0]);
    cout << "Maximum in integer array: " << findMax(intArr, intSize) << endl;
    
    // Test with double array
    double doubleArr[] = {1.5, 3.2, 2.8, 5.1, 4.9};
    int doubleSize = sizeof(doubleArr) / sizeof(doubleArr[0]);
    cout << "Maximum in double array: " << findMax(doubleArr, doubleSize) << endl;
    
    // Test with character array
    char charArr[] = {'a', 'z', 'm', 'b', 'x'};
    int charSize = sizeof(charArr) / sizeof(charArr[0]);
    cout << "Maximum in character array: " << findMax(charArr, charSize) << endl;
    
    return 0;
}
