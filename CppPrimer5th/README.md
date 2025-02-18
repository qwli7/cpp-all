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
[ex1.11.cpp](ch01/ex_1.11.cpp)

### ex1.20
利用 Sales_item.h 头文件，读取一组书籍销售记录，打印到标准输出中
[ch01/ex1.20.cpp](ch01/ex_1.20.cpp)

### ex1.21
编写程序，读取两个 ISBN 的 Sales_item 对象，输出他们的和
[ch01/ex1.21.cpp](ch01/ex_1.21.cpp)

### ex1.22
编写程序，读取多个具有相同 ISBN 的销售记录，输出所有记录的和
[ch01/ex1.22.cpp](ch01/ex_1.22.cpp)

### ex1.23
读取多条销售记录，并统计每个 ISBN 对应的有几条销售记录
[ch01/ex1.23.cpp](ch01/ex_1.23.cpp)

### ex1.24
输入表示多个ISBN 的多条销售记录来测试上一个程序， 每个 ISBN 的记录应该聚合在一起输出
[ch01/ex1.24.cpp](ch01/ex_1.24.cpp)

### ex1.25
借助 Sales_item.h 头文件，编写并运行本书给出的书店程序
[ch01/ex1.25.cpp](ch01/ex_1.25.cpp)

## ch02
### ex2.1
一般来说 short < int < long < long long(C++11)，它们表示的范围不同；C++标准要求 
- short 表示的大小最多只能和 int 相等，而不能超过 int
- int 表示的大小最多只能和 long 相等，而不能超过 long 
- long 表示的大小最多只能和 long long 相等，而不能超过 long long

无符号和有符号的区别
- 无符号表示的范围比有符号大，拿 int 来举例子，假设 int 所占的字节数为 4，那么无符号最多能表示的范围是 0 到 2^32-1，而有符号的范围是 -2^31 到 2^31-1；大小小了一半；
- 对于 char 类型，无符号表示的范围是 0 到 255，而有符号的范围是 -128 到 127；

float 和 double 分别表示单精度浮点型了双精度浮点型，两者的精确度不一样；

### ex2.2
计算按揭贷款时，对于利率、本金和付款分别应该选用何种数据类型？
- 利率选 double
- 本金通常是一个金额比较大的数值，可以选用 double 或者 long double
- 付款每月还款金额，可以选用 double 或者 long double

### ex2.3
读程序，写结果
```cpp
#include <iostream>

int main()
{
    unsigned u = 10, u2 = 42;         // unsigned int 类型，当前机器4个字节，范围是 0-2^32-1
    std::cout << u2 - u << std::endl; // 没有溢出 32
    std::cout << u - u2 << std::endl; // 溢出，2^32-(42-10)  -> 4,294,967,264

    int i = 10, i2 = 42;              // int 类型，当前机器4个字节，范围是 -2^31-1 到 2^31-1
    std::cout << i2 - i << std::endl; // 没有溢出 32
    std::cout << i - i2 << std::endl; // 没有溢出 -32
    std::cout << i - u << std::endl; // 0  
    std::cout << u - i << std::endl;  // 0
    return 0;
}
```

### ex2.4
不要混用带符号类型和无符号类型的数据

### ex2.5
指出下述字面值的数据类型并说明每一组内几种字面值的区别
**如果不加 F，默认的浮点型就是double**
- （a） 'a', L'a', "a", L"a"    // 字符  宽字符a， 字符串a，宽字符串a
- （b） 10, 10u, 10L, 10uL, 012, 0xC  //数字10， 无符号数字10，long类型10， 无符号long类型10，八进制12， 16进制C
- （c） 3.14, 3.14f, 3.14L             //double 类型3.14， 浮点型 3.14，long double 类型 3.14
- （d） 10, 10u, 10., 10e-2           // 数字10，无符号int 10，double 类型10.0，double型浮点数

### ex2.6
下面两组定义是否有区别？
```cpp
int month = 9, day = 7; //十进制
int month = 09, day = 07; //八进制，编译会报错，month 超过了 8 进制的最大范围
```

### ex2.7
下述字面值表示何种含义？他们各自的数据类型是什么
- （a） "Who goes with F\145rgus?\012"; //字符串字面值
- （b） 3.14eL // long double 类型
- （c） 1024f  // float 类型
- （d） 3.14L  // long double 类型

### ex2.8
利用转义序列编写一段程序，要求先输出 2M，然后转到新一行；修改程序，使其先输出2，然后输出制表符，再输出M，最后转到一行
```cpp
#include <iostream>
int main() {
  std::cout << "2M \n"; // \n 转移字符，换行；
  std::cout << "2\tM\n"; //\t制表符 
  return 0;
}
```

### ex2.9
解释下面的定义的含义。对于非法的定义，请说明错在何处，并改正
- （a） std::cin >> int input_value; // 先定义，在cin    int inputValue; std::cin >> inputValue
- （b） int i = {3.14}; //编译报错，初始化列表不允许进行类型转换，可以将其调整成 float 类型或者 double 类型  double i = {3.14}
  - double i = {3.14}; int i(3.14);
- （c） double salary = wage = 9999.99; // wage 类定义，先定义
- （d） int i = 3.14; //类型转换，丢失小数部分

**当我们使用内置数据变量，使用列表初始化且初始值存在丢失信息的风险，编译器将报错**

### ex2.10
[ch02/ex_2.10.cpp](ch02/ex_2.10.cpp)

### ex2.11
指出下面的语句是声明还是定义？
```cpp
extern int ix = 1024; //定义
int iy; //声明并定义
extern int iz; //声明
```
**变量只能被定义一次，但可以被多次声明**

### ex2.12
指出下面哪些名字是非法的
```cpp
int double = 3.14; //非法，double 是关键字
int _; //合法
int catch-22; //非法，命名不能采用 - 进行连接
int 1_or_2 = 1; //非法，命名不能以数字开头
double Double = 3.14; //合法，但不推荐
```

**定义变量一般在第一次使用变量的时候再进行定义，并给其赋值一个合理的初始值**

### ex2.13
下面的程序中，j 的值是多少？
> j的值是 100
[ch02/ex_2.13.cpp](ch02/ex_2.13.cpp)

### ex2.14
下面的程序合法嘛？如果合法，它将输出什么？

> 合法，它将输出 0-9 的累加和
[ch02/ex_2.14.cpp](ch02/ex_2.14.cpp)

### ex2.15
下面哪个定义是不合法的？为什么
```cpp
int ival = 1.01; //合法，会丢失小数位
int &rvall  = 1.01; //不合法，引用不能指向字面值常量，引用的初始值必须是一个对象
int &rval2 = ival; //合法，引用指向了ival
int &rval3; //不合法，引用定义必须要被初始化
```

### ex2.16
考察下面的所有赋值然后问答：哪些赋值时不合法的？为什么？哪些赋值时合法的？它们执行了什么样的操作
```cpp
int i = 0, &r1 = i;
double d = 0, &r2 = d;

r2 = 3.14159; //合法，通过引用修改d的值
r2 = r1; // 合法，将 int类型的值赋值给double类型
i = r2; //合法，将 r2 引用指向的值赋值给 i，会丢失精度
r1 = d; //合法，将d 的值赋值给 r1 引用的对象
```

### ex2.17
执行下面的代码段，将输出什么结果?
```cpp
int i, &ri = i;
i = 5; ri = 10;
std::cout << i << " " << ri << std::endl; // 10 10
```
