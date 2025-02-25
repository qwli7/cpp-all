
## ch09 顺序容器
|类型|描述|
|:----:|:----:|
|vector|可变大小数组，支持快速随机访问。在尾部之外的位置插入或者删除元素可能很慢|
|deque|双端队列。支持快速随机访问。在头部和尾部插入、删除速度很快|
|list|双向链表。支持支双向顺序访问。在 list 中任何位置进行插入、删除操作速度都很快|
|forword_list|单向链表。只支持单向顺序访问。在链表的任何位置进行插入、删除操作速度都很快|
|array|固定大小数组。支持快速随机访问，不能添加或者删除元素|
|string|与 vector 相似的容器，但专门用于保存字符。随机访问块、在尾部补插入、删除速度快|

一般来说，使用 `vector` 是最好的选择，除非你有很好的理由选择其他容器；


## ch09 练习题
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

[ex_9.18.cpp](ex_9.18.cpp)

### ex9.19
重写上一题程序，用 list 替代 deque。列出程序需要做出哪些改变？

[ex_9.19.cpp](ex_9.19.cpp)

### ex9.20
编写程序，从一个 list<int> 拷贝元素到两个 deque 中。值为偶数的所有元素都拷贝到一个 deque 中，值为奇数值元素都拷贝到另一个 deque 中。

[ex_9.20.cpp](ex_9.20.cpp)


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

[ex_9.24.cpp](ex_9.24.cpp)

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
[ex_9.26.cpp](ex_9.26.cpp)

### ex9.27
编写程序，查找并删除 forward_list<int> 中的元素；
> forward_list 是一个单向链表，需要注意 begin() 和 before_begin() 这两个迭代器

[ex_9.27.cpp](ex_9.27.cpp)

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

[ex_9.43.cpp](ex_9.43.cpp)

### ex9.44
重写上一题的函数，这次使用下标和一个 replace

[ex_9.44.cpp](ex_9.44.cpp)

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

[ex_9.47.cpp](ex_9.47.cpp)

### ex9.48
假定 name 和 numbers 的定义如 325 页所示，numbers.find(name)返回什么？
```cpp
std::string numbers("012345689"), name("r2d2");
std::string::size_type pos = numbers.find(name);
cout << (pos == std::string::npos ? "not found" : "found");
```

### ex9.49
如果一个字母延申到中线之上，如 d 和 f，则称其有上出头部分。如果一个字母延申到中线之下，如 p 或者 g。编写程序，读入一个单词文件，输出最长的及不包含上出头部分也不包含下出头部分的单词

[ex_9.49.cpp](ex_9.49.cpp)

### ex9.50
编写程序处理一个 vector<string>，其元素都表示整型值。计算 vector 中所有元素之和。修改程序，使之计算表示浮点值的 string 之和。

[ex_9.50.cpp](ex_9.50.cpp)

### ex9.51
设计一个类，它有三个 unsigned 成员，分别表示年、月和日。为其编写构造函数，接受一个表示日期的 string 参数。你的构造函数应该能处理不同数据格式。如 January 1，1900、1/1/1900、Jan 1 1900 等。
```cpp
class Date {
private:

}
```
