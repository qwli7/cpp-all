## ch10 泛型算法


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
