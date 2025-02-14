## Array（模板类C++11）
一个长度固定的数组，位于名称空间 `std` 中，可以使用模板类 `std::array` 来表示。
## 基本操作
```cpp
#include <iostream>
#include <array>

int main()
{
    std::array<int, 5> ai; // 没有赋值初始值
    std::array<int, 10> aii = {0, 1, 2, 3, 4};

    aii.fill(100); // 使用 100 填充元素
    aii[0] = 20;

    // 下标访问元素没有边界检查
    std::cout << "aii[-1]=" << aii[-1] << std::endl;
    std::cout << "aii[100]=" << aii[100] << std::endl;
    std::cout << "aii[0]=" << aii[0] << std::endl;

    // at访问元素，有边界检查
    aii.at(3) = 1024;
    std::cout << "aii[3]=" << aii.at(3) << std::endl;
    // std::cout << "aii[100]=" << aii.at(100) << std::endl;

    // 访问第一个元素
    aii.front() = 2048;
    std::cout << aii.front() << std::endl;

    // 访问最后一个元素
    aii.back() = 4096;
    std::cout << aii.back() << std::endl;

    // 获取数组指针（指向首地址的指针）
    int *data = aii.data();
    for (int i = 0; i < aii.size(); i++)
    {
        std::cout << data[i] << std::endl;
    }

    // 检查是否为空
    std::cout << std::boolalpha;
    std::cout << "ai.empty()=" << ai.empty() << std::endl;
    std::cout << "aii.empty()=" << aii.empty() << std::endl;
    std::cout << "ai.size()=" << ai.size() << std::endl;
    std::cout << "aii.size()=" << aii.size() << std::endl;
    std::cout << "aii.max_size()=" << aii.max_size() << std::endl;

    // C11 新标准引入了 range-based for 循环，可以直接遍历数组元素
    for (auto &i : aii)
    {
        std::cout << i << "\t";
    }
    return 0;
}
```

## 迭代器
利用迭代器遍历
```cpp
#include <iostream>
#include <array>

int main()
{
    using namespace std;
    array<int, 5> aii = {0, 1, 2, 3, 4};
    array<int, 10>::iterator it = aii.begin(); // 指向第一个元素
    while (it != aii.end())
    {
        cout << *it << " \t";
        it++;
    }
    cout << endl;

    array<int, 5>::iterator it2 = aii.begin();
    for (; it2 != aii.end(); it2++)
    {
        cout << *it2 << " \t";
    }
    cout << endl;

    // 反向迭代器
    array<int, 5>::reverse_iterator rit = aii.rbegin(); // 指向最后一个元素
    while (rit != aii.rend())
    {
        cout << *rit << " \t";
        rit++;
    }
    cout << endl;

    // C11 新标准引入了 range-based for 循环，可以直接遍历数组元素
    for (auto &i : aii)
    {
        std::cout << i << "\t";
    }
    return 0;
}

```