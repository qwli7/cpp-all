






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

### ex6.34
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
使用 2.6.1 节练习定义的 Sales_data 类为 1.6 节的交易处理程序写一个新的版本。
[ch07/ex_7.1.cpp](ch07/ex_7.1.cpp)

- 成员函数的声明必须在类的内部，如果定义也在类内部实现，它会变成隐式的 inline 函数，例如常见的 set get 方法
- 作为接口的组成部分的非成员函数，它们的定义和声明都在类的外部

### ex7.2
曾在 2.6.2 节的练习中编写了一个 Sales_data 类，请向这个类添加 combine 和 isbn 成员。
```cpp
struct Sales_data
{
    // 新成员
    std::string isbn() const { return bookNo; }
    Sales_data &combine(const Sales_data &);
    double avg_price() const;

    // 成员
    std::string bookNo;
    unsigned units_sold = 0;
    double price = 0.0;
    double revenue = 0.0;
};
```

### ex7.3
修改 7.1.1 节的交易处理程序，令其使用这些成员
[ch07/ex_7.1.cpp](ch07/ex_7.1.cpp)

### ex7.4
编写一个名为 Person 的类，使其表示人员的姓名和住址。使用 string 对象存放这些元素，接下来的练习将不断充实这个类的其他特征
```cpp
typedef struct Person
{
    std::string name;
    std::string address;
} p;
```
[ch07/Person.h](ch07/Person.h)

### ex7.5
在你的 Person 类中提供一些操作使其能够返回姓名和住址。这些函数是否应该是 const 的呢？解释原因。
```cpp
typedef struct Person
{
    std::string name;
    std::string address;
    std::string get_name() const
    {
        return name;
    };
    std::string get_address() const
    {
        return address;
    }
} p;
```
[ch07/Person.h](ch07/Person.h)

### ex7.6 
对于函数 add、read、和 print 定义你自己的版本。
```cpp
//添加
Sales_data add(const Sales_data &a, const Sales_data &b) {
  Sales_data sum;
  sum.price = a.price + b.price;
  sum.venue = a.venue + b.venue;
  return sum;
}

//从流中读取
istream& read(istream& cin, Sales_data &trans) {
  cin >> trans.bookNo >> trans.price;
  return is;
}

//打印
ostream& print(ostream& cout, const Sales_data &trans) {
  cout << trans.bookNo << ... << endl;
}
```


### ex7.7
使用这些新函数重写 7.1.2 节练习中的交易程序


### ex7.8 
为什么 read 函数要将其 Sales_data 参数定义成普通的引用，而 print 将其参数定义成常量引用；
> read 需要改变传入的 Sales_data 的成员数据，print 只做输出，不做改变

### ex7.9
对于 7.1.2节练习中的代码，添加读取和打印 Person 对象的操作
[ch07/Person2.h](ch07/Person2.h)

[ch07/Person.cpp](ch07/Person.cpp)

### ex7.10 
在下面这条 if 语句中，条件部分的作用是什么？
```cpp
if(read(read(cin, data1), data2); //输入两个 Sale_datas 类型的数据，假设使用的类是 Sales_data
```

### ex7.11
在你的 Sales_data 类中添加构造函数，然后编写一段程序令其用到每一个构造函数。
```cpp
struct Sales_data
{
    // 构造函数
    Sales_data() = default;
    Sales_data(const std::string &s) : bookNo(s) {}
    Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), price(p)
    {
    }

    // 新成员
    std::string isbn() const { return bookNo; }
    Sales_data &combine(const Sales_data &);
    double avg_price() const;

    // 成员
    std::string bookNo;
    unsigned units_sold = 0;
    double price = 0.0;
    double revenue = 0.0;
};

//
Sales_data s1(); //默认构造函数
Sales_data s2("hello"); //Sales_data(const std::string &s) : bookNo(s) {}
Sales_data s3("hello", 1, 1.0);  // Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), price(p){}

```

### ex7.12
把只接受一个 istream 作为参数的构造函数定义到类的内部
```cpp
struct Sales_data
{
    // 构造函数
    Sales_data() = default;
    Sales_data(const std::string &s) : bookNo(s) {}
    Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), price(p)
    {
    }
    Sales_data(std::istream &is)
    {
        read(is, *this);
    }

    // 新成员
    std::string isbn() const { return bookNo; }
    Sales_data &combine(const Sales_data &);
    double avg_price() const;

    // 成员
    std::string bookNo;
    unsigned units_sold = 0;
    double price = 0.0;
    double revenue = 0.0;
};
```

### ex7.13
使用 istream 构造函数重写 229 页的程序
```cpp
Sales_data total(cin);
Sales_data trans(cin);
if(total.isbn() == trans.isbn(cin)) {
  total.combine(trans);
} else {
  print(cout, total) << endl;
  total = trans;
  return 0;
}
print(cout, total) << endl;
```

### ex7.14
编写一个构造函数，令其用我们提供的类内初始值显示的初始化成员。
```cpp
Sales_data() : bookNo(""), units_sold(0), price(0.0), revenue(0.0) {}
```

### ex7.15
为你的 Person 类添加正确的构造函数
```cpp
typedef struct Person
{
    Person()= default;
    Person(const std::string &nameStr, const std::string &addressStr) : name(nameStr), address(addressStr) {}
    Person(const std::string &nameStr): name(nameStr), address("") {}
    std::string name;
    std::string address;
    std::string get_name() const
    {
        return name;
    };
    std::string get_address() const
    {
        return address;
    }

} p;
```

### ex7.16
在类的定义中对于访问说明符出现的位置和次数有限定吗？如果有，是什么？什么样的成员应该定义在 public 说明符之后？什么样的成员应该定义在private说明符之后？
> 没有限定；如果某些成员不希望外界可以直接访问，可以将其设置成 private；希望外界可以直接访问的，可以设置成 public

### ex7.17
使用 class 和 struct 时有区别吗？如果有，是什么？
> struct 的默认访问权限是 public， class 的默认访问权限是 private

### ex7.18
封装是何含义？它有什么用处？
> 封装将对象的状态（数据成员）和行为（函数成员）绑定在一起，并隐藏对象的内部细节，只暴露必要的接口提供外部访问；
- 提高安全性
- 隐藏实现细节
- 增强可维护性
- 提高代码的可重用性

### ex7.19
在你的 Person 类中，你将把哪些成员声成 public 的？哪些成员设置成 private 的?
> name 和 address 设置成 private 的，对外提供 get 和 set 方法来访问这些对象。


### ex7.20
友元在什么时候有用？请列举出使用友元的利弊。
> 当一个方法不在类的类的内部进行声明，而又想访问当前类的私有属性，就必须将该方法标记成友元；
```cpp
class Person
{
    friend std::istream &read(std::istream &is, Person &person);
    friend std::ostream &print(std::ostream &os, const Person &person);

public:
    Person() = default;
    Person(const std::string &nameStr, const std::string &addressStr) : name(nameStr), address(addressStr) {}
    Person(const std::string &nameStr) : name(nameStr), address("") {}

private:
    std::string name;
    std::string address;

public:
    std::string get_name() const
    {
        return name;
    };
    std::string get_address() const
    {
        return address;
    }
};

//不在类的内部定义，但却想访问 Person 类的私有成员，就需要在类的内部将其声明为友元
std::istream &read(std::istream &is, Person &person);
std::ostream &print(std::ostream &os, const Person &person);
```

### ex7.21
修改你的 Sales_data 类使其隐藏实现的细节。你之前编写的关于 Sales_data 操作的程序应该可以继续使用，借助类的新定义重新编译该程序，确保其工作正常。
```cpp
class Sales_data
{
  //友元函数
    friend Sales_data add(const Sales_data &, const Sales_data &);
    friend std::ostream &print(std::ostream &, const Sales_data &);
    friend std::istream &read(std::istream &, Sales_data &);

public:
    // 构造函数
    Sales_data() = default;
    Sales_data(const std::string &s) : bookNo(s) {}
    Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), price(p)
    {
    }
    Sales_data(std::istream &is)
    {
        read(is, *this);
    }

    // 新成员
    std::string isbn() const { return bookNo; }
    Sales_data &combine(const Sales_data &);
    double avg_price() const;

private:
    // 成员
    std::string bookNo;
    unsigned units_sold = 0;
    double price = 0.0;
    double revenue = 0.0;
};

// 非成员函数
Sales_data add(const Sales_data &, const Sales_data &);
std::ostream &print(std::ostream &, const Sales_data &);
std::istream &read(std::istream &, Sales_data &);
```

### ex7.22
修改你的 Person 类，使其隐藏其细节;
```cpp
//Person.h
#include <string>
class Person
{
    // 友元函数
    friend std::istream &read(std::istream &is, Person &person);
    friend std::ostream &print(std::ostream &os, const Person &person);
    friend void getPerson(Person &person);

public:
    Person() = default;
    Person(const std::string &nameStr, const std::string &addressStr) : name(nameStr), address(addressStr) {}
    Person(const std::string &nameStr) : name(nameStr), address("") {}

private:
    std::string name;
    std::string address;

public:
    std::string get_name() const
    {
        return name;
    };
    std::string get_address() const
    {
        return address;
    }
};

// 读取
std::istream &read(std::istream &is, Person &person);
std::ostream &print(std::ostream &os, const Person &person);
void getPerson(Person &person);


// Person.cpp
#include "Person.h"
#include <iostream>

//友元函数的实现，不需要 Person 的域作用符
std::istream &read(std::istream &is, Person &person)
{
  //可以直接通过 对象.私有属性 的方式访问受保护的属性
    is >> person.name >> person.address;
    return is;
}

std::ostream &print(std::ostream &os, const Person &person)
{
 //可以直接通过 对象.私有属性 的方式访问受保护的属性
    os << person.name << " " << person.address;
    return os;
}

void getPerson(Person &person)  
{
 //可以直接通过 对象.私有属性 的方式访问受保护的属性
    std::cout << person.name << " " << person.address << std::endl;
}
```

### ex7.23
编写你自己的 Screen 类
```cpp
class Screen {
public:
  using pos = std::string::size_type;
private:
  pos m_width = 0;
  pos m_height = 0;
  pos m_cursor = 0;
  std::string contents;
};
```
### ex7.24
给你的 Screen 类添加三个构造函数；
- 一个默认构造函数
- 另一个构造函数接受宽高的值，然后将 contents 初始化成给定的空白；
- 第三个构造函数接受宽和高的值以及一个字符，该字符作为初始化之后的屏幕内容；
```cpp
class Screen {
public:
  Screen() = default;
  Screen(pos width, pos height): m_width(width), m_height(height), contents(width * height, ' ') {}
  Screen(pos width, pos height, char c):  m_width(width), m_height(height), contents(width * height, c){} 
public:
  using pos = std::string::size_type;
private:
  pos m_width = 0;
  pos m_height = 0;
  pos m_cursor = 0;
  std::string contents;
};
```

### ex7.25
Screen 能安全的依赖于拷贝和赋值操作的默认版本吗？如果能，为什么？
> 能，因为编译器会默认为我们提供默认的拷贝和赋值构造函数

### ex7.26
将 Sales_data::avg_price 定义成内联函数
```cpp
class Sales_data {
// ***
public:
  inline double avg_price() const {return price * count}; 
}
```

### ex7.27
给你自己的 Screen 类添加 move、set 和 display 函数，通过执行下面的代码检查你的类是否正确；
```cpp
Screen myscreen(5, 5, 'X');
myScreen.move(4, 0).set('#').display(cout);
cout << "\n";
myScreen.display(cout);
cout << "\n";

//output
xxxxxxxxxxxxxxxxxxxx#xxxx
xxxxxxxxxxxxxxxxxxxx#xxxx
```
[ch07/Screen.h](ch07/Screen.h)

### ex7.28
如果 move、set 和 display 函数返回的类型不是 Screen& 而是 Screen，则在上一个练习中将会发生什么情况？
> 第一次使用 myScreen 对象和第二次使用的不是同一个对象，因此第一次会发生修改，第二次无法进行修改
```cpp
//output
xxxxxxxxxxxxxxxxxxxx#xxxx
xxxxxxxxxxxxxxxxxxxxxxxxx
```
[ch07/Screen2.h](ch07/Screen2.h)

### ex7.29
修改你的 Screen 类，令  move、set 和 display 函数返回 Screen 并检查程序的运行结果，在上一个练习中你的推测是正确的吗？

[ch07/Screen2.h](ch07/Screen2.h)


### ex7.30
通过 this 指针使用成员的做法虽然合法，但是有点多余。讨论显示的使用指针访问成员的优缺点。
> 在类内部，可以省略 this

### ex7.31
定义一对类 X 和 Y，其中 X 包含一个指向 Y 的指针，而 Y 包含一个类型为 X 的对象；
[ch07/ex_7.31.h](ch07/ex_7.31.h)

### 友元
```cpp
class Scrren {
  friend class Window_mgr; //这个类将可以具有 Screen 里面所有属性的访问权限
  friend void Window_mgr::clean(ScreenIndex); //只开放某一个方法为友元方法，那么将只有这一个方法可以访问 Screen 里面的所有属性访问权限 
}
```

### ex7.32
定义你自己的 Screen 和 Window_mgr，其中 clear 是 Window_mgr 的成员，是 Screen 的友元
```cpp
class Screen {
  friend void Window_mgr::clear(int);
};

class Window_mgr{
private:
  std::vector<Screen> screens;
public:
  void clear(index);
}

```

### ex7.33
如果我们给 Screen 类添加一个如下所示的 size 成员，将发生什么情况？如果出现了问题，请尝试修改它？
```cpp
pos Screen::size() const {
  return m_width * m_height;
}
```
> 需要在 typedef std::string::size_type pos 之后定义，否则会提示 pos 未定义

### ex7.34
如果我们把 256 页 Screen 类的 pos 的 typedef 放到类的最后一行，会发生什么情况？
> 在 typedef 之前用 pos 声明的变量会报错，提示找不到 pos 的定义

### ex7.35
解释下面代码的含义，说明其中的 Type 和 initVal 分别使用了哪个定义。如果存在错误，请修改它
```cpp
typedef string Type;
Type initVal();

class Exercise {
public:
  typedef double Type;
  Type setVal(Type); // typedef double Type;
  Type initVal();  // typedef double Type;
private:
  int val;
};

Type Exercise::setVal(Type pram) { //typedef string Type;
  val = pram + initVal();
  return val;
}
```
- 类型定义冲突：（这种冲突会导致在类内部和内外部使用 Type 时，类型不一致引发编译错误）
  - 在文件的全局作用域中使用了 typedef string Type; 这意味着在全局作用域中 Type 是 string类型
  - 在 Exercise 类中，使用了 typedef double Type; 这意味着在 Exercise 类作用域中 Type 是 double 类型
- 函数重定义问题：
  - 在全局作用域中定义了 Type initVal();  在 Exercise 类中页定义了 Type initVal()
  - 虽然这两个函数的调用方式不同（一个通过对象调用，一个直接调用），但在同一个文件中定义相同签名的全局函数和类成员函数可能会导致混淆，尤其是在类外部调用时
  - 如果 initVal() 函数在类外部被实现，那么它与类内部的 initVal() 函数会产生冲突。如果类内部的 initVal 没有被实现，编译会报错
- 未定义行为：
  - Exercise::setVal(Type pram) 方法中调用了 initVal() 函数，但并没有提供这个类成员的具体实现，导致链接错误。因为编译器在链接阶段找不到 Exercise::initVal() 定义
  - 如果 initVal() 作为类成员函数被调用，但其实现位于类外部，应该使用 Exercise::initVal() 来确保正确链接；
```cpp
#include <string>
using std::string;
typedef string GlobalType;
// Type initVal();

class Exercise
{
public:
    typedef double ClassType;
    ClassType setVal(ClassType);
    ClassType initVal();

private:
    int val;
};

Exercise::ClassType Exercise::setVal(Exercise::ClassType pram)
{
    val = static_cast<int>(pram) + static_cast<int>(initVal());
    val = pram + initVal();
    return val;
}

```

### ex7.36
下面的初始值时错误的，请找出问题所在并尝试修改它；
```cpp
struct X {
  // 初始化 rem 时会提示 base 未定义
  X(int i, int j): base(i), rem(base%j) {}
  int rem, base;
};

//fixed
struct X {
  X(int i, int j): base(i), rem(i%j) {}
  int rem, base;
};

```

### ex7.37
使用本机提供的 Sales_data 类。确定初始化下面的变量时分别使用了哪个构造函数，然后罗列出每个对象所有的数据成员的值
```cpp
Sales_data first_item(cin);  // Sales_data(std::istream &is)
int main() { 
  Sales_data next; // Sales_data(std::string s = "");
  Sales_data last("9-999-99999-9"); //  Sales_data(std::string s = "");
}
```

### ex7.38
有些情况下，我们希望提供 cin 作为接受 istream&  参数的构造函数的默认实参，请声明这样的构造函数
```cpp
 Sales_data(std::istream &is = std::cin) {}
```

### ex7.39
如果接受 string 的构造和接受 istream& 的构造函数都是用默认实参，这种行为合法吗？如果不，为什么？
> 不合法，在使用默认构造函数创建对象的时候，编译器不知道该选定哪个构造函数，出现二义性

### ex7.40
从下面的抽象概念中选择一个（或者你自己指定一个），思考这样的类需要哪些数据成员，提供一组合理的构造函数，并阐明这样做的原因
- Book
- Date
- Employee
- Vehicle
- Object
- Tree

```cpp

class Book {
  std::string name;
  std::string no;
  double price;
  std::string author;
  std::string pubDate; 
};
```

### ex7.41
使用委托构造函数重写编写你的 Sales_data 类，给每个构造函数添加一条语句，令其一旦执行就打印一条信息。用各种可能的方式分别创建 Sales_data 对象，认真研究每次输出的信息直到你确实理解了委托构造函数的执行顺序；
[ch07/ex_7.40.cpp](ch07/ex_7.40.cpp)

**委托构造函数，就是使用其他的构造函数来帮助自己完成初始化功能**

### ex7.42
对于你正在练习 7.40 中编写的类，确定哪些构造函数可以使用委托。如果可以的话，编写委托构造函数。如果不可以，从抽象概念列表中重新选择一个你认为可以使用委托构造函数的，为挑选出的这个概念编写类定义。
```cpp
class Book {
  std::string name;
  std::string no;
  double price;
  std::string author;
  std::string pubDate;
public:
  Book(): Book(""){} //委托Book(const std::string &na)构造函数实现
  Book(const std::string &na): name(na) {} 
};
```

### ex7.43
假定有一个名为 NoDefault 的类，它有一个接受 int 的构造函数，但是没有默认构造函数。定义类 C，C 有一个 NoDefault 的类型成员，定义 C 的默认构造函数
```cpp
class NoDefault
{
private:
    int m_x;

public:
    NoDefault(int x) : m_x(x) {}
};

class C
{
private:
    NoDefault m_nd;

public:
    C() {}  //默认构造函数，编译会报错，提示 NoDefault 没有默认构造函数，改成  C(): m_nd(0) {} 即可
}
```

### ex7.44
下面这条声明合法吗？如果不，为什么？
```cpp
vector<NoDefault> vec(10); // NoDefault 没有默认构造函数，不合法
```

### ex7.45
如果在上一个练习中定义的 vector 的元素类型是 C，则声明合法吗？为什么？
> 不合法，因为 C 依赖了 NoDefault，而 NoDefault 没有默认构造函数，不合法

### ex7.46
下面哪些论断是不正确的？为什么？
- a）一个类必须至少提供一个构造函数。 （不正确，如果不提供，编译器会默认帮我们创建构造函数，析构函数以及拷贝构造函数）
- b）默认构造函数是参数列表为空的构造函数。（正确）
- c）如果对于类来说不存在有意义的默认值，则类不应该提供默认构造函数（不完全正确，可提供默认构造函数，空实现，也可不提供）
- d）如果类没有定义默认构造函数，则编译器将为其生成一个并把每个数据成员初始化成相应类型的默认值（正确，如果是自定义的类的话，需要看类的具体定义）

### ex7.47
说明接受一个 string 参数的 Sales_data 构造函数是否应该是 explicit 的，并解释这样做的优缺点。

优点
- 防止隐式转换，标记为 explicit 可以防止编译器使用这个构造函数进行隐式转换。如果你没有使用 explicit，可以这样写  Sales_data sd = "12345"；这会隐式调用 Sales_data(const string& s) 这个构造函数，使用 explicit 可以避免这种隐式转换，代码逻辑更清晰
- 提高代码的安全行和可读性：明确告诉编译器和阅读代码的人，这个构造函数不应该使用隐式转换。有助于保持代码的一致性和可读性
缺点
- 限制了隐式转换的规则：如果你的应用场景确实需要允许这种隐式转换，那么 explicit 会阻止这种用法，你需要显式的调用构造函数来创建对象，可能会增加一些代码量
- 可能会影响某些初始化方式：在某些情况下，你可能希望使用自动类型转换来简化对象的初始化过程，explicit 会限制这种用法

```cpp

class NoDefault
{
private:
    int m_x;

public:
    explicit NoDefault(int x) : m_x(x)  //explicit 组织隐式转换
    {
        std::cout << "NoDefault(int x) called" << std::endl;
    }
};

class C
{
private:
    NoDefault m_nd;

public:
    C() : m_nd(0) {}
};

int main()
{
    // NoDefault nd = 10; // 会隐式调用 NoDefault(int x) 函数
    NoDefault nd2(20); // 加上 explicit 后，只能通过显式调用的方式来创建
    return 0;
}
```

### ex7.48
假设 Sales_data 的构造函数不是 explicit 的，则下述定义将执行什么样的操作？
```cpp
string null_isbn("9-999-99999-9"); //调用 string 的显式构造函数
Sales_data item(null_isbn); //调用Sales_data的显式构造函数
Sales_data item2("9-999-99999-9"); //调用Sales_data的显式构造函数

```

### ex7.49
对于 combine 函数的三种声明，当我们调用 i.combine(s) 是，分别发生了什么情况？其中 i 是一个 Sales_data，而 s 是一个 string 对象
```cpp
Sales_data &combine(Sales_data); //调用 Sales_data 构造函数，发生了隐式转换，s 被转换成了Sales_data 对象传入，临时对象
Sales_data &combine(Sales_data&); //调用 Sales_data 构造函数，发生了隐式转换，s 被转换成了Sales_data 对象传入，原对象
Sales_data &combine(const Sales_data& ) const ; //调用 Sales_data 构造函数，发生了隐式转换，s 被转换成了Sales_data 对象传入，常量对象
```

### ex7.50
确定在你的 Person 类中是否有一些构造函数应该是 explicit 的。
```cpp
#include <string>
class Person
{
    // 友元函数
    friend std::istream &read(std::istream &is, Person &person);
    friend std::ostream &print(std::ostream &os, const Person &person);
    friend void getPerson(Person &person);

public:
    Person() = default;
    Person(const std::string &nameStr, const std::string &addressStr) : name(nameStr), address(addressStr) {}
    Person(const std::string &nameStr) : name(nameStr), address("") {}

private:
    std::string name;
    std::string address;

public:
    std::string get_name() const
    {
        return name;
    };
    std::string get_address() const
    {
        return address;
    }
};

// 读取
std::istream &read(std::istream &is, Person &person);
std::ostream &print(std::ostream &os, const Person &person);
void getPerson(Person &person);

```
看个人习惯和使用场景，如果有大量的 Person p = "name" 这种初始化的方式，那就不能对 Person(const std::string &nameStr) 限制隐式转换，反之则建议限制

### ex7.51
vector 将其单参数的构造函数定义成 explicit 的，而 string 不是，你觉得原因何在？
- vector 的设计更强调类型安全和明确性，其单参数构造函数主要是为了初始化一个具有特定大小的容器，如果使用 explicit 可以更好地防止不必要的隐式类型转换，避免程序中的错误。
- string 类型在很多情况下需要与 C 风格的字符串（即字符数组）进行交互，为了方便这些场景下的使用，string 的构造函数没有使用 explicit。这使得从字符数组到 string 的转换更加自然和简洁。

### ex7.52
使用 Sales_data 类，解释下面的初始化过程，如果存在问题，请修改它
```cpp
Sales_data item = {"978-0590353403", 25, 15.99};

//fixed 属性必须是 public的，顺序必须和定义时候的顺序一致
struct Sales_data {
  std::string bookNo;
  unsigned price;
  double revenue;
};
```

### ex7.53
定义你自己的 Debug 类
```cpp
class Debug
{
public:
    constexpr Debug(bool b = true) : hw(b), io(b), other(b) {}
    constexpr Debug(bool h, bool i, bool o) : hw(h), io(i), other(o) {}
    constexpr bool any()
    {
        return hw || io || other;
    }
    void set_hw(bool b)
    {
        hw = b;
    }
    void set_io(bool b)
    {
        io = b;
    }
    void set_other(bool b)
    {
        other = b;
    }

private:
    bool hw;
    bool io;
    bool other;
};
```

### ex7.54
Debug 中以  set_ 开头的成员应该被声明称 constexpr 吗？如果不，为什么？
> 不应该

### ex7.55
7.5.5 节的 Data 类是字面值常量类吗？请解释原因。
```cpp
struct Data{
  int ival;
  string s;
}
```
- 类中的所有成员都必须是字面值常量表达式类型的。
- 类必须至少有一个 constexpr 构造函数。
- 类中不能有虚函数。
- 类中所有非静态成员变量都必须是 public 且是常量表达式类型的。

不是字面值常量类
- 缺少 constexpr 构造函数
- 成员 s 是 std::string 类型，在编译时期不能确定大小

### ex7.56
什么是类的静态成员？它有何有点？静态成员与普通成员有何区别？
> 定义在类中，所有的类共享同一份数据的成员叫静态成员，用 static 修饰
优点：
- 所有的类共享同一份数据

区别：
- 类的静态成员和类没有关系，不需要通过 . 运算符来获取，定义在类中，可以通过域作用符获取静态成员的数据
- 类的静态成员不是在类的实例化时创建的。没有 this 指针

### ex7.57
编写你自己的 Account 类。
```cpp
class Account {
public:
  static double rate() { return interestRate;}
  static void rate(double);
private:
  static constexpr int period = 30;
  double daily_tbl[peroid];
}
```

### ex7.58
下面的静态数据成员的声明和定义有错吗？请解释原因。
```cpp
//example.h
class Example {
public:
  static double rate = 6.5;  //需要声明为 const 类型， static const double rate = 6.5
  static const int vecSize = 20;
  static vector<double> vec(vecSize);
};
//example.C
#include "example.h"
double Example::rate;
vector<double> Example::vec;
```
fiexd
```
class Example
{
public:
    static double rate;
    static const int vecSize = 20;
    static vector<double> vec;
};

//类外部定义，并初始化成员
double Example::rate = 1.0;
vector<double> vec(Example::vecSize);
int main()
{
    return 0;
}
```

## ch08
### ex8.1
编写函数，接收一个 istream& 参数，返回类型也是 istream&。此函数须从给定的流中读取数据，直至遇到文件结束标识时停止。它将读取的数据打印在标准输出上。完成这些操作后，在返回流之前对流进行复位。使其处于有效状态
```cpp
std::istream &read(std::istream &is)
{
    int n;
    while (is >> n)
    {
        cout << n << " ";
    }
    if (is.eof()) // 遇到文件结束符
    {
        cout << "EOF" << endl;
    }
    if (is.fail()) // 输入失败，如果输入的类型不是 int
    {
        cout << "Fail" << endl;
    }
    if (is.bad())
    {
        cout << "Bad" << endl;
    }

    is.clear();
    return is;
}
```

### ex8.2
测试函数，调用参数 cin
```cpp
int main() {
  read(std::cin)
}
```

### ex8.3
什么情况下 while 循环会中止
```cpp
while(cin >> i) {}; //读取到文件末尾，读取不正确的数，读取到结束符 etc
```

### ex8.4
编写函数，以只读模式打开一个文件，将其内容读入到一个 string 的 vector 中，将每一行作为一个独立的元素存于 vector 中
```cpp
std::vector<std::string> readFileToVector(const std::string &filename)
{
    std::vector<std::string> lines;
    std::ifstream file(filename); // 以只读模式打开文件
    if (!file.is_open())
    {
        std::cerr << "open file " << filename << " failed!" << std::endl;
        return lines;
    }
    std::string line;
    while (std::getline(file, line))
    {
        // 逐行读取文件内容
        lines.push_back(line);
    }
    file.close();
    return lines;
}
```
[ch08/ex_8.4.cpp](ch08/ex8.4.cpp)

### ex8.5.cpp
重写上面的程序，将每个单词作为一个独立的元素存储。
```cpp
std::vector<std::string> readFileToVector(const std::string &filename)
{
    std::vector<std::string> lines;
    std::ifstream file(filename); // 以只读模式打开文件
    if (!file.is_open())
    {
        std::cerr << "open file " << filename << " failed!" << std::endl;
        return lines;
    }
    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream iss(line); // 字符串流
        std::string word;
        while (iss >> word)
        {
            lines.push_back(word);
        }
    }
    file.close();
    return lines;
}
```
[ch08/ex_8.5.cpp](ch08/ex8.5.cpp)

### ex8.6
重写 7.1.1 节的书店程序，从一个文件中读取交易记录，将文件名作为一个参数传递给 main
[ch08/ex_8.6.cpp](ch08/ex8.6.cpp)


### ex8.7
修改上一节的书店程序，将结果保存到一个文件中。将输出文件名作为第二个参数传递给 main 函数
[ch08/ex_8.7.cpp](ch08/ex8.7.cpp)

### ex8.8
修改上一题的程序，将结果追加到指定的文件末尾。对同一个输出文件，运行程序至少两次，检验数据是否得以保留。
[ch08/ex_8.8.cpp](ch08/ex8.8.cpp)

模式可通过位或（|）组合，如ios::out | ios::binary。
|模式|解释|
|----|----|
|ios::in| 读取 `ifstream` 默认|
|ios::out| 写入 `ofstream` 默认|
|ios::app| 追加，写入文件到末尾|
|ios::binary| 二进制模式，避免文本转换|
|ios::ate| 打开后定位到文件末尾(at end)|

### ex8.9
使用 ex8.5.cpp 节的练习，打印 istringstream 对象的内容
```cpp
std::vector<std::string> readFileToVector(const std::string &filename)
{
    std::vector<std::string> lines;
    std::ifstream file(filename); // 以只读模式打开文件
    if (!file.is_open())
    {
        std::cerr << "open file " << filename << " failed!" << std::endl;
        return lines;
    }
    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream iss(line); // 字符串流
        std::string word;
        while (iss >> word) //读取单词
        {
            lines.push_back(word);
        }
    }
    file.close();
    return lines;
}
```

### ex8.10
编写程序，将来自一个文件中的行保存在一个 vector<string> 中，然后使用一个 istringstream 从 vector 中读取元素，每次读取一个单词；
[ch08/ex_8.10.cpp](ch08/ex_8.10.cpp)


### ex8.11
本节的程序在外层 while 循环中定义了 istringstream 对象。如果 record 对象定义在循环之外，你需要对程序进行怎样的修改？重写程序，将 record 的定义转移到 while 循环之外，验证你设想的修改方法是否正确
[ch08/ex8.11.cpp](ch08/ex_8.11.cpp)

### ex8.12
我们为什么没有在PersonInfo 中使用类内初始化？
>  PersonInfo 的属性由 cin 提供，在该例子中不需要使用类内初始化的能力

### ex8.13
重写本节的电话号码程序，从一个命名文件而非 cin 读取数据。
[ch08/ex_8.13.cpp](ch08/ex_8.13.cpp)

### ex8.14
我们为什么将 entry 和 nums 定义为 const auto & ？
> 仅仅只是打印，不需要修改，所以声明为 const，声明为引用是为了避免值传递

## ch09
### 顺序容器

|类型|描述|
|:----:|:----:|
|vector|可变大小数组，支持快速随机访问。在尾部之外的位置插入或者删除元素可能很慢|
|deque|双端队列。支持快速随机访问。在头部和尾部插入、删除速度很快|
|list|双向链表。支持支双向顺序访问。在 list 中任何位置进行插入、删除操作速度都很快|
|forword_list|单向链表。只支持单向顺序访问。在链表的任何位置进行插入、删除操作速度都很快|
|array|固定大小数组。支持快速随机访问，不能添加或者删除元素|
|string|与 vector 相似的容器，但专门用于保存字符。随机访问块、在尾部补插入、删除速度快|

一般来说，使用 `vector` 是最好的选择，除非你有很好的理由选择其他容器；

### ex9.1
对于下面的程序任务，vector deque 和 list 选择哪种容器更加适合？解释你选择的理由。如果没有哪一种容器优于其他容器，也请解释理由。
- 读取固定数量的单词，将它们按照字典顺序插入到容器中。我们将在下一章中看到，关联容器更适合这个问题  -> list
- 读取未知数量的单词，总是将新单词插入到末尾，删除操作在头部进行   -> deque
- 从一个文件读取位置数量的整数。将这些数排序，然后将它们打印到标准输出。 -> vector

### ex9.2
定义一个 list 对象，其元素类型是 int 类型的 deque
```cpp
#include <list>
#include <deque>

int main() {
  list<deque<int>> list;
  return 0;
}
```

### ex9.3
构成迭代器范围的迭代器有何限制
- 左闭右开区间 [a, b);
- end 指向尾部元素的下一个元素
- end == begin 表示容器为空 end != begin 表示容器不为空
- end 不能小于 begin

### ex9.4
编写函数，接收一对指向 vector<int> 的迭代器和一个 int 值。在两个迭代器指定的范围中查找给定的值，返回一个 bool 来指出是否找到；
```cpp
bool find_int(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end, int value)
{
    while (begin != end)
    {
        if (*begin == value)
        {
            return true;
        }
        ++begin;
    }
    return false;
}

```

### ex9.5
重写上一题的函数，返回一个迭代器指向找到的元素。注意，程序必须处理未找到给定值的情况
```cpp
int find_int(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end, int value)
{
    while (begin != end)
    {
        if (*begin == value)
        {
            return *begin;
        }
        begin++;
    }
    return -1; // -1 表示未找到
}
```

### ex9.6
下面的程序有何错误？你应该如何修改它？
```cpp
std::list<int> lst1;
std::list<int>::iterator iter1 = lst1.begin(), iter2 = lst1.end();
while (iter1 < iter2)  // list 的迭代器不能比较大小，应该用 !=
{ /**/
}
```

### ex9.7
为了索引 int 的 vector 中的元素，应该使用什么类型？
> std::vector<int>::const_iterator

### ex9.8
为了读取 string 的 list 中的元素，应该使用什么类型？如果写入 list，又该使用什么类型？
- 读取 std::list<string>::const_iterator
- 写入 std::list<string>::iterator

const_iterator 支持只读访问，iterator 支持读写访问

### ex9.9
begin 和 cbegin 两个函数有什么不同？
> 一个获取读写迭代器，一个获取只读迭代器

### ex9.10
下面 4 个对象分别是什么类型？
```cpp
vector<int> v1;
const vector<int> v2;
auto it1 = v1.begin(), it2 = v2.begin();  // it1 iterator, it2 const_iterator
auto it3 = v1.cbegin(), it3 = v2.cbegin(); //it3 const_iterator, it4 const_iterator
```

### ex9.11
对 6 中创建和初始化的 vector 对象的方法，每一种都给出一个示例。解释每个 vector 包含什么值
```cpp
  std::vector<int> v;  //创建一个 vector
  std::vector<int> v1 = {1, 2, 3, 4, 5}; //创建一个 v，里面的值是 1 2 3 4 5 
  // std::vector<int> v2 = {10};
  // std::vector<int> v2{0};
  std::vector<int> v3(10, 1); //创建一个vector, 里面是 10 个 1
  std::vector<int> v4(v3.begin(), v3.end()); //利用 v3 创建 v4，内容和 v3 一样
  std::vector<int> v5(v4); //拷贝 v4 的内容到 v5
```

### ex9.12
对于一个接收容器创建其拷贝的构造函数，和接受两个迭代器创建拷贝的构造函数，解释它们的不同。
```cpp
std::vector<int> v4(v3); //全量拷贝
std::vector<int> v5(v4.begin(), v4.end()); //可指定范围
```

### ex9.13
如何从一个 list<int> 初始化一个 vector<double>？从一个 vector<int> 又该如何创建。
```cpp
std::list<int> list = {1, 2, 3, 4, 5};
std::vector<double> vec;
for (auto i : list)
{
    vec.push_back(i);
}

// 从 vector int 创建 
std::vector<int> list = {1, 2, 3, 4, 5};
std::vector<double> vec(list.begin(), list.end()); //或者使用迭代器 
```

### ex9.14
编写程序，将一个 list 中的 char* 元素赋值给一个 vector 的中的 string
```cpp
int main()
{

    //如果使用字面值常量，记得不要遗漏 const，编译会有警告 
    //ISO C++ forbids converting a string constant to 'char*'
    std::list<const char *> list = {"hello", "world", "c++", "stl"}; 
    std::vector<std::string> vec;

    for (auto i : list)
    {
        vec.push_back(i);
    }
    for (auto i : vec)
    {
        cout << i << endl;
    }
    return 0;
}
```

### ex9.15
编写程序，判断两个 vector<int> 是否相等
```cpp
int main()
{
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::vector<int> vec2 = {6, 7, 8, 9, 10};
    std::vector<int> vec3 = {1, 2, 3, 4, 5};
    std::cout << std::boolalpha << (vec2 != vec) << endl;
    std::cout << std::boolalpha << (vec == vec3) << endl;
    return 0;
}

```

### ex9.16
重写上一题的程序，比较一个 list<int>中的元素和一个 vector<int>中的元素
```cpp
int main()
{
    std::vector<int> vec = {1, 2, 3, 4, 5};
    // std::list<int> list = {6, 7, 8, 9, 10};
    // std::list<int> list = {1, 2, 3, 4, 5};
    std::list<int> list = {1, 2, 3, 4};
    if (vec.size() != list.size())
    {
        cout << "Not equal" << endl;
        return 0;
    }
    bool equal = true;
    decltype(vec.size()) i = 0;
    std::list<int>::const_iterator it = list.cbegin();
    while (it != list.cend())
    {
        if (*it != vec[i])
        {
            equal = false;
            break;
        }
        ++it;
        ++i;
    }
    if (equal)
    {
        cout << "Equal" << endl;
    }
    else
    {
        cout << "Not equal" << endl;
    }
    return 0;
}

```

### ex9.17
假定c1 和 c2 是两个容器，下面的比较操作有何限制
```cpp
if(c1 < c2)  // < 只有 vector 支持
```

### ex9.18
编写程序，从标准输入中读取 string 序列，存入到一个 deque 中。编写一个循环，用迭代器来打印 deque 中的元素。
[ch09/ex_9.18.cpp](ch09/ex_9.18.cpp)

### ex9.19
重写上一题程序，用 list 替代 deque。列出程序需要做出哪些改变？
[ch09/ex_9.19.cpp](ch09/ex_9.19.cpp)

### ex9.20
编写程序，从一个 list<int> 拷贝元素到两个 deque 中。值为偶数的所有元素都拷贝到一个 deque 中，值为奇数值元素都拷贝到另一个 deque 中。
[ch09/ex_9.20.cpp](ch09/ex_9.20.cpp)


### ex9.21
如果将我们第 308 页中使用 insert 返回值将元素添加到 list 中的循环程序改写为将元素插入到 vector 中，分析循环将如何工作？
```cpp
list<string> lst;
auto iter = lst.begin();
while(cin>>word) {
  iter = lst.insert(iter, word);
}
//改为 vector，也是往 vector 头部开始插入元素
vector<string> vec;
auto iter = vec.begin();
while(cin >> word) {
  iter = vec.insert(iter, word);
}
```
> 也是往 vector 头部开始插入元素

### ex9.22
假定 iv 是一个 int 类型的 vector，下面的程序存在什么错误？你将如何修改？
```cpp
vector<int>::iterator iter = iv.begin(), mid = iv.begin() + iv.size() / 2;
while (iter != mid)
{
    if (*iter == some_val)
    {

        iv.insert(iter, 2 * some_val);
    }
    cout << *mid << endl;
}
```
> 可能会导致死循环，因为 insert 会改变容器的大小和元素的位置，导致迭代器失效。
```cpp
//fixed
std::vector<int> iv = {1, 2, 10, 4, 5};
int some_val = 3;
vector<int>::iterator iter = iv.begin(), mid = iv.begin() + iv.size() / 2;
while (iter != mid)
{
    if (*iter == some_val)
    {

        iter = iv.insert(iter, 2 * some_val) + 1; // 插入后 iter 指向新的元素
    }
    else
    {
        ++iter;
    }
    cout << *mid << endl;
}
```

### ex9.23
在本节中第一个程序，若 c.size() 为 1，则 val、val2、val3 和 val4 的值是什么？
```cpp
if(!c.empty()) {
  auto val = *c.begin(), val2 = c.front();
  auto last = c.end();
  auto val3 = *(--last);
  auto val4 = c.back();
}
```
> 都指向第一个元素

### ex9.24
编写程序，分别使用 at、下标运算符、front 和 begin 提取一个 vector 中的第一个元素。在一个空的 vector 上测试你的程序。
[ch09/ex_9.24.cpp](ch09/ex_9.24.cpp)

### ex9.25
对于第 312 页中删除一个范围内的元素的程序，如果 elem1 和 elem2 相等，会发生什么？如果 elem2 是尾后迭代器，或者 elem1 和 elem2 皆为尾后迭代器，又会发生什么？
```cpp
elem1 = slist.erase(elem1, elem2); 
```
elem1 指向要删除的第一个元素，elem2 指向要删除的最后一个元素之后的位置
> 两者相等，在不做删除；
> elem2 是尾后迭代器，则删除 elem1 和 elem2 之间的所有元素;
> 两个都是尾后迭代器，也不做删除

### ex9.26
使用下面代码定义的 ia，将 ia 拷贝到一个 vector 和一个 list 中。使用单迭代器版本的 erase 从 list 中删除奇数元素，从 vector 删除偶数元素
```cpp
int ia[] = {0, 1,1,2,3,5,8,13,21,55,89};
```
[ch09/ex_9.26.cpp](ch09/ex_9.26.cpp)

### ex9.27
编写程序，查找并删除 forward_list<int> 中的元素；
> forward_list 是一个单向链表，需要注意 begin() 和 before_begin() 这两个迭代器
[ch09/ex_9.27.cpp](ch09/ex_9.27.cpp)

### ex9.28
编写函数，接受一个 forward_list<string> 和两个 string，共三个参数。函数应在链表中查找第一个 string，并将第二个 string 插入到紧接着第一个 string 之后的位置。若第一个 string 未在链表中，则将第二个 string 插入到链表末尾；

### ex9.29
假定 vec 包含 25 个元素，那么 vec.resize(100) 会做什么？如果接下来调用 vec.resize(10) 会做什么？
- vec.resize(100) 后部补 0
- vec.resize(10) 超过 10 个元素的部分会删除

### ex9.30
接受单个参数的 resize 版本对元素类型有什么限制？（如果有的话）
> 元素类型必须是默认可构造的，如果不能构造，将报错

### ex9.31
第 316 页中删除偶数值元素并复制奇数值元素的程序不能用于 list 或者 forward_list。为什么？修改程序，使之也能用于这些类型；
```cpp
int main()
{
    std::vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto iter = v.begin();
    while (iter != v.end())
    {
        if (*iter % 2 == 0)
        {
            iter = v.insert(iter, *iter); // 复制当前元素
            iter += 2;                    // 跳过插入的当前元素和插入的元素
        }
        else
        {
            iter = v.erase(iter); // 删除当前元素
        }
    }
    for (auto i : v)
    {
        cout << i << " ";  // 0 0 2 2 4 4 6 6 8 8 
    }

    return 0;
}
```
适配 list
```cpp
int main()
{
    std::list<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto iter = v.begin();
    while (iter != v.end())
    {
        if (*iter % 2 == 0)
        {
            iter = v.insert(iter, *iter); // 复制当前元素
            iter++;                       // 跳过当前的元素
            iter++;                       // 跳过插入的元素
        }
        else
        {
            iter = v.erase(iter); // 删除当前元素
        }
    }
    for (auto i : v)
    {
        cout << i << " ";
    }
    return 0;
}
```
适配forward_list
```cpp
int main()
{
    std::forward_list<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto prev = v.before_begin(); // 前驱节点
    auto curr = v.begin();        // 当前节点

    while (curr != v.end())
    {
        if (*curr % 2 == 0)
        {
            // 插入到当前节点后，返回新节点的迭代器
            curr = v.insert_after(curr, *curr);
            ++curr; // 跳过新节点，指向原节点的下一位置
            ++prev; // 前驱节点同步跟进（原节点）
            ++prev; // 需要跳过两个节点
        }
        else
        {
            // 删除当前节点（prev的下一个节点）
            curr = v.erase_after(prev);
            // prev 不需要移动，curr 已指向下一节点
        }
    }

    // 验证结果（输出应为：0 0 2 2 4 4 6 6 8 8）
    for (auto n : v)
        cout << n << " ";
    return 0;
}

```

### ex9.32
在 9.31 的程序中，向下面的语句这样调用 insert 是否合法？如果不合法，为什么？
> 
```cpp
iter = v1.insert(iter, *iter++); //不合法，插入的是下一个元素的值
```

### ex9.33
在本节的最后一个例子中，如果不讲 insert 的结果赋予给 begin，将会发生什么？编写程序，去掉此赋值语句，验证你的答案。
```cpp
while(begin != v.end()) {
  ++begin;
  begin = v.insert(begin, 42); //插入新值
  ++begin;
}
```
> 会导致无限循环

### ex9.34
假定 v1 是一个保存 int 的容器，其中有偶数值也有奇数值，分析下面循环的行为，然后编写程序验证你的分析是否正确？
```cpp
iter = vi.begin();
while(iter != v1.end()) {
  if(*iter % 2) {
    iter = v1.insert(iter, *iter);
  }
  ++iter;
}
```
> 会陷入无限循环

### ex9.35
解释一个 vector 的 capacity 和 size 有何区别。
- size 存放元素实际的个数
- capacity 存放元素的容量
```cpp
int main()
{
    std::vector<int> v(10); // 初始化一个容量为10的vector

    v.push_back(1);               // 超过初始化的容器大小，容器自动扩容
    cout << v.capacity() << endl; // 20
    cout << v.size() << endl;     // 11
    for (auto n : v)
        cout << n << " ";
    return 0;
}
```

### ex9.36
一个容器的 capacity 可能小于它的 size 吗？
> 不可能，关系是 capacity >= size

### ex9.37
为什么 list 或者 array 没有 capacity 成员函数。
> array 初始化是固定的，不支持扩容操作
> list 是双端队列，不强制要求是连续的存储空间，保存的是前后节点的指针，不需要获取容量

### ex9.38
编写程序，探究在你的标准库实现中，vector 是如何增长的。
```cpp

int main()
{
    std::vector<int> v(10); // 初始化一个容量为10的vector

    for (int i = 0; i < 100; i++)
    {
        v.push_back(i);
        if (i % 10 == 0)
        {
            cout << "v.size() = " << v.size() << endl;
            cout << "v.capacity() = " << v.capacity() << endl;
        }
    }
    return 0;
}
//output
v.size() = 11
v.capacity() = 20
v.size() = 21
v.capacity() = 40
v.size() = 31
v.capacity() = 40
v.size() = 41
v.capacity() = 80
v.size() = 51
v.size() = 51
v.capacity() = 80
v.size() = 61
v.capacity() = 80
v.size() = 71
v.capacity() = 80
v.size() = 81
v.capacity() = 160
v.size() = 91
v.capacity() = 160
v.capacity() = 80
v.size() = 61
v.capacity() = 80
v.size() = 71
v.capacity() = 80
v.size() = 81
v.capacity() = 160
v.size() = 91
v.capacity() = 160
v.size() = 61
v.capacity() = 80
v.size() = 71
v.capacity() = 80
v.size() = 81
v.capacity() = 160
v.size() = 91
v.capacity() = 160
v.size() = 71
v.capacity() = 80
v.size() = 81
v.capacity() = 160
v.size() = 91
v.capacity() = 160
v.size() = 81
v.capacity() = 160
v.size() = 91
v.capacity() = 160
v.capacity() = 160
v.size() = 91
v.capacity() = 160
v.capacity() = 160
v.size() = 101
v.capacity() = 160
```
根据输出的结果来看，大概是 2n 倍的关系增长

### ex9.40
如果上一题中的程序读入了 256 个词，在 resize 之后容器的 capacity 可能是多少，读取了 512 个、1000、或者 1048 个词呢？
> 上一题我们得出增长关系大概是 2n 倍

- 如果是 256 个词，capcity = 320
- 如果是 512 个词，capcity = 640
- 如果是 1000 个词，capacity = 1280
- 如果是 1048 个词， capacity = 1280

### ex9.41
编写程序，从一个 vector<char> 初始化一个 string
```cpp
int main()
{
    std::vector<char> v2(10, 'a');
    std::vector<char> v1 = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
    std::string str1(v1.begin(), v1.end());
    std::string str2(v2.begin(), v2.end());
    cout << str1 << endl;
    cout << str2 << endl;
    return 0;
}
```

### ex9.42
假定你希望每次读取一个字符存入一个 string 中，而且直到最少需要读取 100 个字符，应该如何提高程序性能；
```cpp
//通过构造函数 + 指针的方式构造
std::vector<char> v2(200, 'a');
std::string str2(&v2[0], &v2[0] + 100);
cout << str2 << endl;
cout << str2.size() << endl;
```

### ex9.43
编写一个函数，接受三个 string 参数 s、oldVal 和 newVal。使用迭代器及 insert 和 erase 函数将 s 中所有 oldVal 替换威 newVal。测试你的程序，用他替换通用的简写形式。如，将 `tho` 替换为 `though`, 将 `thru` 替换称 `through`;
[ch09/ex_9.43.cpp](ch09/ex_9.43.cpp)

### ex9.44
重写上一题的函数，这次使用下标和一个 replace
[ch09/ex_9.44.cpp](ch09/ex_9.44.cpp)

### ex9.45
编写一个函数，接受一个表示名字的 string 参数和两个分别表示前缀（如 "Mr." 或者 "Ms."）和后缀（如 "Jr." 或者 "III"）的字符串。使用迭代器及 insert 和 append 函数将前缀和后缀添加到给定的名字中。将生成的新 string 返回
```cpp
std::string &func(std::string &s, const std::string &prefix, const std::string &suffix)
{
    s.insert(0, prefix);
    s.append(suffix);
    return s;
}
```

### ex9.46
重写上一题的函数，这次使用位置和长度来管理 string，并只使用 insert
```cpp
std::string &func(std::string &s, const std::string &prefix, const std::string &suffix)
{
    s.insert(0, prefix);
    s.insert(s.size(), suffix);
    return s;
}
```

### ex9.47
编写程序，首先查找 string “ab2c3d7R4E” 中的每个数字字符，然后查找其中每个字母字符。编写两个版本的程序，第一个要使用 find_first_of，第二个要使用 find_first_not_of;
[ch09/ex_9.47.cpp](ch09/ex_9.47.cpp)

### ex9.48
假定 name 和 numbers 的定义如 325 页所示，numbers.find(name)返回什么？
```cpp
std::string numbers("012345689"), name("r2d2");
std::string::size_type pos = numbers.find(name);
cout << (pos == std::string::npos ? "not found" : "found");
```

### ex9.49
如果一个字母延申到中线之上，如 d 和 f，则称其有上出头部分。如果一个字母延申到中线之下，如 p 或者 g。编写程序，读入一个单词文件，输出最长的及不包含上出头部分也不包含下出头部分的单词

[ch09/ex_9.49.cpp](ch09/ex_9.49.cpp)

### ex9.50
编写程序处理一个 vector<string>，其元素都表示整型值。计算 vector 中所有元素之和。修改程序，使之计算表示浮点值的 string 之和。

[ch09/ex_9.50.cpp](ch09/ex_9.50.cpp)

### ex9.51
设计一个类，它有三个 unsigned 成员，分别表示年、月和日。为其编写构造函数，接受一个表示日期的 string 参数。你的构造函数应该能处理不同数据格式。如 January 1，1900、1/1/1900、Jan 1 1900 等。
```cpp
class Date {
private:

}
```


## ch10

### ex10.1
头文件 algorithm 中定义了一个名为 count 的函数，它类似于 find，接受一对迭代器和一个值作为参数，count 返回给定值在序列中出现的次数。编写程序，读取 int 序列存入 vector 中，打印有多少个元素等于给定值。
```cpp
#include <algorithm>
int main()
{
    std::vector<int> ivec;
    int value;
    while (cin >> value)
    {
        ivec.push_back(value);
    }
    std::ptrdiff_t count = std::count(ivec.cbegin(), ivec.cend(), 42);
    cout << count << endl;
    return 0;
}
```

### ex10.2
重做上一题，但读取 string 序列存入 list 中
```cpp
#include <algorithm>
int main()
{
    std::vector<std::string> svec;
    std::string value;
    while (cin >> value)
    {
        svec.push_back(value);
    }
    std::ptrdiff_t count = std::count(svec.cbegin(), svec.cend(), "42");
    cout << count << endl;
    return 0;
}
```

### ex10.3
用 accumulate 求一个 vector<int> 中的元素之和
```cpp
#include <numeric>
int main()
{
    std::vector<int> ivec = {1, 2, 3, 4, 5};
    int sum = std::accumulate(ivec.cbegin(), ivec.cend(), 0);
    cout << "sum = " << sum << endl;
    return 0;
}
```

### ex10.4
假定 v 是一个 vector<double>, 那么调用 accmulate(v.cbegin(), v.cend(), 0) 有何错误（如果存在的话）？
> 会丢失精度
```cpp
//fixed
#include <numeric>
int main()
{
    std::vector<double> ivec = {1, 2, 3, 4, 5.4};
    double sum = std::accumulate(ivec.begin(), ivec.end(), 0.0);
    cout << "sum = " << sum << endl;
    return 0;
}
```

### ex10.5
在本节对名册（roster）调用 equal的例子中，如果两个名册中保存的都是 C 风格字符串而不是 string，会发生什么？
```cpp
equal(roster1.cbegin(), roster1.cend(), roster2.cbegin());
```
可以正常比较相等
```cpp

int main()
{
    std::vector<const char *> roster1 = {"hello", "world", "c++"};
    // std::vector<const char *> roster2 = {"hello", "world", "c++", "java"};
    std::vector<const char *> roster2 = {"olleh", "dlrow", "++c", "java"};
    bool flag = std::equal(roster1.cbegin(), roster1.cend(), roster2.cbegin());
    cout << "flag = " << flag << endl;
    return 0;
}
```

### ex10.6
编写程序，使用 fill_n 将一个序列中的 int 值都设置为 0
```cpp
int main()
{
    std::vector<int> v = {1, 2, 3, 4, 5};
    // std::fill_n(v.begin(), 3, 0);
    // std::fill_n(v.begin(), v.size(), 0);
    std::fill_n(v.begin(), v.end() - v.begin() - 2, 0); //前三个元素设置为 0
    for (auto &i : v)
    {
        cout << i << " ";
    }
    return 0;
}
```

### ex10.7
下面的程序是否有错误？如果有，请改正。
```cpp
// a
vector<int> vec; list<int> lst; int i;
while(cin >> i) {
  lst.push_back(i);
}
std::copy(lst.cbegin(), lst.cend(), vec.begin());

//a fixed
vector<int> vec; list<int> lst; int i;
while(cin >> i) {
  lst.push_back(i);
}
vec.resize(lst.size()); //需要先设定容量，否则行为就是未定义的
std::copy(lst.cbegin(), lst.cend(), vec.begin());

// b
vector<int> vec;
vec.reserve(10);
fill_n(vec.begin(), 10, 0);

// b fixed
int main()
{
    vector<int> vec(10);//声明大小
    // vec.reserve(10);
    cout << "vec size: " << vec.size() << endl;
    cout << "vec capacity: " << vec.capacity() << endl;

    //或者使用
    //fill_n(std::back_inserter(vec), 10, 11);
    fill_n(vec.begin(), 10, 11);
    return 0;
}
```

### ex10.8
本节提到过，标准库算法不会改变它们所操作的容器的大小，为什么使用 back_inserter 不会使这一断言失效？
