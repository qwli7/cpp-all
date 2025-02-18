#include <iostream>

// 编写代码，分别更改指针的值以及指针所指向对象的值
int main()
{
    int a = 10, *ptr;
    int b = 100;
    ptr = &a;                              // 指针指向了a的地址
    std::cout << "a = " << a << std::endl; // 输出 a 的值
    std::cout << "b = " << b << std::endl; // 输出 b 的值
    *ptr = 200;                            // 修改 a 的值为 200
    std::cout << "a = " << a << std::endl; // 输出 a 的值
    ptr = &b;                              // 将指针指向 b 的地址

    *ptr = 300;                            // 修改 b 的值为 300
    std::cout << "b = " << b << std::endl; // 输出 b 的值

    return 0;
}
