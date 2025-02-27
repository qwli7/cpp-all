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
