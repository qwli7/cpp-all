# ch12 动态内存

## 12.1动态内存与与智能指针
- `new` 在动态内存中为对象分配空间，并返回一个指向该对象的指针
- `delete` 接受一个动态对象的指针，销毁该对象，并释放与之管理的内存

`shared_ptr` 允许多个指针指向同一个对象；`unique_str` 独占所指向的对象；两种类型都定义在 `memory` 头文件中。

|操作|说明|
|----|----|
|`shared_ptr<T> sp`, `unique_ptr<T> up`|空智能指针，可以指向类型为 `T` 的对象|
|`p`|将 `p` 用作一个条件判断，若 `p` 指向一个对象，则为 `true`|
|`*p`|解引用 `p`，获得它指向的对象|
|`p->mem`|等价于 `(*p).mem`|
|`p.get()`|返回 `p` 中保存的指针。要小心使用，若只能指针释放了其对象，返回的指针所指向的对象也就消失了|
|`swap(p, q)`, `p.swap(q)`|交换 `p` 和 `q` 中的指针|

对于一块内存，`shared_ptr` 类保证只有有任何 `shared_ptr` 对象引用它，它就不会被释放；直到引用计数变成 `0`，那么被 `shared_ptr` 指向的那块内存才会被释放。

```cpp
int main()
{

    std::shared_ptr<int> ptr = std::make_shared<int>(4); // 指向一个值为4的 int 指针
    // 指向一个值为 9 个 'h' 的字符串指针
    std::shared_ptr<std::string> str_ptr = std::make_shared<std::string>(9, 'h');

    // 初始化一个智能指针，初始值为0
    std::shared_ptr<int> iptr2 = std::make_shared<int>();

    // 也可以用 auto 和 decltype 来简化代码
    // 指向一个空的 vector<int> 向量
    auto ptr3 = std::make_shared<std::vector<int>>();

    // shared_ptr 有引用计数
    auto ptr4 = std::make_shared<int>(5); // 指向一个值为5的 int 指针
    // ptr5 和 ptr4 指向同一个对象，此时 5 这个 int 两个指针指向它
    auto ptr5(ptr4);

    // 如果是赋值语句，将不会递增引用计数
    auto ptr6 = std::make_shared<int>(6);
    {
        // ptr7 离开作用域会被释放，ptr6 在 main 函数未执行完成时，不会被释放
        auto ptr7 = ptr6;
    }
    return 0;
}
```




# ch12练习题
## 12.1.1 节练习
在此代码的结尾，`b1` 和 `b2` 各包含多少个元素？
```cpp
int main()
{

    StrBlob b1;
    {
        StrBlob b2 = {"a", "an", "the"};
        b1 = b2;               // 拷贝赋值
        b2.push_back("about"); // b2的元素也会被拷贝到b1中
    }
    cout << b1.size() << endl; // 输出4
    // b2 离开作用域后已被释放
    return 0;
}
```
> `b1` 中存在  `4` 个元素，`b2` 离开作用域后无效，但由于 `b2` 引用的内存仍然有 `b1` 指向它，所以原内存仍然有效。

