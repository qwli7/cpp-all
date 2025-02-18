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

### ex2.18
编写代码分别更改指针的值以及指针所指向的对象的值
[ch02/ex_2.18.cpp](ch02/ex_2.18.cpp)

### ex2.19
说明指针和引用的区别
- 引用在声明的时候必须被初始化，指针可以先声明，后初始化
- 指针指向的是一个变量的地址，它自己本身也有地址，可以修改指向；引用本身没有地址，只是变量的别名，一旦绑定了，就不允许被修改

### ex2.20
请叙述下面这段代码的作用
```cpp
int i = 42;
int *pi = &i; //定义一个指针，指向i
*pi = *pi * *pi; // 通过 * 解引用符对 i 取平方后，再赋值给 i
```

### ex2.21
请解释下述定义。在这些定义中有非法的嘛？如果有，为什么？
```cpp
int i = 0;
double *dp = &i; //非法，不能把 double 类型的指针指向 int 类型的变量
int *p = i; // 非法，指针赋值必须是地址，不能是变量
int *p = &i; //合法，把指针 p 指向 i 的地址
```

### ex2.22
假设 p 是一个 int 型指针，请说明下述代码的含义
```cpp
if(p) //条件永远成立

if(*p); //当 p 指向的类型值为 0 时条件成立，否则条件不成立
```

### ex2.23
给定指针p，你能知道它是否指向了一个合法的对象嘛？如果能，叙述判断的思路，如果不能，也请说明原因；
```cpp
//可以通过 nullptr 或者 cstdlib 里面的 NULL 来进行判断，但仅仅只能判断指针指向的对象是否合法，不能判断指针指向的内存是否是应用程序外部的内存地址
if(ptr != nullptr) {
//有效
} else {
// 无效 
}
```

### ex2.24
下面的这段代码中为什么 p 合法，而 lp 非法？
```cpp
int i = 42;
void *p = &i; //void* 能接收任意类型的指针
long *lp = &i; // 指针的类型和指向的变量类型不一致，不能处理，除非进行类型转换

```

### ex2.25
说明下列变量的类型和值
```cpp
int *ip, i, &ri = i; //定义了一个指针 ip，一个 int类型的变量，一个 ri 类型的引用，绑定了 i 这个变量
int i, *p = 0;  //定义了一个 int 类型的变量，一个指向 int 类型的指针 p，赋值为 0（也叫做 nullptr）
int *ip, ip2; //定义了一个指向 int 类型的指针 ip，一个 int 类型的变量 ip2
```

### ex2.26
下面哪些句子是合法的，如果有不合法的句子，请说明为什么？
```cpp
const int buf; //不合法，const 类型的变量在声明时必须被初始化，因为 buf 后续不能被改变
int cnt = 0; //合法，创建一个变量，初始化为0
const int sz = cnt; //合法，将 cnt 的值赋值到 sz 上，在编译的时候进行处理
++cnt; ++sz; // 前者合法，后者不合法，因为 sz 被 const 修饰了，不能再被改变
```
- 默认被 const 修饰的变量只在当前的文件内有效
- const 类型修饰的必须被初始化
- const int i = get_size(); //运行时被初始化
- const int j = 42; //编译时被初始化
- 多文件共享同一个 const 对象，需要用 extern 关键词修饰，表明当前变量来自于其他文件
```cpp
//file1.cpp 中定义并初始化了一个常量，该常量能被其他文件访问
extern const int buffSize = fcn();
//other_file.cpp
extern const int buffSize; //与 file1.cpp 中的 buffSize 是同一个
```

### ex2.27
下面的哪些初始化是合法的，请说明原因；
```cpp
int i = -1, &r = 0; //前半部分合法，后半部分不合法，不能把一个引用绑定到一个字面值常量上
int *const p2 = &i2; //合法，p2 是一个指针常量，表示 p2 不能改变指向
const int i = -1; &r = 0; //前半部分合法，后半部分不合法，不能把一个引用绑定到一个字面值常量上
const int *const p3 = &i2; // 合法，p3 是一个指针常量，指向一个常量，不能改变指向也不能通过指针改变 i2 的值
const int *p = &i2; //合法，指向常量的指针，但不能通过 p 去修改值，这样不被允许
const int &const r2; //不合法，常量引用没有赋初始值
const int i2 = i, &r = i; //合法，定义常量 i2 赋初始值，定义引用绑定i对象
```

### ex2.28
说明下面的这些定义是什么意思，挑出不合法的部分
```cpp
int i, *const cp; //定义了一个变量，一个常量指针，但常量指针没有赋值初始值
int *p1, *const p2; //定义了一个指向 int类型的指针，一个常量指针，常量指针没有赋初始值
const int ic, &r = ic; //定义了一个 int类型的常量，没有赋值初始值；一个常量引用
const int *const p3; //定义了一个指向常量的常量指针，没有赋值初始值
const int *p; //定义了一个指向常量的指针
```

### ex2.29
假设已有上一个练习中定义的那些变量，则下面的哪些语句是合法的？请说明原因
```cpp
i = ic; //赋值合法，将 ic 赋值给变量 i
p1= p3; //不合法，将 p3 赋值给 p1 后，p3 所指向对象可以被 p1 修改
p1 = &ic; //合法，将常量 ic 的地址赋值给指针 p1
p3 = &ic; // 合法
p2 = p1; // 不合法，p2 是指针常量，不允许被修改指向
ic = *p3; //ic是常量，不允许修改值
```
### ex2.30
对于下面的这些语句，请说明对象被声明称顶层 const 还是底层 const
```cpp
const int v2 = 0; //顶层 const
int v1 = v2; // 顶层const
int *p1 = &v1, &r1 = v1; //底层 const
const int *p2 = &v2, *const p3 = &i, &r2 = v2; //既是顶层也是底层 
```

### ex2.31
假设已有上一个练习中所做的哪些声明，则下面的哪些语句是合法的？请说明顶层 const 和底层 const 在每个例子中有何体现。
```cpp
r1 = v2; // 不合法，引用不能更改绑定的对象，r1 已经作为了 v1 的引用
p1 = p2; 
p2 = p1;
p1 = p3;
p2 = p3;
```

- 顶层 const：表示指针本身是一个常量
- 底层 const：表示指针指向的对象是一个常量


### ex2.32
下面的代码是否合法？如果非法，请设法将其修改正确；
```cpp
int null = 0,*p = null; //不合法
int a = 0, *p = nullptr, *q = NULL, *r = 0;  // 正确写法
```


### ex2.36
关于下面的代码，请指出每一个变量的类型以及程序结束时它们各自的值
```cpp
int a = 3, b =4;
decltype(a) c = a; //int c =  a;
decltype((b)) d = a; // int & d = a
++c;
++d;

// a = 4
// c = 4
// d = 4
// b = 4
```
- decltype((variable)) 结果是引用，例如 decltype((i)) d, 那么推断出来的 d 的类型是 int& d; 且 d 必须被初始化
- decltype(variable) 只有当 variable 本身是引用时，才是引用；decltype(i) e // e 是一个未初始化的 int 类型

### ex2.37
赋值是会产生又难用的一类典型表达式，引用的类型就是左值的类型。也就是说如果 i 是 int，则表达式 i = x 的类型就是 int&。根据这一特点，请指出下面的代码每个变量的类型和值；
```cpp
int a = 3, b =4;
decltype(a) c = a; //int c = a
decltype(a = b) d = a;  // int& b = a;
```

### ex2.38
说明由 decltype 指定的类型和 auto 指定的类型有啥区别？

### ex2.39
编译下面的程序观察其运行结果。
```cpp
struct Foo {}
int main() {
  return 0;
}
```
> 以上的代码编译会报错

### ex2.40
写出自己的 `Sales_data` 类
```cpp
struct Sales_data {
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};
```

### ex2.41
使用你自己的 Sales_data 类重写 1.5.1 节和 1.5.2 节和第 1.6 节的练习。
[ch02/ex_2.41.cpp](ch02/ex_2.41.cpp)

### ex2.42
根据自己的理解重写一个 `Sales_data.h` 文件；主要解决重复包含的问题
[ch02/Sales_data.h](ch02/Sales_data.h)


## ch03
### ex3.1
使用恰当的 using 声明重做 1.4.1 节和 2.6.2 节的练习
[ch03/ex_3.1.cpp](ch03/ex_3.1.cpp)

### string对象的初始化方式
|定义方式                            |解释                                |
|------------------------------------|------------------------------------|
| string s1                          | 默认初始化，s1 是一个空的字符串     |
| string s2(s1)                      | s2 是 s1 的副本                    |
| string s2 = s1                     | 等价于 s2(s1)                   |
| string s3("value")                 | s3 是字面值 "value" 的副本          |
| string s3 = "value"                | 等价于 s3("value")                 |
| string s4(n, 'c')                  | 把 s4 初始化由连续的 n 个字符 c 组成的串 |

- **使用 = 初始化，执行的是拷贝初始化**
- 不使用等号，则执行的是 **直接初始化**
### string 对象的操作方式
|定义方式|解释|
|------------------------------------|------------------------------------|
|os << s| 将 s写到输出流 os中，返回 os|
|is >> s| 从is 中读取字符串赋值给s， 字符串以空白符分割，返回 is|
|getline(is, s)| 从 is 中读取一行赋值给 s，返回 is|
|s.empty()| s 为空，返回 true，否则返回 false|
|s.size()| 返回 s 中字符的个数|
|s[n]| 返回 s 中第 n 个字符的引用，下标从 0 开始|
|s1+s2| 返回 s1 和 s2 连接后的结果|
|s1=s2| 用 s2 的副本代替 s1 中原来的字符|
|s1==s2| 如果 s1 和 s2 中所含的字符完全一样，则它们相等；string 对象的相等性判断对字母的大小写敏感|
|s1!=s2| 不相等|
|<, <=, >, >=|利用字符在字典中的顺序进行比较，则对字母的大小写敏感|

### ex3.2
编写一段程序，从标准输入中一次读取一整行，然后修改该程序使其一次读入一个词
[ch03/ex_3.2.cpp](ch03/ex_3.2.cpp)

### ex3.3
请说明 string 类的输入运算符和 getline 函数分别是如何处理空白字符的
- getline 一次读取一行，丢弃末尾的换行符
- cin>>str 以空格进行分隔

### ex3.4
编写一段程序读取两个字符串，比较其是否相等并输出结果。如果不相等，输出较大的那个字符串。改写上述程序，比较输入的两个字符串是否等长，如果不等长，输出长度较大的那个字符串；
- [ch03/ex3.4_1.cpp](ch03/ex3.4.1.cpp)
- [ch03/ex3.4.2.cpp](ch03/ex3.4.2.cpp)
