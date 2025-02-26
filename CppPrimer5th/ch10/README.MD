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
fun();
```

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
