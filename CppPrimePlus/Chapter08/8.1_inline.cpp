#include <iostream>

//演示内联函数

inline double square(double x) {
    return x * x;
}

//通过宏定义来提供内联代码的原始实现
#define SQUARE2(x) x*x

int main() {

    using namespace std;

    double a, b;
    double c = 13.0;

    a = square(5.0);
    b = square(4.5+7.5);

    cout << "a = " << a  << ", b= " <<b << "\n";
    cout << "c = " << c;
    cout << ", c squared = " << square(c++) << "\n";
    cout << "Now c = " << c << "\n";

    return 0;
}