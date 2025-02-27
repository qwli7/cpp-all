## ch11 关联容器
### 关联容器类型
|类别|能力|
|----|----|
|`map`|关联数组：保存关键字-值对|
|`set`|关键字即值，即只保存关键字的容器|
|`multimap`|关键字可重复出现的 `map`|
|`multiset`|关键字可重复出现的 `set`|
|`unordered_map`|用哈希函数组织的 `map`|
|`unordered_set`|用哈希函数组织的 `set`|
|`unordered_multimap`|哈希组织的 `map`；关键字可以重复出现|
|`unordered_multiset`|哈希组织的 `set`；关键字可以重复出现|


### 关联容器额外的类型别名
|类型别名|解释|
|----|----|
|`key_type`|此容器类型的关键字类型|
|`mapped_type`|每个关键字关联的类型：只适用于 `map`|
|`value_type`|对于 `set`，与 `ket_type` 相同，对于 `map`，为 `pair<const key_type, mapped_type>`|
---


## ch11 练习题
### ex11.1
描述 `map` 和 `vector` 的不同？
> `map` 是 `key-value` 的形式，`vector` 是单值形式

### ex11.2
分别给出最合适使用 `list`、`vector`、`deque`、`map` 以及 `set` 的例子
- `list` 双端链表
- `vector` 连续内存的单项队列
- `deque` 双端队列
- `map` `key-value` 键值形式存储
- `set` 存储关键字的容器

### ex11.3
编写你自己的单词计数程序。
```cpp
#include <map>
int main()
{
    std::map<string, size_t> word_count;
    std::string word;
    while (cin >> word)
    {
        ++word_count[word];
    }

    for (auto it : word_count)
    {
        cout << it.first << " occurs " << it.second << " times" << endl;
    }

    return 0;
}
```

### ex11.4
扩展你的程序，忽略大小写和标点。例如 `example.`、`example,`、`Example` 应该递增相同的计数器
```cpp
int main()
{
    std::map<string, size_t> word_count;
    std::string word;
    while (cin >> word)
    {
        // 删除标点符号
        word.erase(std::remove_if(word.begin(), word.end(), ispunct), word.end());
        // 转换为小写字母
        std::transform(word.begin(), word.end(), word.begin(), tolower);
        ++word_count[word];
    }

    for (auto it : word_count)
    {
        cout << it.first << " occurs " << it.second << " times" << endl;
    }

    return 0;
}
```

### ex11.5
解释下 `map` 和 `set` 的区别。你如何选择使用哪个？
- `map` `key-value` 形式存储
- `set` `key` 形式存储

### ex11.6
解释下 `set` 和 `list` 的区别。你如何选择使用哪个？
- `std::set` 是一个关联容器，它存储唯一的元素，并且这些元素按照特定的顺序自动进行排序。`std::set` 内部实现通常是红黑树，因此查找、插入和删除操作的时间复杂度为对数时间。`std::set` 主要用于存储不重复的元素，并且需要保持元素有序的情况。
- `std::list` 是一个双向链表容器，它允许在常数时间内在任意位置插入和删除元素。`std::list` 不会自动排序元素，也不保证元素的唯一性。`std::list` 适用于需要频繁插入和删除的情况，并且不需要元素自动排序的情况

### ex11.7
定义一个 `map`，关键字是家庭的姓，值是一个 `vector`，保存家中孩子（们）的名。编写代码，实现添加新的家庭以及向已有家庭中添加新的孩子。
```cpp
int main()
{
    std::map<std::string, std::vector<string>> name_map;
    name_map["Alice"].push_back("apple");
    name_map["Alice"].push_back("banana");
    name_map["Bob"].push_back("orange");
    name_map["Bob"].push_back("pear");
    name_map["Charlie"].push_back("grape");
    name_map["Charlie"].push_back("peach");
    name_map["David"].push_back("plum");
    for (auto it : name_map)
    {
        cout << it.first << " : ";
        for (auto vt : it.second)
        {
            cout << vt << " ";
        }
        cout << endl;
    }
    return 0;
}
```

### ex11.8
编写一个程序，在一个 `vector` 而不是一个 `set` 中保存不重复的单词，使用 `set` 的有点是什么？
```cpp
int main()
{
    std::vector<string> words;
    words.push_back("hello");
    words.push_back("world");
    words.push_back("apple");

    std::for_each(words.begin(), words.end(), [](const string &s)
                  { cout << s << " "; });
    return 0;
}
```

### ex11.9
定义一个 `map`，将单词与一个行号的 `list` 关联，`list` 中保存的是单词所出现的行号。
```cpp
int main()
{
    std::map<string, std::list<int>> map;
    map["hello"].push_back(1);
    map["hello"].push_back(157);
    return 0;
}
```

### ex11.10
可以定义一个 `vector<int>::iterator` 到 `int` 的 `map` 吗？为什么？`list<int>::iterator` 到 `int` 的 `map` 呢？对应这两种情况，如果不能，解释为什么？
```cpp
int main()
{  
    std::map<std::vector<int>::iterator, int> m; //语法上可以，但不建议，编译不报错
    std::map<std::list<int>::iterator, int> l;  //语法上可以，但不建议，编译不报错
    return 0;
}
```

### ex11.11
不使用 `decltype` 重新定义 `bookstore`。
```cpp
multiset<Sales_data, &compareIsbn> bookstore(compareIsbn);
multiset<Sales_data, decltype(compareIsbn) * > bookstore(compareIsbn);
```

### ex11.12 
编写程序：读入 `string` 和 `int` 的序列，将每个 `string` 和 `int` 存入一个 `pair` 中，`pair` 保存在一个 `vector` 中；
```cpp
int main()
{
    std::vector<std::pair<string, int>> v;
    std::string s;
    int value;
    while (cin >> s >> value)
    {
        v.push_back(std::make_pair(s, value));
    }

    std::for_each(v.begin(), v.end(), [](const std::pair<string, int> &p)
                  { cout << p.first << " " << p.second << endl; });
    return 0;
}
```

### ex11.13
在上一题的程序中，至少有三种创建 `pair` 的方法。编写此程序的三个版本，分别采用不同的方法创建 `pair` 。解释你认为那种形式最易于编写和理解，为什么？
```cpp
int main()
{

    std::vector<std::pair<string, int>> v;
    std::string s;
    int value;
    while (cin >> s >> value)
    {
        v.push_back(std::make_pair(s, value));
        v.push_back(std::pair<string, int>(s, value));
        v.push_back(std::pair<string, int>{s, value});
    }
    std::for_each(v.begin(), v.end(), [](const std::pair<string, int> &p)
                  { cout << p.first << " " << p.second << endl; });
    return 0;
}
```

### ex11.14
扩展你在 `11.2.1` 的练习中编写的孩子姓名到 `map`，添加一个 `pair` 的 `vector`，包含孩子的姓名和生日；
```cpp
int main()
{
    std::map<std::string, std::vector<string>> name_map;
    std::vector<std::pair<std::string, std::string>> birthday_vec;
    name_map["Alice"].push_back("apple");
    name_map["Alice"].push_back("banana");
    name_map["Bob"].push_back("orange");
    name_map["Bob"].push_back("pear");
    name_map["Charlie"].push_back("grape");
    name_map["Charlie"].push_back("peach");
    name_map["David"].push_back("plum");

    birthday_vec.push_back(std::make_pair("Alice apple", "2000-01-01"));
    birthday_vec.push_back(std::make_pair("Alice banana", "2000-01-01"));
    birthday_vec.push_back(std::make_pair("Bob orange", "2000-01-01"));
    for (auto it : name_map)
    {
        cout << it.first << " : ";
        for (auto vt : it.second)
        {
            cout << vt << " ";
        }
        cout << endl;
    }
    return 0;
}
```

### ex11.15
对一个 `int` 到 `vector<int>` 的 `map`，其 `mapped_type`、`key_type` 和 `value_type` 分别是什么？
- `key_type` 为 `int`
- `mapped_type` 为 `vector<int>`
- `value_type` 为 `pair<const int, vector<int>>`

### ex11.16
使用一个 `map` 迭代器编写一个表达式，将一个值赋予一个元素
```cpp
int main()
{
    std::map<std::string, int> word_count;
    std::map<std::string, int>::iterator it = word_count.find("hello");
    if (it != word_count.end())
    {
        it->second = 5;
    }
    //word_count["hello"] = 5;
    return 0;
}
```

### ex11.17
假定 `c` 是一个 `string` 的 `multiset`， `v` 是一个 `string` 的 `vector`，解释下面的调用。指出每个调用是否合法？
```cpp
copy(v.begin(), v.end(), inserter(c, c.end())); //把 v 里面的元素拷贝到 c 中
copy(v.begin(), v.end(), back_inserter(c));  //编译报错
copy(c.begin(), c.end(), inserter(v, v.end())); //把 c 里面的元素拷贝到 v 中
copy(c.begin(), c.end(), back_inserter(v)); //把 c 里面的元素拷贝到 v 中
```

### ex11.18
写出 `382` 页循环中 `map_it` 的类型，不要使用 `auto` 或者 `decltype`。
```cpp
std::map<std::string, int>::iterator it = word_count.begin();
```

### ex11.19
定义一个变量，通过对 `11.22` 节中的名为 `bookstore` 的 `multiset` 调用 `begin()` 来初始化这个变量。写出变量的类型，不要使用 `auto` 或者 `decltype`。


### ex11.20
重写 `11.1` 节练习的单词计数程序，使用 `insert` 代替下标操作。你认为哪个程序更容易编写和阅读？解释原因。
```cpp
int main()
{
    std::map<string, size_t> word_count;
    std::string word;
    while (cin >> word)
    {
        auto ret = word_count.insert(std::make_pair(word, 1));
        cout << "insert " << word << " " << ret.second << endl;
        if (!ret.second) // word 已经在 word_count 中，insert 什么也不做
        {
            ++ret.first->second;
        }
    }

    for (auto it : word_count)
    {
        cout << it.first << " occurs " << it.second << " times" << endl;
    }

    return 0;
}
```

### ex11.21
假定 `word_count` 是一个 `string` 到 `size_t` 的 `map`，`word` 是一个 `string`，解释下面循环的作用；
```cpp
while(cin >> word) {
    ++word_count.insert({word, 0}).first->second;  //和 ex11.20 作用一样
}
```

### ex11.22
给定一个 `map<string, vector<int>>`，对此容器的插入一个元素的 `insert` 版本，写出其参数类型和返回类型。
```cpp
int main()
{
    std::map<std::string, std::vector<int>> m;
    std::vector<int> v = {1, 2, 3};
    std::pair<std::map<std::string, std::vector<int>>::iterator, bool> ret = m.insert(std::make_pair("apple", v));
    return 0;
}
```

### ex11.23
`11.2.1` 节练习中的 `map` 以孩子的姓为关键字，保存他们的名的 `vector`， 用 `multimap` 重写此 `map`;
```cpp
int main()
{
    std::multimap<std::string, std::vector<std::string>> m_name;

    std::vector<std::string> v_name = {"Alice", "Bob", "Charlie"};
    m_name.insert(std::make_pair("Alice", v_name));
    m_name.insert(std::make_pair("Bob", v_name));
    m_name.insert(std::make_pair("Charlie", v_name));

    return 0;
}
```
### ex11.24
下面的程序完成什么功能？
```cpp
map<int, int> m;
m[0] = 1; //初始化一个元素
```

### ex11.25
对比下面程序与上一题程序
```cpp
vector<int> v;
v[0] = 1; // 越界 v 是一个空容器
```

### ex11.26
可以用什么类型来对一个 `map` 进行下标操作？下标运算符返回的类型是什么？请给出一个具体的例子--即，定义一个 `map`，然后写出一个可以用来对 `map` 进行下标操作的类型以及下标运算符会返回的类型。

### 11.3.5 访问元素
#### ex11.27
对于什么问题你会使用 `count` 来解决？什么时候你又会选择 `find` 呢？


#### ex11.28
对于一个 `string` 到 `int` 的 `vector` 的 `map`，定义并初始化一个变量来保存在其上调用 `find` 所返回的结果。


#### ex11.29
如果给定的关键字不在容器中，`upper_bound`、`lower_bound` 和 `equal_range` 分别会返回什么？


#### ex11.30
对于本节最后一个程序中的输出表达式，解释运算对象 `pos.first->second` 的含义。


#### ex11.31
编写程序，定义一个作者及其作品的 `multimap`。使用 `find` 在 `multimap` 中查找一个元素并用 `erase` 删除它。确保你的程序在元素不在 `map` 中时也能正常运行。


#### ex11.32
使用上一题定义的 `multimap` 编写一个程序，按字典序打印作者列表和他们的作品。


### 11.3.6 一个单词转换的 map
#### ex11.33
实现你自己的版本的单词转换程序。


#### ex11.34
如果你将 `transform` 函数中的 `find` 替换为下标运算符，会发生什么情况？

#### ex11.35
在 `buildMap` 中，如果进行如下改写，会有什么效果？
```cpp
trans_map[key] = value.substr(1);
//改为 trans_map.insert({key, value.substr(1)})
```

#### ex11.36
我们的程序并没有检查输入文件的合法性。特别是，它假定转换规则文件中的规则都是有意义的。如果文件中的某一行包含一个关键字、一个空格，然后就结束了，会发生什么？预测程序的行为并进行验证，再与你的程序进行比较。


### 11.4 无序容器

#### ex11.37 
 一个无序容器与其有序版本相比有何优势？有序版本有何优势？


#### ex11.38
用 `unordered_map` 重写单词计数程序和单词转换程序。


