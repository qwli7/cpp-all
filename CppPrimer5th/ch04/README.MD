
## ch04 表达式


## ch04 练习题
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

[ex_4.21.cpp](ex_4.21.cpp)

### ex4.22
本节的示例程序将成绩划分为 high，pass 和 fail 三种，扩展该程序使其进一步将 60 分到 75 分之间的成绩设定为 low pass。要求程序包含两个版本
- 一个版本只使用条件运算符
- 另一个版本使用 1 个或多个 if 语句。
哪个版本的程序更容易理解呢？为什么？

> if 条件版本版本，能明确看到进入 if 分支的条件逻辑

[ex_4.22.cpp](ex_4.22.cpp)

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

[ex_4.28.cpp](ex_4.28.cpp)

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
