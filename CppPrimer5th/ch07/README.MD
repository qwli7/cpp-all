## ch07 类

### = default
`= default` 表示让编译器生成默认的构造函数

### 委托构造函数
**委托构造函数，就是使用其他的构造函数来帮助自己完成初始化功能**

## ch07 练习题
### ex7.1
使用 2.6.1 节练习定义的 Sales_data 类为 1.6 节的交易处理程序写一个新的版本。

[ex_7.1.cpp](ex_7.1.cpp)

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

[ex_7.1.cpp](ex_7.1.cpp)

### ex7.4
编写一个名为 Person 的类，使其表示人员的姓名和住址。使用 string 对象存放这些元素，接下来的练习将不断充实这个类的其他特征
```cpp
typedef struct Person
{
    std::string name;
    std::string address;
} p;
```
[Person.h](Person.h)

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
[Person.h](Person.h)

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

[Person2.h](Person2.h)

[Person.cpp](Person.cpp)

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
[Screen.h](Screen.h)

### ex7.28
如果 move、set 和 display 函数返回的类型不是 Screen& 而是 Screen，则在上一个练习中将会发生什么情况？
> 第一次使用 myScreen 对象和第二次使用的不是同一个对象，因此第一次会发生修改，第二次无法进行修改
```cpp
//output
xxxxxxxxxxxxxxxxxxxx#xxxx
xxxxxxxxxxxxxxxxxxxxxxxxx
```
[Screen2.h](Screen2.h)

### ex7.29
修改你的 Screen 类，令  move、set 和 display 函数返回 Screen 并检查程序的运行结果，在上一个练习中你的推测是正确的吗？

[Screen2.h](Screen2.h)


### ex7.30
通过 this 指针使用成员的做法虽然合法，但是有点多余。讨论显示的使用指针访问成员的优缺点。
> 在类内部，可以省略 this

### ex7.31
定义一对类 X 和 Y，其中 X 包含一个指向 Y 的指针，而 Y 包含一个类型为 X 的对象；

[ex_7.31.h](ex_7.31.h)

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

[ex_7.40.cpp](ex_7.40.cpp)



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
