## ch03 字符串、向量和数组
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
## ch03 练习题
### ex3.1
使用恰当的 using 声明重做 1.4.1 节和 2.6.2 节的练习

[ex_3.1.cpp](ex_3.1.cpp)



### ex3.2
编写一段程序，从标准输入中一次读取一整行，然后修改该程序使其一次读入一个词

[ex_3.2.cpp](ex_3.2.cpp)

### ex3.3
请说明 string 类的输入运算符和 getline 函数分别是如何处理空白字符的
- getline 一次读取一行，丢弃末尾的换行符
- cin>>str 以空格进行分隔

### ex3.4
编写一段程序读取两个字符串，比较其是否相等并输出结果。如果不相等，输出较大的那个字符串。改写上述程序，比较输入的两个字符串是否等长，如果不等长，输出长度较大的那个字符串；

[ex3.4_1.cpp](ex3.4.1.cpp)

[ex3.4.2.cpp](ex3.4.2.cpp)

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

[ex_3.10.cpp](ex_3.10.cpp)

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

[ex_3.16.cpp](ex_3.16.cpp)

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

[ex_3.31.cpp](ex_3.31.cpp)

### ex3.32
将上一题刚刚创建的数组拷贝给另一个数组。利用 vector 重写程序，实现类似的功能；

[ex_3.32.cpp](ex_3.32.cpp)，vector 版本 [ex_3.32_vector.cpp](ex_3.32_vector.cpp)


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

[ex_3.35.cpp](ex_3.35.cpp)

### ex3.36
编写一段程序，比较两个数组是否相等。再写一段程序，比较两个 vector 对象是否相等；

[ex_3.36.cpp](ex_3.36.cpp)


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

[ex_3.39.cpp](ex_3.39.cpp)

### ex3.40
编写一段程序，定义两个字符数组并用字符串字面值初始化它们；接着再定义一个字符数组存放前两个数组连接后的结果。使用 strcpy 何 strcat 把前两个两组的内容拷贝到第三个数组中。

[ex_3.40.cpp](ex_3.40.cpp)

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
[ex_3.43.cpp](ex_3.43.cpp)

### ex3.44
改写上一个练习中的程序，使用类型别名来代替循环控制变量的类型；

[ex_3.44.cpp](ex_3.44.cpp)

### ex3.45
再一次改写程序，这次使用 auto 关键字

[ex_3.45.cpp](ex_3.45.cpp)
