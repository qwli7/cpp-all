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
### ex1.11
提示用户输入两个整数，打印出这两个整数所指定范围内的所有整数；
[ch01/ex1.11.cpp](ch01/ex1.11.cpp)

### ex1.12
下面的 for 循环完成了什么功能？sum 的终值是多少？
```cpp
int sum = 0;
for(int i = -100; i <= 100; i++) {
  sum += i;
}
```
 完成了 -100 到 100 之间的所有整数，进行累加，sum 最终的值为 0

### ex1.13
使用 for 循环重做 1.9 1.10 1.11
```cpp
// 1.9
int sum = 0;
for(int i = 50; i <=100; i++ ){
  sum += i;
}
```

```cpp
//1.10
for(int i = 10; i >=0; i--) {
  std::cout << i << " ";
}
```

见[ch01/ex1.11.cpp](ch01/ex1.11.cpp)

### ex1.16
编写程序，从 cin 中读取一组数，输出其和;
```cpp
#include <iostream>

int main()
{
    int sum;
    int val;
    while (std::cin >> val)
    {
        sum += val;
    }
    std::cout << sum << std::endl;
    return 0;
}
```
输入数字，用空格分隔，如果要结束输入，可以按住 `Ctrl + Z` 然后再按回车（Windows），或者输入非数字+回车，也可结束

### ex1.17
```cpp
#include <iostream>

int main()
{
    int currVal = 0, val = 0;
    if (std::cin >> currVal)
    {
        int cnt = 1;
        while (std::cin >> val)
        {
            if (val == currVal)
            {
                ++cnt;
            }
            else
            {
                std::cout << currVal << " occurs "
                          << cnt << " times" << std::endl;
                currVal = val;
                cnt = 1;
            }
        }
        std::cout << currVal << " occurs "
                  << cnt << " times " << std::endl;
    }
    return 0;
}

```
如果输入的数都是相等的，那么只会输出一条语句，打印输入数的次数；如果没有重复的值，那么会输出所有数值只出现了一次；

### ex1.18
同 ex1.17

### ex1.19
处理输入的两个数大小不一致的情况
[ex1.11.cpp](ch01/ex1.11.cpp)

### ex1.20
利用 Sales_item.h 头文件，读取一组书籍销售记录，打印到标准输出中
[ch01/ex1.20.cpp](ch01/ex1.20.cpp)

## ex1.21
编写程序，读取两个 ISBN 的 Sales_item 对象，输出他们的和
[ch01/ex1.21.cpp](ch01/ex1.21.cpp)

## ex1.22
编写程序，读取多个具有相同 ISBN 的销售记录，输出所有记录的和
[ch01/ex1.22.cpp](ch01/ex1.22.cpp)

## ex1.23
读取多条销售记录，并统计每个 ISBN 对应的有几条销售记录
[ch01/ex1.23.cpp](ch01/ex1.23.cpp)

## ex1.24
输入表示多个ISBN 的多条销售记录来测试上一个程序， 每个 ISBN 的记录应该聚合在一起输出
[ch01/ex1.24.cpp](ch01/ex1.24.cpp)

## ex1.25
借助 Sales_item.h 头文件，编写并运行本书给出的书店程序
[ch01/ex1.25.cpp](ch01/ex1.25.cpp)