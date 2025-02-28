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

### 12.1.2 直接管理内存
```cpp
int *pi = new int; //pi 指向一个动态分配的、未初始化的无名对象

//类型对象将使用默认构造函数进行初始化
std::string *ps = new std::string; //默认构造函数，初始化为空字符串


//构造的时候直接初始化
int *pi2 = new int(42); //pi2 指向一个动态分配的、值为 42 的 int 对象
std::string *ps2 = new std::string(10, 'h'); //ps2 指向一个动态分配的、值为 10 个 'h' 的字符串对象)

std::vector<int> *pv = new std::vector<int>{1,2,3}; //pv 指向一个动态分配的、值为 {1,2,3} 的 vector 对象

//初始化 const 
const int *pci = new const int; // 报错，pci 指向一个常量，必须被初始化
const int *pci2 = new const int(42); // pci2 指向一个常量 int 对象，值为 42

const std::string *pcs = new const std::string(); // pcs 指向一个常量空字符串对象

//分配失败
int *pi3 = new int;//分配失败，抛出 bad_alloc 异常
int *pi4 = new (nothrow) int; //分配失败，返回 nullptr

```

释放内存通过 `delete` 关键字来释放；释放一块不是由 `new` 分配的内存或者多次释放同一块内存，都会导致未定义的行为；

如果忘记释放内存，将会导致内存泄露，这种问题不好排查；总之建议坚持使用智能指针来管理内存。如果手动释放内存，记得将指针赋值为 `nullptr`，避免出现悬空指针的问题；

# ch12练习题
## 12.1.1 节练习
### ex12.1
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
> `b1` 中存在  `4` 个元素，`b2` 离开作用域后无效，但由于 `b2` 指向的内存仍然有 `b1` 指向它，所以原内存仍然有效。

### ex12.2
编写你自己的 `StrBlob` 类，包含 `const` 版本的 `front` 和 `back` 函数。

[ex12.2.cpp](ex_12.2.cpp)

### ex12.3
`StrBlob` 需要 `const` 版本的 `push_back` 和 `pop_back` 吗？如果需要，添加进去。否则解释为什么不需要。

> 不需要，因为 `push_back` 和 `pop_back` 对 `StrBlob` 里面的数据做了更改，如果是 `const` 对象，则无法修改其数据，所以不需要 `const` 版本的 `push_back` 和 `pop_back`。

### ex12.4
在我们的 `check` 函数中，没有检查 `i` 是否大于 `0`。为什么可以忽略这个检查？

> `size_type` 本身的类型是一个无符号的类型；`long unsigned int` 

### ex12.5
我们未编写接受一个 `initializer_list explicit` 参数的构造函数。讨论这个设计的优缺点。

> 使用了 `explicit` 则声明了拒绝编译器的隐式转换，`StrBlob sb = {"hello", "world"};` 这样的定义会报错，必须使用 `StrBlob sb = StrBlob({"hello", "world"});` 这样的形式，降低了灵活性；缺点是增加了代码量。
----
## 12.1.2 节练习
### ex12.6
编写函数，返回一个动态分配的 `int` 的 `vector`。将此 `vector` 传递给另一个函数，这个函数读取标准输入，将读入的值保存在 `vector` 元素中。再将 `vector` 传递给另一个函数，打印读入的值。记得在恰当的时刻`delete vector`。

[ex12.6.cpp](ex_12.6.cpp)

### ex12.7
重做上一题，这次使用 `shared_ptr` 而不是内置指针。

[ex12.7.cpp](ex_12.7.cpp)

### ex12.8
下面的函数是否由错误？如果有，解释错误原因。
```cpp
bool b() {
    int *p = new int;

    //....

    return p; // 错误，返回指针而不是 bool 值，没有释放时始终会返回 true
}
```

### ex12.9
解释下面代码的执行结果。
```cpp
int *q = new int(42), *r = new int(100); //初始化两个指针
r = q; // r 指向 q 指向的对象，没有释放 q 指向的对象，q指向的内存 不会被释放
auto q2 = make_shared<int>(42), r2 = make_shared<int>(100); //初始化两个智能指针
r2 = q2; // r2 指向 q2 指向的对象，q2 将会被自动释放，不需要手动调用 delete
```

## 12.1.3 节练习
### ex12.10
下面的代码调用了第 `413` 页中定义的 `process` 函数，解释此调用是否正确。如果不正确，应如何修改？
```cpp
//在函数被调用时，ptr 被创建并初始化
void process(shared_ptr<int> ptr) {
    //do something
} // ptr 离开作用域，被销毁

shared_ptr<int> p(new int(42)); 
process(shared_ptr<int>(p));
```


### ex12.11
如果我们像下面这样调用 `process`，会发生什么？
```cpp
process(std::shared_ptr<int>(p));
```


### ex12.12
`p` 和 `q` 的定义如下，对于接下来的对 `process` 的每个调用，如果合法，解释它做了什么，如果不合法，解释错误原因。
```cpp
auto p = new int();
auto sp = make_shared<int>();

//a
process(sp);

//b
process(new int());

//c
process(p);

//d
process(shared_ptr<int>(p));
```

### ex12.13
如果执行下面的代码，会发生什么？
```cpp
auto sp = make_shared<int>();
auto p = sp.get();
delete p;
```

----
## 12.1.4 节练习
### ex12.14
编写你自己版本的用 `shared_ptr` 管理 `connection` 的函数。


### ex12.15
重写第一题的程序，用 `lambda` 代替 `end_connection` 函数。


----
## 12.1.5 节练习

