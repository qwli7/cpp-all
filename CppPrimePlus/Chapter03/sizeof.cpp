#include <iostream>

// 使用sizeof 查看数据类型占用的字节数
int main() {
    using namespace std;
    std::cout << "int " << sizeof(int) << std::endl;
    std::cout << "short " << sizeof(short) << std::endl;
    std::cout << "long " << sizeof(long) << std::endl;
    std::cout << "float " << sizeof(float) << std::endl;
    std::cout << "double " << sizeof(double) << std::endl;
    std::cout << "char " << sizeof(char) << std::endl;
    std::cout << "bool " << sizeof(bool) << std::endl;
    std::cout << "long long " << sizeof(long long) << std::endl;
    return 0;
}