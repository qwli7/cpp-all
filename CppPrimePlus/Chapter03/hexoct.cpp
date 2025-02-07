#include <iostream>

//设定输出的进制类型
// hex 设定输出的进制类型为十六进制
// oct 设定输出的进制类型为八进制
int main() {
    int a = 42;
    int b = 42;
    int c={42};

    using namespace std;
    std::cout << "十进制 " << a <<  std::endl;
    std::cout << hex;
    std::cout << "十六进制" << b << std::endl;
    std::cout << oct;
    std::cout << "八进制" << c << std::endl;

    return 0;

}