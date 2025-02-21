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

### ex3.5
编写一段程序，从标准输入中读入多个字符串，并把他们他们连接在一起；输出连接成的大字符串。然后修改上述程序，用空格把输入的多个字符串分隔开来
```cpp
#include <iostream>
#include <string>

// 使用 using 来声明，避免每次都需要写域作用符 std::cout std::cin std::endl

using std::cin;
using std::cout;
using std::endl;
using std::string;
int main()
{
    string str;
    string str2;
    while (cin >> str)
    {
        // str2 += str;
        str2 += str;
        str2 += " ";
    }
    cout << str2 << endl;

    return 0;
}
```

### ex3.6
使用范围 for 循环语句将字符串内所有的字符用 X 替代；
```cpp
#include <iostream>
#include <string>

// 使用 using 来声明，避免每次都需要写域作用符 std::cout std::cin std::endl

using std::cin;
using std::cout;
using std::endl;
using std::string;
int main()
{
    string str = "Hello world";
    for (auto &c : str)
    {
        c = 'X';
    }
    cout << str << endl;

    return 0;
}
```

### ex3.7
就上一题完成的程序而言，如果将循环控制变量的类型设置成 char，将发生什么？
> 无法完成替代，还是会原样输出，要修改字符串的内容，必须要将变量的类型设置成 & （值传递）

### ex3.8
分别用 while 循环和传统 for 循环重做 ex3.7
```cpp
#include <iostream>
#include <string>

// 使用 using 来声明，避免每次都需要写域作用符 std::cout std::cin std::endl

using std::cin;
using std::cout;
using std::endl;
using std::string;
int main()
{
    string str = "Hello world";
    for (decltype(str.size()) i = 0; i < str.size(); ++i)
    {
        str[i] = 'X';
    }
    cout << str << endl;
    decltype(str.size()) i = 0;
    while (i < str.size())
    {
        str[i] = 'Y';
        i++;
    }
    cout << str << endl;

    return 0;
}
```

### ex3.9
下面的程序有何作用？它合法吗？如果不合法，为什么？
```cpp
string s;
cout << s[0] << endl; 
```
> 不合法，s 是一个空字符串，根据索引 0 取值会取到无法预料到的结果

### ex3.10
编写一段程序，读入一个包含标点符号的字符串，将标点符号去除后输出字符串剩余的部分；
[ch03/ex_3.10.cpp](ch03/ex_3.10.cpp)

### ex3.11
下面的范围 for 语句合法吗？如果合法，c 的类型是什么？
```cpp
const string s = "Keep out!";
for(auto &c: s){/**/}
```
> 如果 for 没有修改原本的 s 对象的内容，则合法；反之，则不合法，s 被定义成常量，不允许被修改

### ex3.12
下列 vector 对象的定义有不正确的吗？如果有，请指出来。对于正确的，描述其执行结果；对于不正确的，说明其错误的原因；
```cpp
vector<vector<int>> ivec; //正确定义了一个 vector 容器，里面每个元素是一个 vector<int> 类型
vector<string> svec = ivec; //两个模板的类型不一致，不能做拷贝初始化，错误
vector<string> svec(10, "null"); //定义了一个 vector 容器，里面有10个元素，每个元素都是一个 null 字符串
```

### ex3.13
下列的 vector 对象各包含多少个元素？这些元素的值分别是多少？
```cpp
vector<int> v1; //初始化了一个模板，容量为0
vector<int> v2(10); //初始化了一个vector，容量为10，初始值为0
vector<int> v3(10,42); //初始化了一个 vector，容量为10，初始值为 42
vector<int> v4{10}; //容量为1，初始值为 10
vector<int> v5{10, 42}; //容量为2，初始值为 10 42
vector<string> v6{10}; //容量为10，初始值为 ""
vector<string> v7{10, "hi"}; //容量为10，初始值为十个 "hi"
```

### ex3.14
编写一段程序，用 cin 读取一组整数，并把他们存入一个 vector 对象
```cpp
#include <iostream>
#include <vector>

// 使用 using 来声明，避免每次都需要写域作用符 std::cout std::cin std::endl

using std::cin;
using std::cout;
using std::endl;
using std::vector;
int main()
{
    vector<int> ivec;
    int value;
    while (cin >> value)
    {
        ivec.push_back(value);
    }
    return 0;
}
```

### ex3.15 
改写 3.14 的程序，不过这次读入的是字符串
```cpp
#include <iostream>
#include <vector>
#include <string>

// 使用 using 来声明，避免每次都需要写域作用符 std::cout std::cin std::endl

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
int main()
{
    vector<string> ivec;
    string value;
    while (cin >> value)
    {
        ivec.push_back(value);
    }
    return 0;
}
```

### ex3.16
编写一段程序，把练习 3.13 中的 vector对象的容量和具体内容输出出来
[ch03/ex_3.16.cpp](ch03/ex_3.16.cpp)

### ex3.17
从 cin 中读取一组词，并把他们存入一个 vector 对象，然后设法把所有的词都改成大写形式，输出改变后的结果，每个词占一行
```cpp
#include <iostream>
#include <vector>
#include <string>

// 使用 using 来声明，避免每次都需要写域作用符 std::cout std::cin std::endl

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
int main()
{
    vector<string> vstr;
    string str;
    while (cin >> str)
    {
        vstr.push_back(str);
    }
    for (auto &s : vstr)
    {
        for (auto &c : s)
        {
            c = toupper(c);
        }
        cout << s << endl;
    }
    return 0;
}
```

### ex3.18
下面的程序合法吗？如果不合法，你准备如何修改
```cpp
vector<int> ivec;
ivec[0] = 42;
```
> 不合法，将其修改成 ivec.push_back(10);

### ex3.19
如果想定义一个含有 10 个元素的 vector 对象，所有的元素值都是 42，请列举出三种不同的实现方法？
```cpp
vector<int> ivec = {42, 42, 42, .......}; //10个42
vector<int> ivec {42, 42, 42, 42 .......};// 10个42
vector<int> ivec(10, 42); //10个42
```

### ex3.20
读入一组整数并把他们存储一个 vector 对象中，将每队相邻整数的和输出出来。改写你的程序，这次要求先输出第一个和最后一个元素的和，紧接着输出第二个和倒数第二个元素的和，以此类推；
```cpp
#include <iostream>
#include <vector>

// 使用 using 来声明，避免每次都需要写域作用符 std::cout std::cin std::endl

using std::cin;
using std::cout;
using std::endl;
using std::vector;
int main()
{
    vector<int> ivec;
    int value;
    while (cin >> value)
    {
        ivec.push_back(value);
    }
    //相邻相加
    for (decltype(ivec.size()) i = 0; i < ivec.size() - 1; ++i)
    {
        cout << "ivec[" << i << "] + ivec[" << i + 1 << "] = " << ivec[i] + ivec[i + 1] << endl;
    }

    cout << endl;
    // 首尾相加
    for (decltype(ivec.size()) i = 0; i < ivec.size() / 2; ++i)
    {
        cout << "istr[" << i << "] + istr[" << ivec.size() - 1 - i << "] = " << ivec[i] + ivec[ivec.size() - 1 - i] << endl;
    }
    return 0;
}
```

### ex3.21
使用迭代器重做 3.3.3 节的第一个练习
```cpp
#include <iostream>
#include <vector>
#include <string>

// 使用 using 来声明，避免每次都需要写域作用符 std::cout std::cin std::endl

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
int main()
{
    vector<int> ivec(10, 42);
    for (std::vector<int>::iterator it = ivec.begin(); it != ivec.end(); ++it) //普通迭代器
    {
        cout << *it << " ";
    }
    cout << endl;

    auto it2 = ivec.cbegin(); //常量迭代器
    while (it2 != ivec.cend())
    {
        cout << *it2++ << " ";
    }
    cout << endl;

    return 0;
}
```

### ex3.22
修改之前那个输入 text 第一段的程序，首先把 text 的第一段全部都改成大写形式，然后再输出它
```cpp
#include <iostream>
#include <vector>
#include <string>

// 使用 using 来声明，避免每次都需要写域作用符 std::cout std::cin std::endl

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
int main()
{
    vector<string> v = {"hello", "world", "c++"};
    std::vector<string>::iterator p = v.begin();
    for (; p != v.end() && !p->empty(); ++p)
    {
        for (auto &c : *p)
        {
            c = toupper(c);
        }
        cout << *p << endl;
    }

    return 0;
}
```

### ex3.23
编写一段程序，创建一个含有10个整数的 vector 对象，然后使用迭代器将所有元素的值都变成原来的两倍，输出 vector 对象的内容，检查程序是否正确
```cpp
#include <iostream>
#include <vector>
#include <string>

// 使用 using 来声明，避免每次都需要写域作用符 std::cout std::cin std::endl

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
int main()
{
    vector<int> ivec = {1, 2, 3, 4, 5};
    std::vector<int>::iterator p = ivec.begin();
    for (; p != ivec.end(); ++p)
    {
        *p = *p * 2;
        cout << *p << " ";
    }

    return 0;
}
```

### ex3.24
使用迭代器重做 3.20 的练习
> 读入一组整数并把他们存储一个 vector 对象中，将每队相邻整数的和输出出来。改写你的程序，这次要求先输出第一个和最后一个元素的和，紧接着输出第二个和倒数第二个元素的和，以此类推;
```cpp
#include <iostream>
#include <vector>
#include <string>

// 使用 using 来声明，避免每次都需要写域作用符 std::cout std::cin std::endl

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
int main()
{
    vector<int> ivec;
    int value;
    while (cin >> value)
    {
        ivec.push_back(value);
    }
    // 迭代器相邻相加
    std::vector<int>::const_iterator it = ivec.cbegin();
    while (it != ivec.cend() - 1)
    {
        cout << *it + *(it + 1) << " ";
        it++;
    }
    cout << endl;

    // 首尾相加
    std::vector<int>::const_iterator it1 = ivec.cbegin();
    std::vector<int>::const_iterator it2 = ivec.cend() - 1;
    while (it1 <= it2)
    {
        if (it1 == it2)
        {
            // 中间只有一个元素，直接输出
            cout << *it1 << " ";
        }
        else
        {
            cout << *it1 + *it2 << " ";
        }
        it1++;
        it2--;
    }

    return 0;
}
```

### ex3.25 
3.3.3 节中划分分数段的程序是使用下标运算符实现的，请利用迭代器改写该程序，并实现完全相同的功能；
```cpp
#include <iostream>
#include <vector>
#include <string>

// 使用 using 来声明，避免每次都需要写域作用符 std::cout std::cin std::endl

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
int main()
{
    vector<int> ivec = {10, 20, 11, 25, 67, 45, 50, 88, 92, 95, 98, 100, 6};
    vector<int> iScore(11, 0);
    std::vector<int>::const_iterator iter = ivec.cbegin();
    for (; iter != ivec.cend(); ++iter)
    {
        iScore[(*iter / 10)]++;
    }
    for (auto i : iScore)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
```

### ex3.26
在 100 页的二分搜索中，为什么用的是 mid=begin+(end-begin)/2, 而非 mid=(begin+end)/2;
> begin 指向的是首元素的地址，end 指向的是尾元素的下一个元素的地址，要计算首尾指针之间的元素数量，需要用 begin-end，再除以 2 得到的就是相对 begin 和 end 来说的中间位置，如果要获取到中间对应的指针元素，还需要将 begin 偏移一半的位置；

### ex3.27
假设 txt_size 是一个无参数的函数，他的返回值是 int，请回答下列哪个定义是非法的？为什么
```cpp
unsigned buf_size = 1024;

int ia[buf_size]; //合法，常量表达式
int ia[4*7-14]; //合法，常量表达式
int ia[txt_size()]; //合法
char st[11] = "fundamental"; //不合法，存不下结尾的空字符
```

### ex3.28
下列数组中元素的值指的是什么？
```cpp
string sa[10]; //默认初始化为 10 个空字符串
int ia[10]; // 默认初始化为 10 个 0
int main() {

    string sa2[10]; //未初始化
    int ia2[10];  //未初始化，访问的是随机的数字
    return 0;
}
```

### ex3.29
相比较 vector 来说，数组有哪些缺点？
- array 是固定分配的大小，不能动态扩充
- array 不能被拷贝赋值，只能通过拷贝构造函数进行初始化
- array 访问越界元素不会引发异常，会导致程序崩溃

### ex3.30
指出下面代码中的索引错误
```cpp
constexpr size_t array_size = 10;
int ia[array_size]; 
//访问到 ia[10] 的时候会越界
//数组的下标是从 0 到 size-1
for(size_t ix = 1; ix <= array_size; ++ix) { 
    ia[ix]=ix;
}
```

### ex3.31
编写一段程序，定义一个含有10个元素的数组，令每个元素的值就是其下标值
[ch03/ex_3.31.cpp](ch03/ex_3.31.cpp)

### ex3.32
将上一题刚刚创建的数组拷贝给另一个数组。利用 vector 重写程序，实现类似的功能；
[ch03/ex_3.32.cpp](ch03/ex_3.32.cpp)，vector 版本 [ch03/ex_3.32_vector.cpp](ch03/ex_3.32_vector.cpp)


### ex3.33
对于 104 页的代码来说，如果不初始化 score 数组，会出现什么问题？
```cpp
unsigned int score[10] = {0};
unsigned grade;
while(cin >> grade) {
    if(grade <= 100) {
        ++score[grade/10];
    }
}
```
> 不初始化会导致 score 数组里面的值是随机的，可能是 0， 也可能是其他的值，导致后续的计算结果不准确。

### ex3.34
假定 p1 和 p2 指向同一个数组中的元素，则下面程序的功能是什么？什么情况下该程序是非法的？
```cpp
p1 += p2 -p1; 
```
> 合法，将 p1 往后移动，指向 p2 指向的元素，此时 p1 和 p2 指向同一个元素
```cpp
#include <iostream>

using std::cout;
using std::endl;
int main()
{

    int ia2[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *p1 = &ia2[1];
    int *p2 = &ia2[5];
    cout << *p1 << endl; // 1
    cout << *p2 << endl; // 5
    cout << endl;
    p1 += p2 - p1;
    cout << *p1 << endl; // 5
    cout << *p2 << endl; // 5

    return 0;
}
```

### ex3.35
编写一段程序，利用指针将数组中的元素置为 0；
[ch03/ex_3.35.cpp](ch03/ex_3.35.cpp)

### ex3.36
编写一段程序，比较两个数组是否相等。再写一段程序，比较两个 vector 对象是否相等；
[ch03/ex_3.36.cpp](ch03/ex_3.36.cpp)


### ex3.37
下面程序是何含义，程序的输出结果是什么？
```cpp
const char ca[] = {'h', 'e', 'l', 'l', 'o'};
const char *cp = ca;
while(*cp) {
  cout << *cp << endl;
  ++cp;
}
```
> 会逐行打印出 h，e，l，l，o 后继续往后打印，直到遇到空字符（\0）为止

### ex3.38
在本节中我们提到，将两个指针相加不但是非法的，而且也没有什么意义。请问为什么两个指针相加没有什么意义？
> 两个指针相加，无法确定相加后的指针指向的是是否是合法的数据

### ex3.39
编写一段程序，比较两个 string 对象。再编写一段程序，比较两个 C 风格字符串内容；
[ch03/ex_3.39.cpp](ch03/ex_3.39.cpp)

### ex3.40
编写一段程序，定义两个字符数组并用字符串字面值初始化它们；接着再定义一个字符数组存放前两个数组连接后的结果。使用 strcpy 何 strcat 把前两个两组的内容拷贝到第三个数组中。
[ch03/ex_3.40.cpp](ch03/ex_3.40.cpp)

### ex3.41 
编写一段程序，用整型数组初始化一个 vector 对象
```cpp
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    vector<int> v(arr, arr + 5); //指针
    vector<int> v2(std::begin(arr), std::end(arr)); // 迭代器
    vector<int> v3(arr + 1, arr + 4); //指针
    return 0;
}
```

### ex3.42
编写一段程序，将含有整数元素的 vector 对象拷贝给一个整型数组
```cpp
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    vector<int> v(arr, arr + 5); // 指针

    int arr2[5];
    // for (decltype(v.size()) i = 0; i < v.size(); ++i)
    for (size_t i = 0; i < v.size(); ++i)
    {
        arr2[i] = v[i];
    }

    for (auto i : arr2)
    {
        cout << i << " ";
    }

    return 0;
}
```

### ex3.43
编写三个不同版本的程序，令其均能输出 ia 的元素。
- 版本1使用范围 for 管理迭代过程
- 版本2 和版本3 都是用普通的 for 语句，其中版本2 要求用下标运算符，版本3要求用指针
- 此外三个版本都要求直接写出数据类型，不能使用类型别名，auto、decltype 关键字
```cpp
int ia[3][4] = {
  {1, 2, 3, 4},
  {2, 4, 6, 8},
  {3, 6, 9, 12}
}
```
[ch03/ex_3.43.cpp](ch03/ex_3.43.cpp)

### ex3.44
改写上一个练习中的程序，使用类型别名来代替循环控制变量的类型；
[ch03/ex_3.44.cpp](ch03/ex_3.44.cpp)

### ex3.45
再一次改写程序，这次使用 auto 关键字
[ch03/ex_3.45.cpp](ch03/ex_3.45.cpp)


## ch04

### ex4.1
表达式 5+10*20/2 的求值结果是多少？
> 105

### ex4.2
根据 4.12 节中的表，在下述表达式的合理位置添加括号，使得添加括号后运算对象的组合顺序于添加括号前一致；
```cpp
*vec.begin(); //(*vec).begin()
*vec.begin() + 1; // (*vec).begin() + 1
```

### ex4.3
C++ 语言没有明确规定大多数二元运算符的求值顺序，给编译器优化留下余地。这种策略实际上是在代码生成效率和程序潜在缺陷之间进行了权衡；你认为这样可以接受吗？
> 可以接受，如果使用者需要明确规定求值顺序，可以使用 () 来强制改变求值顺序

### ex4.4
在下面的表达式中添加括号，说明其求值的过程以及最终的结构。编写程序编译该（不加括号的）表达式并输出其结果验证之前的推断
```cpp
12 / 3 * 4 + 5 * 15 + 24 % 4 / 2; // 91
```
>  (12 / 3) * 4 + (5 * 15) + (24 % 4) / 2

### ex4.5
写出下列表达式的求值结果
```cpp
-30 * 3 + 21 / 5; // -86
-30 + 3 * 21 / 5; // -18
30 / 3 * 21 % 5; // 0
-30 / 3 * 21 % 4;// -2
```

### ex4.6
写出一条表达式，用于确定一个整数是奇数还是偶数
```cpp
i%2 != 0; //奇数
i%2 == 0; //偶数
```

### ex4.7
溢出是何含义？写出三条将导致溢出的表达式
> 溢出表示超出了类型的最大范围，假设 char 是一个字节，那么表示的范围就是 -(2^8) ~ 2^8-1
```cpp
unsigned char c = -1; // 溢出，转换成 int 类型后，c 的值为 255
short short_value = 32767; short_value += 1； //溢出
```
### ex4.8
说明现在逻辑与、逻辑或及相等性运算符中运算对象求值的顺序
- 逻辑或 a || b, 如果 a 为真，则不对 b 进行求值；（当且仅当左侧运算对象为真时，才对右侧运算对象求值 **短路求值**）
- 逻辑与 a && b, 如果 a 为假，则不会对 b 进行求值；（当且仅当左侧运算对象为假时，才对右侧对象求值 **短路求值**）
- 相等性运算符，两侧都需要进行求值，然后对两侧求值的对象进行相等性判断

### ex4.9
解释在下面的 if 语句中，条件部分的判断过程
```cpp
const char *cp = "Hello World";
if(cp && *cp) {/**/};
```
> 先判断 cp 是否是指向了 nullptr 或者 NULL 或者 0， 如果不是，则判断 *cp 的内容

### ex4.10
为 while 循环写一个条件，使其从标准输入中读取整数，遇到 42 停止；
```cpp
int main()
{
    int value;
    while (cin >> value)
    {
        if (value == 42)
        {
            break;
        }
        cout << "input value: " << value << endl;
    }
    return 0;
}
```

### ex4.11
书写一条表达式，用于测试 4 个值 a、b、c、d 的关系，确保 a 大于 b，b 大于c， c 大于d；
```cpp
if(a > b && b > c && c > d) {/**/}
```

### ex4.12
 假设i、j 和 k 是三个整数，说明表达式 i != j < k 的含义
 > 这个表达式会先判断 i!=j，再拿 bool 类型的值与 k 进行比较

### ex4.13 
在下述语句中，当赋值完成后，i 和 d 的值分别是多少？
```cpp
int i; double d;
d = i = 3.5;
i = d = 3.5;
```
> 第一条执行后 d 和 i 都是 3； 第二条执行后 d 是 3.5，i 是 3

### ex4.14
执行下述 if 语句后将发生什么情况？
```cpp
if(42 = i) //
if(i = 42) //
```
> 第一个 if 编译报错，因为 42 是一个常量，赋值运算符左边必须是一个可修改的左值；
> 第二个 if 是把 42 赋值给 i，拿赋值的结果来判断是否是 false 或者 true

### ex4.15
下面的赋值是非法的，为什么，应该如何修改？
```cpp
double dval; int ival; int *pi;
dval = ival = pi = 0;
```
> pi 是一个指针，把指针赋值给基本类型的变量会导致编译报错；不能将 int * 类型的变量赋值给 int 类型的实体；
> 修改方式对指针进行解引用即可
```cpp
double dval; int ival; int *pi;
dval = ival = *pi = 0;
```

### ex4.16
尽管下面的语句合法，但他们实际执行的行为可能和预期的并不一样，为什么？应该如何修改？
```cpp
if(p = getPtr() != 0) // if((p = getPtr()) != 0)
if(i = 1024) //  if(i == 1024)
```

### ex4.17
说明前置递增运算符和后置递增运算符的区别。
> 前置递增运算符 ++i： 直接把 i 自增 1 后的值赋值给 i；
> 后置递增运算符 i++： 先取出 i 的值使用后，再对 i 进行自增 1；

### ex4.18
如果第 132 也那个输出 vector 对象的元素的 while 循环使用前置递增运算符，将得到什么结果？
```cpp
auto pbeg = v.begin();
while(pbeg != v.end() && *pbeg >=0) {
  cout << *pbeg++ << endl;
}
```
> 会导致位置为 0 的元素不会被打印出来，最后元素位置的下一个元素也会被打印出来

### ex4.19
假设 ptr 的类型是指向 int 的指针、vec 的类型是 vector<int>、ival 的类型是 int，说明下面表达式是什么含义？如果有的表达式不正确，为什么？应该如何修改？
```cpp
ptr != 0 && *ptr++;  //判断指针有效，且对指针的下一个位置取值，等同于 ptr != 0 && a
ival++ && ival; //对 ival 自增和 ivar 本身的值进行与运算
vec[ival++] <= vec[ival]; //判断 vec 里面相邻两个元素的大小关系
```

### ex4.20
假设 iter 的类型是 vector<string>::iterator，说明下面的表达式是否合法。如果合法，表达式的含义是什么？如果不合法，错在何处？
```cpp
*iter++; //合法，取 vec 容器的下一个元素的值
(*iter)++; //合法，对当前位置取值，然后自增
*iter.empty(); // 不合法，解引用符优先级低于点运算符，所以这里的意思是调用迭代器的 empty() 方法，迭代器并没有 empty() 方法，可修改成 (*iter).empty() 或者 iter->empty();
iter->empty(); //合法，迭代器指向的 string 类型是否是空串
++*iter; //不合法，需要将 *iter 用括号括起来
iter++->empty(); //合法，指向的下一个元素的内容是否是空的
```
- 如果用指针访问成员，需要用 -> 符号
- 如果解引用后访问成员，可以使用 . 运算符

### ex4.21
编写一段程序，使用条件运算符从 vector<int> 中找到哪些元素的值是奇数，然后将这些奇数的值翻倍；
[ch04/ex_4.21.cpp](ch04/ex_4.21.cpp)

### ex4.22
本节的示例程序将成绩划分为 high，pass 和 fail 三种，扩展该程序使其进一步将 60 分到 75 分之间的成绩设定为 low pass。要求程序包含两个版本
- 一个版本只使用条件运算符
- 另一个版本使用 1 个或多个 if 语句。
哪个版本的程序更容易理解呢？为什么？

> if 条件版本版本，能明确看到进入 if 分支的条件逻辑

[ch04/ex_4.22.cpp](ch04/ex_4.22.cpp)

### ex4.23
因为运算符的优先级问题，下面这条表达式无法通过编译。根据 4.12 节中的表，指出它的问题在哪里？应该如何修改？
```cpp
string s = "word";
string p1 = s + s[s.size() -1] == 's' ? "": "s"; // string p1 = s + (s[s.size() -1] == 's' ? "" : "s")
```
> 需要提升条件运算符的优先级

### ex4.24
本节的示例程序将成绩划分成 high pass、pass 和 fail 三种，他的依据是条件运算符满足右结合律。假如条件运算符满足的是左结合率、求值过程是怎样的？
```cpp
finalgrade = (grade>90) ? "high pass" : (grade < 60) ? "fail" : pass
```
> 满足左结合率，会运算第一个条件运算符，这样会导致编译报错

### ex4.25
如果一台机器上 int 占 32 位、char 占 8 位，用的是 Latin-1 字符集，其中字符 q 的二进制形式是 01110001，那么表达式 q << 6 的值是什么？
> 01110001 右移动 6 位，变成 01000000 转换成十进制就是 64

### ex4.26
在本节关于成绩测验的例子中，如果使用 unsigned int 作为 quizl 的类型会发生什么样的情况？
> 有可能 int 的范围不够，如果 int 和 short 一样的话，可能只有 16 位，无法存储 30 个学生测测试情况

### ex4.27
下面的表达式的结果是什么？
```cpp
unsigned long ul1 = 3, ul2 = 7;
ul1 & ul2; //按位与  00000011 & 00000111 = 00000011  转换成十进制就是3
ul1 | ul2; //按位或  00000011 | 00000111 = 00000111  转换成十进制就是7
ul1 && ul2; //两个 true && true，结果为 true
ul1 || ul2; //两个 true || true，结果仍然为 true
```
- 按位与：都是 1 才返回 1，否则为0
- 按位或：都是 0 才返回 0，否则为1
- 按位异或：只有一个 1 才返回 1，否则为 0

### ex4.28
编写一段程序，输出一种内置类型所占用的空间大小；
[ch04/ex_4.28.cpp](ch04/ex_4.28.cpp)

### ex4.29
推断下面的代码的输出结果并说明理由。实际运行这段程序，结果和你想象的一样吗？如果不一样，为什么？
```cpp
int x[10]; int *p = x;
cout << sizeof(x)/sizeof(*x) << endl; //计算数组元素的个数
cout << sizeof(p)/sizeof(*p) << endl; //计算指针p的大小除以一个 int 类型的大小
```

### ex4.30
根据 4.12 节中的表，在下述表达式的适当位置加上括号，使得加上括号之后表达式的含义与原来的含义相同；
```cpp
sizeof x + y; //sizeof(x+y)
sizeof p->mem[i]; //sizeof(p -> mem[i]);
siezeof a < b; // sizeof(a < b);
sizeof f(); // sizeof(f());
```

### ex4.31
本节的程序使用了前置版本的递增运算符和递减运算符，解释为什么要用前置版本而不用后置版本。想要使用后置版本的递增递减运算符需要做哪些改动？使用后置版本重写本节的程序
```cpp
vector<int>::size_type cnt = ivec.size();
for(vector<int>::size_type ix = 0; ix != ivec.size(); ++ix, --cnt) {
  ivec[ix] = cnt;
}
```
后置版本
```cpp
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
int main()
{

    vector<int> ivec(5);
    vector<int>::size_type cnt = ivec.size();
    for (vector<int>::size_type ix = 0; ix != ivec.size(); ix++, cnt--)
    {
        ivec[ix] = cnt;
    }
    for (auto i : ivec)
    {
        cout << i << " ";
    }
    return 0;
}
```

### ex4.32 
解释下面这个循环的含义
```cpp
constexpr int size = 5;
int ia[size] = {1,2,3,4,5};
for(int*ptr = ia, ix = 0; ix!=size && ptr != ia+size; ++ix, ++ptr) {
}
```
> 遍历 ia，将 ix 的值从 0 自增到 4

### ex4.33
根据 4.12 节中的表，说明下面这条表达式的含义。
```cpp
someValue ? ++x, ++y: --x, --y; //someValue的值为 true，则对 x 和 y 自增，反之自减
```

### ex4.34
根据本节给出的变量定义，说明在下面的表达式中将发生什么样的类型转换？
```cpp
if(fval)  //fval 转换成 bool
dval = fval + ival; //fval 和 ival 都转换成 double
dval+ ival * cval; // cval 提升成 int类型与 ival 进行计算后，再转换成 double 类型 
```

### ex4.35
假设有如下的定义
```cpp
char cval;
int ival;
unsigned int ui;
float fval;
double dval;
```
请问再下面的表达式中发生了隐式类型转换吗？如果有，请指出来
```cpp
cval = 'a' + 3; //发生了，先把 a 提升成 int 类型，与 3 相加，然后把结果转换成 char 类型
fval = ui - ival * 1.0; //发生了
dval = ui * fval; //发生了
cval = ival + fval + dval; //发生了
```


### ex4.36
假设 i 是 int 类型，d 是 double 类型，书写表达式 i*=d 使其执行整数类型的乘法而不是浮点型类型的乘法；
```
i*=d; // 先乘，再舍弃小数点，假如 i= 9，d = 2.4；这条语句执行后，将得到 21 的结果
i*=static_cast<int>(d); //先转换成 int，再进行乘法，假如 i= 9，d = 2.4；这条语句执行后，将得到 18 的结果
```

### ex4.37
用命名的强制类型转换改写下列旧式的转换语句
```cpp
int i; double d; const string *ps; char *pc; void *pv;

pv = (void*)ps;  // pv = const_cast<void *>(static_cast<const void *>(ps));
i = int(*pc); // i = static_cast<int>(*pc);
pv = &d; // pv = static_cast<void *>(&d);
pc = (char*) pv; //pc = static_cast<char*>(pv);
```

### ex4.38
说明下面这条表达式的含义
```cpp
double slope = static_cast<double>(j/i); 
```
> 把 j/i 的值强制转换成 double 类型


## ch05
### ex5.1
什么是空语句？什么时候会用到空语句？
> 只有一个 ; 的语句是空语句。当语法上需要，逻辑上不需要的时候，就可以使用空语句。

### ex5.2
什么是块？什么时候要用到块？
> {} 就是一个语句块；语法上需要一条语句，但逻辑上需要多条语句，我们就应该使用 {} 将其包裹起来

### ex5.3
使用逗号运算符重写第十页的 while 循环，使他不再需要块，观察改写之后的代码，可读性是提高了还是降低了。
```cpp
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
int main()
{

    int sum = 0;
    int val = 1;
    while (val <= 10)
    {
        sum += (val++);
    }
    cout << sum << endl;

    return 0;
}
```

### ex5.4
说明下列例子的含义，如果存在问题，试着修改它；
```cpp
while(string::iterator iter != s.end()) {/**/}; //死循环
while(bool status = find(word)) {
  if(!status) {/**/} // if 语句不会进入
}
```
> 第一个需要将迭代器赋值初始值，并移动
> 第二个 if 永远不会被执行
```cpp
string::iterator iter = s.begin();
while((iter++) != s.end()) {/**/};

if(!find(word)) {
/**/
}

while(!find(word)) {/**/}

```
### ex5.5 
写一段自己的程序，使用 if else 语句实现把数字成绩转换成字母成绩的要求；
[ch05/ex_5.5.cpp](ch05/ex_5.5.cpp)

### ex5.6
改写上一题的程序，使用条件运算符（?:）代替 if else 语句
[ch05/ex_5.6.cpp](ch05/ex_5.6.cpp)

### ex5.7
改正下列代码中的错误
```cpp
//a
if(ival1 != ival2)
  ival1 = ival2
else ival1 = ival2 = 0;

//a 修改
if(ival1 != ival2) {
  ival1 = ival2;
} else {
  ival1 = ival2 = 0;
}

// b
if(ival < minval)
  minval = ival;
  occurs = 1;

//b 修改
if(ival < minval) {
  minval = ival;
  occurs = 1;
}

//c
if(int ival = get_val())
  cout << "ival = " << ival << endl;

//c 修改
int ival = get_val();
if(ival != 0)
  cout <<"ival = " << ival << endl;


//d
if(ival =0)
  ival = get_val();

//d 修改
if(ival == 0)
  ival = get_val();
```

### ex5.8
什么是垂悬 else? C++语言是如何处理 else 子句的？
> 没有与 else 匹配的 if 叫 垂悬 else
> else 与最近的一个 if 进行匹配


### ex5.9 
编写一段程序，使用一系列 if 语句统计从 cin 读入的文本中又多少个元音字母；a o e i u
[ch05/ex_5.9.cpp](ch05/ex_5.9.cpp)

### ex5.10
我们之前实现统计与元音字母的程序存在一个问题，如果原因字母以大写的形式出现，不会被统计在内。编写一段程序，及统计元音字母的小写形式，也统计大写形式，也就是说新程序遇到 'a' 和 'A' 都应该递增 aCnt 的值，以此类推。
[ch05/ex_5.10.cpp](ch05/ex_5.10.cpp)

### ex5.11
修改统计元音字母的程序，使其也能统计空格、制表符和换行符的数量。
[ch05/ex_5.11.cpp](ch05/ex_5.11.cpp)

### ex5.12
修改统计元音字母的程序，使其能统计以下含有两个字符的字符序列数量：ff、fl 和 fi；
[ch05/ex_5.12.cpp](ch05/ex_5.12.cpp)

### ex5.13
下面显示的每个程序都含有一个常见的编程错误，指出错误在哪里？然后修改他们
```cpp
//a
unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
char ch = next_text();
switch(ch) {
  case 'a': aCnt++; //遗漏了 break 语句
  case 'e': eCnt++; //遗漏了 break 语句
  default: iouCnt++; //遗漏了break 语句
}

//a fixed
switch(ch) {
  case 'a': aCnt++; break; 
  case 'e': eCnt++; break;
  default: iouCnt++; break;
}


// b
unsigned index = some_value();
switch(index) {
    case 1:
        int ix =  get_value();
        ivec[ix] = index;
        break;
    default:
        ix = ivec.size() -1;  //ix 未定义
        ivec[ix] = index; // 遗漏了 break 语句
}

//b fixed
unsigned index = some_value();
switch(index) {
    case 1:
        int ix =  get_value();
        ivec[ix] = index;
        break;
    default:
        int ix2 = ivec.size() -1;  //ix 未定义
        ivec[ix2] = index;
        break;
}

// c
unsigned evenCnt = 0, oddCnt = 0;
int digit = get_num() % 10;
switch(digit) {
    case 1,3,5,7,9: //case 错误
        oddCnt++;
        break;
    case 2,4,6,8,10: // case 错误
        evenCnt++;
        break; 
        // 缺少default语句，不会引起编译错误，但是建议补上
}


//c fixed
unsigned evenCnt = 0, oddCnt = 0;
int digit = get_num() % 10;
switch(digit) {
    case 1: case 3: case 5: case 7: case 9: 
        oddCnt++;
        break;
    case 2: case 4: case 6: case 8: case 10: 
        evenCnt++;
        break; 
    default: // 补上default语句
        break;
}


//d 
unsigned ival = 512, jval = 1024, kval = 4096;
unsigned bufsize;
unsigned swt = get_bufCnt();
switch(swt)  {
    case ival:  //case 标签的值不能用变量
        bufsize = ival * sizeof(int);
        break;
    case jval: //case 标签的值不能用变量
        bufsize = jval * sizeof(int);
        break;
    case kval: //case 标签的值不能用变量
        bufsize = kval * sizeof(int);
        break;
}


// d fixed
unsigned ival = 512, jval = 1024, kval = 4096;
unsigned bufsize;
unsigned swt = get_bufCnt();
switch(swt)  {
    case 512:  
        bufsize = ival * sizeof(int);
        break;
    case 1024: 
        bufsize = jval * sizeof(int);
        break;
    case 4096:
        bufsize = kval * sizeof(int);
        break;
    default: // 补上default语句
        break;
}
```

### ex5.14
编写一段程序，从标准输入中读取若干 string 对象，并查找连续重复出现的单词。所谓的连续重复出现的意思是：一个单词后面紧跟着这个单词本身。要求记录连续重复出现的最大次数以及对应的单词。如果这个单词存在，输出重复出现的最大次数；如果不存在，输出一条信息说明任何单词都没有连续出现过；
例如：输入是 how now now now brown cow cow，那么输出应该表明单词 now 连续出现了 3 次；

[ch05/ex_5.14.cpp](ch05/ex_5.14.cpp)


### ex5.15 
说明下列循环的含义并改正其中的错误
```cpp
//a ix 出了 for 循环的作用域，ix 未定义
for(int ix = 0; ix != sz; ++x) { /**/}
  if(ix != sz)
    //

//a fixed
for(int ix = 0; ix != sz; ++x) {
  //ix 仅可在这个作用域内使用
}


//b  fox 循环语法错误
int ix;
for(ix != sz; ++ix) { /**/ }

//b fixed
int ix;
for(; ix != sz; ++ix) { /**/ }

//c 每次执行 ix 和 sz 都自增，可能会导致死循环
for(int ix = 0; ix != sz; ++ix, ++sz) {
  /**/
}

//c fixed
for(int ix = 0; ix <= sz; ++ix) {
}
```

### ex5.16
while 循环特别适用于那种条件保持不变、反复执行操作的情况，例如，当未达到文件末尾时不断读取下一个值。for 循环则更像时在按步骤迭代，他的索引值在某个范围内依次变化。根据每种循环的习惯用法各自编写一段程序，然后分别用另一个循环改写。如果只能使用一种循环，你倾向于使用哪种呢？为什么？
```cpp
//循环读取字符串到 str 中打印出来
while(std::cin >> str) {
  cout << str << endl;
}
//循环输出 0 - 99 的值
for(int i = 0; i < 100; ++i) {
  cout << i << endl;
}
```

### ex5.17
假设又两个包含整数的 vector 对象，编写一段程序，检验其中一个 vector 对象是否时另一个的前缀。为了实现这一目标，对于两个不等长的 vector 对象，只需要挑出长度较短的那个，把它的所有元素和另一个 vector 对象比较即可。例如，如果两个 vector 对象的元素分别是 0、1、1、2 和 0、1、1、2、3、5、8，则程序的返回结果应该为真。
```cpp
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
int main()
{
    vector<int> v = {0, 1, 1, 2};
    vector<int> v2 = {0, 1, 1, 2, 3, 5, 8};
    bool flag = true;
    for (decltype(v.size()) i = 0; i < v.size(); ++i)
    {
        if (v[i] != v2[i])
        {
            flag = false;
            break;
        }
    }

    cout << "Mismatch: " << std::boolalpha << flag << endl;
    return 0;
}
```


### ex5.18
说明下列循环的含义并改正其中的错误。
```cpp
// a do while 缺少花括号
do
  int v1, v2;
  cout << "Please enter two numbers to sum:";
  if(cin >> v1 >> v2)
    cout << "Sum is: " << v1 + v2 << endl;
while(cin);

//a fixed
do {
  int v1, v2;
  cout << "Please enter two numbers to sum:";
  if(cin >> v1 >> v2)
    cout << "Sum is: " << v1 + v2 << endl;
} while(cin);


// b  while 循环条件是赋值语句，不正确的循环条件
do {
//
} while(int ival = get_response());

// b fixed
do {
  int ival = get_response();
} while(ival >= 0);


// c  如果 ival 不等于0，始终无法跳出循环
do {
  int ival = get_response();
} while(ival);
```


### ex5.19
编写一段程序，使用 do while 循环重复的执行下述任务：首先提示用户输入两个 string 对象，然后挑出较短的那个并输出它；
```cpp
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
int main()
{
    string s1;
    string s2;
    do
    {
        cout << "Enter two strings: " << endl;
        cin >> s1 >> s2;
        cout << (s1.length() > s2.length() ? s2 : s1) << endl;
    } while (cin);
    return 0;
}
```

### ex5.20
编写一段程序，从标准输入中读取 string 对象的序列直到连续出现两个相同的单词或者所有的单词都读完为止。使用 while 循环一次读取一个单词，当一个的那次连续出现两次时，使用 break 语句终止循环。输出连续重复出现的单词，或者输出一个消息说明没有任何单词时连续重复出现的。
```cpp
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
int main()
{
    string lastWord;
    string str;
    while (cin >> str)
    {
        if (lastWord.empty())
        {
            lastWord = str;
        }
        else
        {
            if (lastWord == str)
            {
                // 跳出循环
                cout << "Found continues word: " << lastWord << endl;
                lastWord = "";
                break;
            }
            else
            {
                lastWord = str;
            }
        }
    }

    if (!lastWord.empty())
    {
        cout << "Not found continues word" << endl;
    }
    return 0;
}
```

### ex5.21
修改 ex5.20 的程序，使其找到的重复单词必须以大写字母开头
```cpp
#include <iostream>
#include <vector>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
int main()
{
    string lastWord;
    string str;
    while (cin >> str)
    {
        if (!isupper(str[0]))
        {
            // 如果当前字符串首字母不是大写，则跳过
            continue;
        }
        if (lastWord.empty())
        {
            lastWord = str;
        }
        else
        {
            if (lastWord == str)
            {
                // 跳出循环
                cout << "Found continues word: " << lastWord << endl;
                lastWord = "";
                break;
            }
            else
            {
                lastWord = str;
            }
        }
    }

    if (!lastWord.empty())
    {
        cout << "Not found continues word" << endl;
    }
    return 0;
}
```


### ex5.22 
本节的最后一个例子跳回到 begin，其实使用循环能更好的完成该任务。重写这段代码，注意不再使用 goto 语句。
```cpp
begin:
  int sz = get_size();
  if(sz <= 0 ) {
    goto begin;
  }

//使用 while 重写

while(get_size() <= 0) {
  //执行循环逻辑
}
```

### 异常类定义
- exception 头文件定义了最通用的异常类 exception. 它只报告异常的发生，不提供任何额外信息
- stdexcept 头文件定义了几种常用的异常类，见下表
- new 头文件定义了 bad_alloc 异常类型
- type_info 头文件定义了 bad_cast 异常类型
  
| 异常定义 | 异常描述 |
|----------|----------|
|exception | 最常见的问题|
|runtime_error | 只有在运行时才能检测的问题|
|range_error| 运行时错误：生成的结果超出了有意义的值域范围|
|overflow_error| 运行时错误：计算上溢|
|underflow_error| 运行时错误：计算下溢|
|logic_error| 程序逻辑错误|
|domain_error|逻辑错误：参数对应的结果值不存在|
|invalid_argument| 逻辑错误：无效参数|
|length_error|逻辑错误：试图创建一个超出该类型最大长度的对象|
|out_of_range|逻辑错误：使用一个超出有效范围的值|


### ex5.23
编写一段程序，从标准输入读取两个整数，输出第一个数除以第二个数的结果。
```cpp
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
int main()
{
    int a, b;
    cin >> a >> b;
    cout << a / b << endl;
    return 0;
}
```

### ex5.24
修改你的程序，使得当第二个数是 0 时抛出异常。先不要设定 catch 子句，运行程序并真的为除数输入0， 看看会发生什么？
```cpp
#include <iostream>
#include <exception>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;
int main()
{
    int a, b;
    cin >> a >> b;
    if (b == 0)
    {
        throw std::runtime_error("division by zero");
    }
    int result = a / b;
    cout << "result= " << result << endl;

    return 0;
}
```

### ex5.25
修改上一题的程序，使用 try 语句去捕获异常。catch 的子句应该为用户输出一条提示信息，询问器是否输入新数并重新执行 try 语句块的内容；
```cpp
#include <iostream>
#include <exception>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;
int main()
{
    int a, b;

    while (cin >> a >> b)
    {
        try
        {
            if (b == 0)
            {
                throw std::runtime_error("division by zero");
            }
            int result = a / b;
            cout << "result= " << result << endl;
            break;
        }
        catch (std::runtime_error &e)
        {
            cout << "Caught exception: " << e.what() << endl;
            cout << "Please try again." << endl;
        }
    }

    return 0;
}
```


## ch06
### ex6.1
实参和形参的区别是什么？
> 实参是形参的初始值
> 实参的类型必须与对应的形参类型匹配

### ex6.2
请指出下列函数哪个有错误，为什么？应该如何修改这些错误呢？
```cpp
// a 错误，实际返回类型和函数返回类型无法对应，其次，s 的作用域就在 f() 函数内，返回局部变量可能会导致 s 被回收而获取到不确定的结果
int f() {
  string s;
  //.....
  return s;
}

//a fixed，仅仅只修改返回值类型
string f() {
  string s;
  //
  return s;
}

// b 错误，没有显示定义 f2 的返回值类型
f2(int i) { /**/ }

// b fixed
void f2(int i) { /**/ }

// c 错误，两个形参变量名一致
int calc(int v1, int v1) { /**/ }

// c fixed
int calc(int v1, int v2) { /**/ }

//d 缺少 {}
double square(double x) return x * x;

//d fixed
double square(double x) {return x * x};
```

### ex6.3
编写你自己的 fact 函数，上机检查是否正确
[ch06/ex_6.3.cpp](ch06/ex_6.3.cpp)

### ex6.4
编写一个与用户交互的函数，要求用户输入一个数字，计算生成该数字的阶乘。在 main 函数中调用该函数。
[ch06/ex_6.4.cpp](ch06/ex_6.4.cpp)

### ex6.5
编写一个函数，输出其实参的绝对值
```cpp
int abs(int n)
{
    return n >= 0 ? n : -n;
}
```


### ex6.6
说明形参、局部变量以及局部静态变量的区别。编写一个函数，同时用到这三种形式。
> 形参: 实在函数定义时声明的变量，用于接收调用时传递的参数
> 局部变量：在函数内部声明的变量，只在函数内部有效
> 局部静态变量：在函数内部声明，且在变量声明前加上 static 关键字；局部静态变量在函数调用之前保持其值，在函数外部不可见；不管该方法被调用多少次，该变量始终只有一份。
```cpp
#include <iostream>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;

// 这里不要用 int 如果超出范围了，可能会溢出
long long fact(int n) // n 是形参
{
    if (n <= 1)
    {
        return 1;
    }
    static int call_cnt; // call_cnt 是静态局部变量
    call_cnt++;
    cout << "call_cnt addr = " << &call_cnt << endl;
    int result = fact(n - 1) * n; // result 是局部变量
    cout << "result addr = " << &result << endl;
    return result;
}

int main()
{
    fact(2); // 调用 fact 函数
    cout << "-----------" << endl;
    fact(3); // 调用 fact 函数
    return 0;
}
```

### ex6.7
编写一个函数，当他第一次被调用时返回 0，以后每次被调用返回值+1；
```cpp
int add_call_cnt() {
  static int call_cnt = 0;
  return call_cnt ++;
}
```

### ex6.8
编写一个名为 Chapter6.h 的头文件，令其包含 6.1 节练习中的函数声明
[ch06/Chapter6.h](ch06/Chapter6.h)

### ex6.9 
编写你自己的 fact.cc 和 factMain.cc，这两个文件都应该包含上一小节的练习中编写的 Chapter6.h 头文件。通过这些文件，理解你的编译器是如何支持分离式编译的。
- [ch06/fact.cc](ch06/fact.cc)
- [ch06/factMain.cc](ch06/factMain.cc)

```shell
g++ factMain.cc fact.cc -o main -std=c++11 -Wall
```
  
### ex6.10
编写一个函数，使用指针形参交换两个整数的值。在代码中调用该函数，并输出交换后的结果，以此验证函数的正确性。
[ch06/ex_6.10.cpp](ch06/ex_6.10.cpp)

### ex6.11
编写并验证你自己的 reset 函数，使其作用于引用类型的参数
```cpp
void reset(int& a) {
  a++;
}
void reset(const int& a) {
  a++; //不允许，被定义成了常量引用
  cout << a << endl;
}
```

### ex6.12 
改写  6.2.1 节中练习 6.10 的程序，使用引用而非指针交换两个整数的值。你觉得哪种方法更易于使用呢？为什么？
```cpp
void swapr(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

//调用
swapr(a1, a2); 
```

### ex6.13
假设 T 是某种类型的名字，请说明一下两个函数声明的区别：
- 一个是 void f(T)
- 另一个是 void f(&T);

> void f(T) 是值传递，传递参数时会把参数拷贝一份到 T 中
> void f(&T) 是引用传递

### ex6.14
举一个形参应该是引用类型的例子，再举一个形参不能是引用类型的例子。
> 传入参数过大，值传递拷贝成本过高或者根本不能拷贝，那就应该使用引用
> 当函数比较简单，且不需要修改传入的参数，那就可以直接使用普通类型，避免不必要的引用开销；例如传入两个参数，计算参数相加的和，这种情况下就不需要使用引用；

### ex6.15
说明 find_char 函数中的三个形参为什么是现在的类型，特别说明为什么 s 是常量引用而 occurs 是普通引用？为什么 s 和 occurs 是引用类型而 c 不是？如果另 s 是普通引用会发生什么情况？如果另 occurs 是常量引用会发生什么情况？
```cpp
string::size_type find_char(const string &s, char c, string ::size_type &occurs) {
  auto ret =  s.size();
  occurs = 0;
  for(decltype(ret) i = 0; i != s.size(); ++i) {
    if(s[i] == c） {
      if(ret == s.size()) {
        ret = i;
      }
      ++occurs;
    }
  }
  return occurs;
}
```
> 因为不需要修改 s 的值，所以设置成常量引用，避免内部逻辑修改，occurs 是普通引用是因为在函数内部需要对 occurs 的值进行自增处理，声明成常量引用后，occurs 的值无法被修改
> s 是普通引用的话，如果在 find_char 修改了 s 的值，将会导致整个方法的业务逻辑错误；为了避免不必要的错误，设置成常量引用好些
> occurs 是常量引用，方法编译会报错，会提示无法对 occurs 的值做修改


### ex6.16
下面的这个函数虽然合法，但是不是特别有用。指出它的局限性并设法改善
```cpp
bool is_empty(string& s) {return s.empty();};
```
> 不对 s 进行修改，应该将 s 设置成常量引用
```cpp
bool is_empty(const string& s) {
  return s.empty();
}
```

### ex6.17
编写一个函数，判断 string 对象中是否含有大写字母。编写另一个函数，把 string 对象全部都改写成小写形式。在这两个函数中，你使用的形参类型相同吗？为什么？
> 不相同，第一个是常量引用，第二个是普通引用

[ch06/ex_6.17.cpp](ch06/ex_6.17.cpp)

### ex6.18
为下面的函数编写声明，从给定的名字中推测函数具备的功能；
- 名为 compare 的函数，返回布尔值，两个参数都是 matrix 类的引用
- 名为 change_val 的函数，返回 vector<int> 的迭代器，有两个参数：一个是 int，另一个是 vector<int> 的迭代器
```cpp
bool compare(const matrix& m1, const matrix& m2); //避免两个 matrix 对象
vector<int>::iterator change_val(const int& a, vector<int>::iterator& it1); //改变迭代器中的某些值
```

### ex6.19
假定有如下声明，判断哪个调用合法、哪个调用不合法。对于不合法的函数调用，说明原因。
```cpp
double calc(double);
int count(const string&, char);
int sum(vector<int>::iterator, vector<int>::iterator, int);
vector<int> vec(10);

//a
calc(23.4, 55.1); //不合法，calc 的声明只有一个参数
//b
count("abcda", 'a'); // 合法，因为 char 是值传递，会把 'a' 拷贝过去

//c
calc(66); //合法，会把 int 类型提升为 double 类型
//d
 sum(vec.begin(), vec.end(), 3.8); //合法，值传递，3.8 会转换成3拷贝过去
```

### ex6.20
形参引用什么时候应该是常量引用？如果形参应该是常量引用，而我们将其设置成了普通引用，会发生什么情况？
> 不对传入的参数做修改的时候，尽量设置成常量引用，避免对传入的参数误修改了
> 应该是常量引用，但设置成了普通引用，可能会导致传入的参数被修改，导致逻辑错误；

### ex6.21
编写一个函数，令其接受两个参数；一个是 int 型的数，另一个是 int 指针。函数比较 int 的值和指针所指的值，返回较大的那个。在该函数中，指针的类型应该是什么？
```cpp
int compare(int, int*); //函数声明

int compare(int a, int * b){
  return a > *b ? a : *b;
}
```

### ex6.22
编写一个函数，令其交换两个 int 指针
```cpp
void swapp(int*, int*);

void swapp(int* a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}
```

### ex6.23
参考本节介绍的几个 print 函数，根据理解编写你自己的版本。依次调用每个函数使其输入下面定义的 i 和 j
```cpp
int i = 0, j[2] = {0, 1};
void print(int*)
void print(int[2]);
void print(int&); //传递引用
void print(int(&)[2]); //传递引用
```

### ex6.24
描述下面的函数行为，如果代码中存在问题，请指出并改正；
```cpp
//没有显示传入数组的长度，如果传入数组的长度小于 10，会导致访问到非法数据
void print(const int ia[10]){
  for(size_t i = 0; i != 10; ++i) {
    cout << ia[i] << endl;
  }
}

// fixed
void print(const int ia[], const int size){
  for(size_t i = 0; i != size; ++i) {
    cout << ia[i] << endl;
  }
}
```

### ex6.25
编写一个 main 函数，令其接受两个实参。把实参的内容连接成一个 string 对象并输出出来
```cpp
// g++ main.cpp -o main -std=c++11 && main hello world
int main(int argc, char**argv) {
  string str1 = argv[1];  // hello
  string str2 = argv[2]; // world
  cout << str1 + str2 << endl; // helloworld
  return 0;
}
```

### ex6.26
编写一个程序，使其接受本届所示的选项：输出传递给main 函数的实参内容
```cpp
// g++ main.cpp -o main -std=c++11 && main hello world olleh dlrow
int main(int argc, char* argv[]) {
  cout << argc << endl; //命令行参数个数 5
  cout << argv[0] << endl; // main 
  cout << argv[1] << endl; // hello
  cout << argv[2] << endl; // world
  cout << argv[3] << endl; //olleh
  cout << argv[4] << endl; // dlrow
}
```

### ex6.27
编写一个函数，它的参数是 initializer_list<int> 类型的对象，函数的功能是计算列表中所有元素的和；
```cpp
int add(std::initializer_list<int> il)
{
    std::initializer_list<int>::iterator it = il.begin();
    int sum = 0;
    while (it != il.end())
    {
        sum += *it;
        ++it;
    }
    return sum;
}
```

### ex6.28
在 error_msg 函数中的第二个版本中包含 ErrCode 类型的参数，其中循环内的 elem 是什么类型？
```cpp
void error_msg(ErrCode e, initializer_list<string> il) {
  cout <<e.msg() << ": ";
  for(const auto &elem: il) { //const string& 
    cout << elem << " ";
  }
  cout << endl;
}
```
> const string&

### ex6.29
在范围 for 循环中使用 initializer_list 对象时，应该将循环控制变量类型声明为引用类型吗？为什么？

> 不行，应该将其设置成 const 类型的引用，因为 initializer_list 里面的对象都是常量，无法被修改；


### ex6.30
编译 200 页的 str_subrange 函数，看看你编译器是如何处理编译错误的。
```cpp
bool str_subrange(const string &str1, const string &str2) {
  if(str1.size() == str2.size()) {
    return str1 == str2;
  }
  auto size = (str1.size() < str2.size()) ? str1.size() : str2.size();
  for(decltype(size) i = 0; i != size; ++i) {
    if(str1[i] != str2[i]) {
      return; //  error: return-statement with no value, in function returning 'bool' [-fpermissive]
    }
  }
}
```

### ex6.31
什么情况下返回的引用无效？什么情况下返回的常量引用无效？
> 返回布局变量的引用可能会导致无效（在函数内部定义的局部变量），当方法结束的时候，局部变量会被回收，此时的引用就是一个无效的引用
>
> 如果函数参数是按值传递的，此时返回函数参数的引用也是一个临时对象的引用，该对象会在结束的时候被销毁
>
> 如果返回值是常量引用，此时返回局部变量的引用，也是无效的
>
> 如果返回值是常量引用，此时返回的是动态分配的内存，但在返回之前已经释放了内存，也是无效的；

### ex6.32
下面的函数合法吗？如果合法，说明其功能；如果不合法，修改其中的错误并解释原因
```cpp

int &get(int* array, int index) {return array[index];}

int main() {
  int ia[10];
  for(int i = 0; i != 10; ++i) {
    get(ia, i) = i;
  }
}
```
> 合法，就是给数组进行赋值，赋值分别为 0-9；需要注意，定义 ia[10] 没有赋值初始值，get 函数访问的实际上是一些未定义的值

### ex6.33
编写一个递归函数，输出 vector 对象的内容
```cpp
void print(vector<int>::const_iterator begin, vector<int>::const_iterator end)
{
    if (begin == end)
    {
        return;
    }
    cout << *begin << " ";
    print(++begin, end);
}
```
[ch06/ex_6.33.cpp](ch06/ex_6.33.cpp)

## ex6.34
如果 factorial 函数停止的条件如下所示，将会发生什么情况？
```
if(val != 0) 
```
> 会导致无限递归，直到程序崩溃

### ex6.35
在调用 factorial 函数时，为什么我们传入的值时 val-1 而非 val--？
```cpp
long long fact(int n)
{
    cout << n << endl;
    if (n <= 1)
    {
        return 1;
    }
    return n * fact(n--); //假设调用是 fact(5); —> 5*fact(5) 一直到程序崩溃
}

```
> 先使用 n 的值，在对 n 进行 -- ， n 是指传递，会导致无限递归

### ex6.36
编写一个函数的声明，使其返回数组的引用并且该数组包含 10 个 string 对象。不要使用尾置返回类型、decltype 或者类型别名
```cpp
string(&func(int))[10];
string(&func())[10]; 
```

### ex6.37
为上一题的函数在写三个声明，一个使用类型别名，另一个使用尾置返回类型，最有一个使用 decltype 关键字。
```cpp
//尾置返回类型
auto func() -> string(&)[10];

//类型别名
using reftype = string[10];
typedef int reftype[10];
reftype &func();

//decltype
string arr[10];
decltype(arr) &func();
```


### ex6.38
修改 arrPtr 的函数，使其返回数组的引用。
```cpp
int odd[] = {1, 3, 5, 7, 9};
int even[] = {0, 2, 4, 6, 8};
int (*attrPtr(int))[]; // 函数声明
decltype(odd) *attrPtr(int i)
{
    return (i % 2) ? &odd : &even;
}

using arrRef = int[]; 
int (&attrPtr2(int i))[]; // 函数声明
affRef& attrPtr2(int); //函数声明
arrRef &attrPtr2(int i)
{
    return (i % 2) ? odd : even;
}

int main()
{
    cout << (*attrPtr(1))[0] << endl;
    cout << attrPtr2(1)[0] << endl;
    return 0;
}
```

### ex6.39
说明在下面的每组声明中第二条声明语句是何含义？如果有非法的声明，请指出来。
```cpp
//a 是函数重载
int calc(int, int);
int calc(const int, const int);

//b 非函数重载，编译器报错
int get();
double get();

//c 函数重载
int* reset(int *);
double* reset(double *);
```

> 函数重载：在同一个作用域内，可以有多个函数具有相同的函数名，但它们的参数列表不同（参数的数量，类型或者顺序至少有一个不同）

### ex6.40
下面哪个声明是错误的？为什么？
```cpp
//a
int ff(int a, int b = 0, int c = 0);
//b 错误，默认值只能排在最右边
char * init(int ht = 24, int wd, char bckgrnd);

//b fixed
char * init(int wd, char bckgrnd, int ht = 24);
```

### ex6.41
下面的哪个调用时非法的？为什么？哪个调用虽然合法但显然于程序员的初衷不符？为什么？
```cpp
char *init(int ht, int wd = 80, char backgrnd = ' ');

//a 错误，必须要给 ht 赋值
init(); // fixed    init(20);

//b 正确
init(24, 10);

//c 错误，会把 * 转换成 int 类型赋值给 wd
init(14, '*');  // fixed init(14, 10, '*');
```

### ex6.42
给 mark_plural 函数的第二个形参赋予默认实参's'，利用新版本的函数输出单词 success 和 failure 的单数和复数形式；
```cpp
string make_plural(size_t ctr, const string &word, const string &ending) {
  return (ctr > 1) ? word + ending : word;
}

// fixed
string make_plural(size_t ctr, const string &word, const string &ending="s") {
  return (ctr > 1) ? word + ending : word;
}
```


### ex6.43
你会把下面的哪个声明和定义放在头文件中？哪个放在源文件中？为什么？
```cpp
//a 头文件中
inline bool eq(const BigInt&, const BigInt&){}

//b 源文件中
void putValues(int *arr, int size)
```
> 一般把内联函数和 constexpr 放在头文件中。

### ex6.44
将 6.2.2 节的 isShorter 函数改写成内联函数
```cpp
bool isShoter(const string &s1, const string &s2) {
  return s1.size() < s2.size();
}
// fixed
inline bool isShorter(const string &s1, const string &s2) {
  return s1.size() < s2.size();
}
```


### ex6.45
回顾前面练习中你编写的那些函数，它们应该是内联函数吗？如果是，将他们改写成内联函数；如果不是，说明原因；
> 对于一些简单的函数，如果它们被频繁调用，可以将它们定义成内联函数，例如比较大小等。
内联函数一般只是简单的展开，不会产生额外的开销

> 相对普通的函数来说，普通的函数在调用前要先存储寄存器，并在返回的时候恢复；也可能需要拷贝实参，或者程序转向一个新的位置继续执行等

### ex6.46
能把 isShorter 函数定义成 constexpr 函数吗？如果能，请将它改写。
```cpp
bool isShoter(const string &s1, const string &s2) {
  return s1.size() < s2.size();
}
```

> 不能，constexpr 函数要求函数体内只能包含常量表达式，不能包含循环、条件语句、递归等语句。
> 准确来说，常量表达式需要在编译的时候就能计算出来

### NDBUG 启用调试
```cpp
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    for (int i = 0; i < 10; ++i)
    {
#ifdef NDEBUG
        cout << __func__ << endl; //输出当前函数名称
#endif
        cout << i << "-- ";
    }

    return 0;
}
```
执行 `g++ main.cpp -o main -DNDEBUG` 定义了 NDEBUG 宏，使得 NDEBUG 生效

|宏|说明|
|---|---|
|__func__|返回当前函数名|
|__FILE__|返回当前源文件名|
|__LINE__|返回当前行号|
|__DATE__|返回编译日期|
|__TIME__|返回编译时间|

### ex6.47
改写 6.3.2 节练习中使用递归输出 vector 内容的程序，使其有条件的输出与执行过程有关的程序。例如，每次调用时输出 vector 对象的大小。分别在打开和关闭调试器的模式下编译并运行程序。
```cpp
void print(vector<int>::const_iterator begin, vector<int>::const_iterator end)
{
    if (begin == end)
    {
        return;
    }
    cout << *begin << " ";
    print(++begin, end);
}
```
[ch06/ex_6.47.cpp](ch06/ex_6.47.cpp)

### ex6.48
说明下面这个循环的含义，它对 assert 的使用合理吗？
```cpp
string s;
while(cin >> s && s != sought) {}
assert(cin); // 不合理，cin 可能已经处于错误状态
```
> 当输入流结束时（例如，用户输入了EOF，或者达到了文件末尾），cin会变为假（即cin.fail()或cin.eof()可能会返回true），这时assert(cin)会触发，并导致程序终止


### ex6.49
什么是候选函数？什么是可行函数？
> 候选函数是指可以用来匹配函数调用的函数，可行函数是指候选函数中最匹配的函数。

### ex6.50
已知有第 217 页对函数 f 的声明，对于下面的每一个调用列出可行函数。其中哪个函数是最佳匹配？如果调用不合法，是因为没有可匹配的函数还是因为调用具有二义性？
```cpp
void f();
void f(int);
void f(int, int);
void f(double, double = 3.14);

//a
f(2.56, 42); //可行函数 f(int, int); f(double, double=3.14) 二义性
//b
f(42); //可行函数 f(int);  void f(double, double = 3.14);最佳匹配 void f(int)；
//c
f(42, 0); //可行函数 f(int, int);  void f(double, double = 3.14); 最佳匹配 void f(int, int)；
//d
f(2.56, 3.14); // 可行函数 f(int, int); f(double, double=3.14) 最佳匹配 f(double, double=3.14)
```

### ex6.51
 编写 f 函数的四个版本，令其各输出一条可以区分的消息。验证上一个练习的答案，如果你回答错了，反复研究本节的内容；
[ch06/ex_6.51.cpp](ch06/ex_6.51.cpp)


### ex6.52
已知有如下声明
```cpp
void manip(int, int);
double dobj;
```
请指出下列调用中每个类型转换的等级。
```cpp
//a
manip('a', 'z'); //a z 转换成 int

//b
manip(55.4, dobj); //55.4 dobj 转换成 int

```

### ex6.53
说明下列每组声明中的第二条语句会产生什么影响，并指出那些不合法（如果有的话）
```cpp
// a
int calc(int&, int&);
int calc(const int&, const int&);

// b
int calc(char*, char*);
int calc(const char*, const char*);

//c 不合法，两个函数声明相同，都是 char类型的指针
int calc(char*, char*);
int calc(char* const, char* const);
```

### ex6.54
编写函数的声明，令其接受两个 int 形参，并且返回类型也是 int；然后声明一个 vector 对象，令其与元素是指向该函数的指针；
```cpp
int fun(int, int);
std::vector<int(*)(int, int)> vec;

//或者使用别名
using PF = int(*)(int, int);
std::vector<PF> vec;
```

### ex6.55
编写 4 个函数，分别对两个 int 类型的值执行加、减、乘、除运算；在上一题创建的 vector 对象中保存指向这些函数的指针；

[ch06/ex_6.55.cpp](ch06/ex_6.55.cpp)

### ex6.55
调用上述 vector 对象中的每个元素，并输出结果
```cpp

//方式1
int (*funPtr)(int, int); 
for (decltype(funPtr) it : funVec)
{
    cout << it(10, 2) << endl;
}
//方式二
using PF = int (*)(int, int);
// for (PF it : funVec)
// {
//     cout << it(10, 2) << endl;
// }
```


## ch07
### ex7.1
使用 2.6.1 节练习定义的 Sales_data 类未 1.6 节的交易处理程序写一个新的版本。

