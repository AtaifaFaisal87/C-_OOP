#include <iostream>
using namespace std;

template<typename T>
T Power(T x, int y) {
    T result = static_cast<T>(1);
    bool negative = (y < 0);
    if (negative) {
        y = -y;
    }
    for (int i = 0; i < y; ++i) {
        result *= x;
    }
    return negative ? static_cast<T>(1) / result : result;
}

int main() {
    cout << "Power(2, 3) = " << Power(2, 3) << '\n';
    cout << "Power(1.5, 4) = " << Power(1.5, 4) << '\n';
    cout << "Power(2.0, -3) = " << Power(2.0, -3) << '\n';
    return 0;
}
