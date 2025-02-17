## ch01

### ex_1.6
解释下面的程序片段是否合法
```cpp
std::cout << "The sum of " << v1;
  << " and " << v2;
  << " is " << v1 + v2 << std::endl;
```
不合法 `<< " and " << v2;` 和 `<< " is " << v1 + v2 << std::endl;` 不是一条有效的 `c++` 语句

### ex1.7 
编译一个包含不正确的嵌套注释的程序，观察编译器返回的错误信息
```cpp
#include <iostream>

int main()
{
    int a;
    int b;
    std::cin >> a >> b;
    std::cout << "The sum of ";
    std::cout << a;
    /*std::cout << " and /*""*/"*/;  //编译失败
    std::cout << b;
    std::cout << " is ";
    std::cout << a + b << std::endl;
    return -1;
}
```
### ex1.8
指出下列哪些输出语句是合法的（如果有的话）
```cpp
std::cout  << "/*";          //合法
std::cout << "*/";           //合法
std::cout << /* "*/" */;     //不合法
std::cout << /* "*/" /* "/*" */; //不合法
```
### ex1.9
while 循环计算 50-100 之间数的和
```cpp
#include <iostream>
int main()
{
    int i = 50;
    int sum = 0;
    while (i <= 100)
    {
        sum += i++;
    }
    std::cout << sum << std::endl;
    return 0;
}
```
### ex1.10
循环打印出10-0之间的数字
```cpp
#include <iostream>

int main()
{
    int i = 10;
    while (i >= 0)
    {
        std::cout << i-- << " ";
    }
    return 0;
}

```

