## ch06 函数

## ch06 练习题
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

[ex_6.3.cpp](ex_6.3.cpp)

### ex6.4
编写一个与用户交互的函数，要求用户输入一个数字，计算生成该数字的阶乘。在 main 函数中调用该函数。

[ex_6.4.cpp](ex_6.4.cpp)

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

[Chapter6.h](Chapter6.h)

### ex6.9 
编写你自己的 fact.cc 和 factMain.cc，这两个文件都应该包含上一小节的练习中编写的 Chapter6.h 头文件。通过这些文件，理解你的编译器是如何支持分离式编译的。

[fact.cc](fact.cc)

[factMain.cc](factMain.cc)

```shell
g++ factMain.cc fact.cc -o main -std=c++11 -Wall
```
  
### ex6.10
编写一个函数，使用指针形参交换两个整数的值。在代码中调用该函数，并输出交换后的结果，以此验证函数的正确性。

[ex_6.10.cpp](ex_6.10.cpp)

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

[ex_6.17.cpp](ex_6.17.cpp)

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
[ex_6.47.cpp](ex_6.47.cpp)

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

[ex_6.51.cpp](ex_6.51.cpp)


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

[ex_6.55.cpp](ex_6.55.cpp)

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
