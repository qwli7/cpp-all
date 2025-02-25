## ch05 语句
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

[ex_5.5.cpp](ex_5.5.cpp)

### ex5.6
改写上一题的程序，使用条件运算符（?:）代替 if else 语句

[ex_5.6.cpp](ex_5.6.cpp)

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

[ex_5.9.cpp](ex_5.9.cpp)

### ex5.10
我们之前实现统计与元音字母的程序存在一个问题，如果原因字母以大写的形式出现，不会被统计在内。编写一段程序，及统计元音字母的小写形式，也统计大写形式，也就是说新程序遇到 'a' 和 'A' 都应该递增 aCnt 的值，以此类推。

[ex_5.10.cpp](ex_5.10.cpp)

### ex5.11
修改统计元音字母的程序，使其也能统计空格、制表符和换行符的数量。

[ex_5.11.cpp](ex_5.11.cpp)

### ex5.12
修改统计元音字母的程序，使其能统计以下含有两个字符的字符序列数量：ff、fl 和 fi；

[ex_5.12.cpp](ex_5.12.cpp)

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

[ex_5.14.cpp](ex_5.14.cpp)


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
