## ch10 泛型算法
### lambda 表达式
```cpp
[capture_list](parameter list) -> return type {function body}
```
改写 `is_shorter` 方法成 `lambda` 表达式
```cpp
[](const string & s1, const string & s2) {return s1.size() > s2.size();}

auto fun = [](const string & s1, const string & s2) {return s1.size() > s2.size();};
//调用 
cout << fun("hello", "world2") << endl;
```

#### 定义 `lambda` 返回类型
需要定义 `lambda` 返回类型，需要使用尾置表达式
```cpp
[](int a) -> int {return a < 0 ? -a : a;}  //说明这个 lambda 表达式的返回值是一个 int，如果能推到出来，可以不写；否则需要手动指定 lambda 返回值类型
```

### lambda 表达式捕获列表
|表达式|介绍|
|----|----|
|`[]`|空捕获列表，`lambda` 不能使用所在函数中的变量。一个 `lambda` 只有捕获变量后才能使用它们|
|`[names]`|`names` 是一个逗号分隔的名字列表，这些名字都是 `lambda` 所在的函数的局部变量。默认情况下捕获列表中的变量都被拷贝。名字前如果使用了 `&`，则采用引用捕获的方式|
|`[&]`|隐式捕获列表，采用引用捕获的方式。`lambda` 体中所使用的来自所在函数的实体都采用引用方式使用|
|`[=]`|隐式捕获列表，采用值捕获的方式。`lambda` 体中所使用的来自所在函数的实体的值|
|`[&, identifier_list]`|`identifier_list` 是一个逗号分隔的列表，包含 `0` 个或者多个来自所在函数的变量。这些变量采用值捕获的方式，而任何隐式捕获的变量都采用引用方式捕获。`identifier_list` 中的名字前面不能使用 `&`|
|`[=, identifier_list]`|`identifier_list`中的变量都采用引用方式捕获，而任何隐式捕获的变量都采用值方式捕获。`identifier_list` 中的名字不能包括 `this`，且这些名字之前必须使用 `&`|

### 几种迭代器
- `back_inserter` 创建一个 `push_back` 的迭代器
- `front_inserter` 创建一个 `push_front` 的迭代器
- `inserter` 创建一个 `insert` 的迭代器 


### 迭代器类别
|类别|说明|
|----|----|
|输入迭代器|只读，不写；单遍扫描，只能递增|
|输出迭代器|只读，不写；单遍扫描，只能递增|
|前向迭代器|可读写；多遍扫描，只能递增|
|双向迭代器|可读写；多遍扫描，可递增递减|
|随机访问迭代器|可读写；多遍扫描，支持全部迭代器运算|


## ch10 练习题
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
> `back_inserter` 接受一个指向容器的引用，返回一个与该容器绑定的插入迭代器，当我们通过此迭代器赋值时，赋值运算符会调用 `push_back` 将一个具有给定值的元素添加到容器中。
```cpp
vector<int> ivec; //空容器
auto it = back_inserter(vec); //创建一个插入迭代器
*it = 42;  //现在容器内有一个元素
```
在算法上通常使用这种。
```cpp
vector<int> vec;
fill_n(back_inserter(vec), 10, 0); //添加10个0
```

### ex10.9 
实现你自己的 `elimDups`。测试你的程序，分别在读取输入后、调用 unique 后以及调用 erase 后打印 vector 的内容；

输入 `the` `quick` `red` `fox` `jumps` `over` `the` `slow` `red` `turtle`。排序去重后输出

[ex10.9.cpp](ex_10.9.cpp)


### ex10.10
你认为算法不改变容器大小的原因是什么？
> 算法基本上都是基于迭代器来进行处理的，改变容器大小会导致原有的迭代器失效。


### ex10.11
编写程序，使用 `stable_sort` 和 `isShorter` 将传递给你的 `elimDups` 版本的 `vector` 排序。打印 `vector` 的内容，验证你程序的正确性。

[ex10.11.cpp](ex_10.11.cpp)

### ex10.12
编写名为 `compareIsbn` 的函数，比较两个 `Sales_data` 对象的 `isbn()` 成员。使用这个函数排序一个保存 `Sales_data` 对象的 `vector`。

[ex10.12.cpp](ex_10.12.cpp)

### ex10.13
标准库定义了名为 `partition` 的算法，他接受一个谓词，对容器内容进行划分，使得谓词为 `true` 的值会排在容器的前半部分，而使谓词为 `false` 的值会排在后半部分。算法返回一个迭代器，指向最后一个使谓词为 `true` 的元素之后的位置。编写函数，接受一个 `string`，返回一个 `bool` 值，指出 `string` 是否有 `5` 个或更多字符。使用此函数划分 `words`。打印出长度大于等于 `5` 的元素。

[ex10.13.cpp](ex_10.13.cpp)

### ex10.14
编写一个 `lambda`，接受两个 `int `，返回它们的和；
```cpp
auto fun = [](const int& a, const int& b) {return a+b;}
fun(1, 2);
```

### ex10.15
编写一个 `lambda`，捕获它所在函数的 `int`, 并接受一个 `int` 参数。`lambda` 应该返回捕获的 `int` 和 `int` 参数的和。
```cpp
int func(const int &a)
{
    auto fun = [a](const int &b)
    { return a + b; };
    return fun(1);
}

int main()
{
    cout << func(10) << endl;  //11

    return 0;
}

```
### ex10.16
使用 `lambda` 表达式编写你自己版本的 `biggies`
```cpp
void biggies(std::vector<string> &words, std::vector<string>::size_type sz)
{
    elimDups(words); // 按照字典排序

    std::stable_sort(words.begin(), words.end(), [](const string &s1, const string &s2)
                     { return s1.size() < s2.size(); });

    auto wc = std::find_if(words.begin(), words.end(), [sz](const string &s)
                           { return s.size() >= sz; });
    auto count = words.end() - wc;
    cout << count << " words are longer than or equal to " << sz << endl;

    std::for_each(wc, words.end(), [](const string &s)
                  { cout << s << " "; });
    cout << endl;
}
```

### ex10.17
重写 `ex10.12`的程序，在对 `sort` 的调用中使用 `lambda` 表达式来替代函数 `compareIsbn`。
```cpp
std::sort(data.begin(), data.end(), [](const Sales_data &sd1, const Sales_data &sd2){return sd1.isbn() < sd2.isbn();});
```

### ex10.18
重写 `biggies`，用 `partition` 代替 `find_if`。
```cpp
void biggies(std::vector<string> &words, std::vector<string>::size_type sz)
{
    elimDups(words); // 按照字典排序

    std::stable_sort(words.begin(), words.end(), [](const string &s1, const string &s2)
                     { return s1.size() < s2.size(); });

    auto wc = std::partition(words.begin(), words.end(), [sz](const string &s)
                             { return s.size() >= sz; }); //满足条件的放在前面，不满足条件的放在后面，返回的 wc 指向的是最后满足条件的下一个位置
    auto count = wc - words.begin();
    cout << count << " words are longer than or equal to " << sz << endl;

    std::for_each(words.begin(), wc, [](const string &s)
                  { cout << s << " "; });
    cout << endl;
}
```


### ex10.19
用 `stable_partition` 重写前一题的程序，与 `stable_sort` 类似，在划分后的序列中维持原有元素的顺序。
```cpp
void biggies(std::vector<string> &words, std::vector<string>::size_type sz)
{
    elimDups(words); // 按照字典排序

    auto wc = std::stable_partition(words.begin(), words.end(), [sz](const string &s1)
                                    { return s1.size() >= sz; });

    // auto wc = std::partition(words.begin(), words.end(), [sz](const string &s)
    //                          { return s.size() >= sz; });
    auto count = wc - words.begin();
    cout << count << " words are longer than or equal to " << sz << endl;

    std::for_each(words.begin(), wc, [](const string &s)
                  { cout << s << " "; });
    cout << endl;
}
```

### ex10.20
标准库定义了一个名为 `count_if` 的算法。类似于 `find_if`，此函数接受一对迭代器，表示一个输入范围，还接受一个谓词，会对输入范围中的每个元素执行。`count_if` 返回一个计数值，表示谓词有多少次为真。使用`count_if` 重写我们辰戌中统计有多少个单词长度超过 `6` 的部分；
```cpp
int main()
{
    std::vector<string> words = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};

    std::ptrdiff_t count = std::count_if(words.begin(), words.end(), [](const string &s) -> bool
                                         { return s.size() >= 6; });
    cout << count << endl;  // 1
    return 0;
}
```

### ex10.21
编写一个 `lambda`，捕获一个局部 `int` 变量，并递减变量值，直到它变为 `0`。一旦变量变为 `0`，再调用 `lambda` 应该不再递减变量。`lambda` 应该返回一个 `bool` 值，指出捕获的变量是否为 `0`;
```cpp

void func(int &a)
{
    for (int i = 0; i < 20; i++)
    {
        auto fun = [&a]() -> bool
        {
            if (a <= 0)
            {
                return true;
            }
            cout << "a = " << a << endl;
            a--;
            return false;
        };
        bool flag = fun();
        cout << "fun() return " << std::boolalpha << flag << endl;
    }
}

int main()
{
    int num = 10;
    func(num);

    return 0;
}
```

### ex10.22
重写统计长度小于等于 `6` 的单词数量的程序，使用函数代替 `lambda`
```cpp
#include <functional>
bool check_size(const std::string & s, std::string::size_type sz) {
    return s.size() >= sz;
}
//_1 _2 占位符在 placeholders 命名空间下

int main() {
    auto check = std::bind(check_size, std::placeholders::_1, 6); // sz 默认固定为 6， _1 为占位符，表示传递过来的参数
    check("hello"); //调用了 check_size()
    return 0;
}
```

### ex10.23
`bind` 接受几个参数；
> 两个，第一个是函数名，第二个是可变参数列表，用逗号分隔。

### ex10.24
给定一个 `string`, 使用  `bind` 和 `check_size` 在一个 `int` 的 `vector` 中查找第一个大于 `string` 长度的值；

[ex_10.24.cpp](ex_10.24.cpp)

### ex10.25
在 `10.3.2` 节的练习中，编写了一个使用 `partition` 的 `biggies` 版本。使用 `check_size` 和 `bind` 重写此函数；
```cpp
bool check_size(const std::string & s, std::string::size_type sz) {
    return s.size() < sz;
}

void biggies(std::vector<string> &words, std::vector<string>::size_type sz)
{
    elimDups(words); // 按照字典排序

    std::stable_sort(words.begin(), words.end(), [](const string &s1, const string &s2)
                     { return s1.size() < s2.size(); });
    //参数绑定 _1 是占位符
    auto check = std::bind(check_size, std::placeholders::_1, sz);
    auto wc = std::partition(words.begin(), words.end(), check); //满足条件的放在前面，不满足条件的放在后面，返回的 wc 指向的是最后满足条件的下一个位置
    auto count = wc - words.begin();
    cout << count << " words are longer than or equal to " << sz << endl;

    std::for_each(words.begin(), wc, [](const string &s)
                  { cout << s << " "; });
    cout << endl;
}
```

### ex10.26
解释三种插入迭代器的不同之处
- `back_inserter` 创建一个 `push_back` 的迭代器，向容器尾部插入
- `front_inserter` 创建一个 `push_front` 的迭代器，向容器头部插入
- `inserter` 创建一个 `insert` 的迭代器，指定位置插入

### ex10.27
除了 `unique` 之外，标准库还定义了名为 `unique_copy` 的函数，他接受三个迭代器，表示拷贝不重复元素的目的位置。编写一个程序，使用 `unique_copy` 将一个 `vector` 中不重复的元素拷贝到一个初始为空的 `list` 中。
```cpp
int main()
{

    std::vector<string> words = {"hello", "hello", "world"};

    std::list<string> words2 = {};
    std::unique_copy(words.begin(), words.end(), std::back_inserter(words2)); //这里需要使用 back_inserter
    for (auto it : words2)
    {
        cout << it << " ";  // hello world
    }
    cout << endl;
    return 0;
}
```

### ex10.28
一个 `vector` 中保存 `1` 到 `9`，将其拷贝到三个其他容器中。分别使用 `inserter`、`back_inserter`、`front_inserter` 将元素添加到三个容器中。对每种 `inserter`，估计输出顺序是怎样的，运行程序验证你的估计是否正确。
```cpp
int main()
{

    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::list<int> l;
    std::unique_copy(v.begin(), v.end(), std::back_inserter(l)); // 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
    for (auto t : l)
    {
        cout << t << " ";
    }
    cout << endl;
    std::list<int> l2;
    std::unique_copy(v.begin(), v.end(), std::front_inserter(l2)); // 10, 9, 8, 7, 6, 5, 4, 3, 2, 1
    for (auto t : l2)
    {
        cout << t << " ";
    }
    cout << endl;

    std::list<int> l3;
    std::unique_copy(v.begin(), v.end(), std::inserter(l3, l3.begin())); // 1 2 3 4 5 6 7 8 9 10
    for (auto t : l3)
    {
        cout << t << " ";
    }
    cout << endl;
    return 0;
}
```

### ex10.29


### ex10.30


### ex10.31


### ex10.32


### ex10.33


### ex10.34
使用 `reverse_iterator` 逆序打印一个 `vector`；
```cpp
int main()
{

    std::vector<int> ivec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int>::reverse_iterator it = ivec.rbegin(); // 获取反向迭代器  
    while (it != ivec.rend())
    {
        cout << *it << " "; //10 9 8 7 6 5 4 3 2 1
        ++it;
    }

    return 0;
}
```

### ex10.35
使用普通迭代器逆序打印一个 `vector`
```cpp
int main()
{

    std::vector<int> ivec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int>::const_iterator iter = ivec.cend();
    while (iter != ivec.cbegin())
    {
        --iter;
        cout << *iter << " ";
    }
    cout << endl;

    return 0;
}
```

### ex10.36
使用 `find` 在一个 `int` 的 `list` 中查找最后一个值为 `0` 的元素。

[ex_10.36.cpp](ex_10.36.cpp)


### ex10.37
给定一个包含 `10` 个元素的 `vector`，将位置 `3` 到 `7` 之间的元素按逆序拷贝到一个 `list` 中；

[ex_10.37.cpp](ex_10.37.cpp)

### ex10.38
列出 `5` 个迭代器类别，以及每类迭代器所支持的操作。
|类别|说明|
|----|----|
|输入迭代器|只读，不写；单遍扫描，只能递增|
|输出迭代器|只读，不写；单遍扫描，只能递增|
|前向迭代器|可读写；多遍扫描，只能递增|
|双向迭代器|可读写；多遍扫描，可递增递减|
|随机访问迭代器|可读写；多遍扫描，支持全部迭代器运算|

### ex10.39
`list` 上的迭代器属于哪类？`vector` 呢？
> `list` 是双向链表，迭代器类别为双向迭代器

> `vector` 连续存储空间的单向列表，可通过下标获取元素，迭代器类别为随机访问迭代器

### ex10.40
你认为 `copy` 要求哪类迭代器？`reverse` 和 `unique` 呢？
> `copy` 要求前向迭代器和输出迭代器

### ex10.41 
仅根据算法和参数的名字，描述下面每个标准库算法执行什么操作；
```cpp
replace(beg, end, old_val, new_val); //在 begin 和 end 之间，将 old_val 替换成 new_val 
replace_if(beg, end, pred, new_val); //如果满足谓词，在 begin 和 end 之间，将 old_val 替换成 new_val 
replace_copy(beg, end, dest, old_val, new_val); // 在 begin 和 end 之间，将 old_val 替换成 new_val，同步拷贝到 dest
replace_copy_if(beg, end, dest, pred, new_val); //如果满足谓词，在 begin 和 end 之间，将 old_val 替换成 new_val，同步拷贝到 dest
```

### ex10.42
使用 `list` 代替 `vector` 重新实现 `10.2.3` 节的去除重复单词的程序。

