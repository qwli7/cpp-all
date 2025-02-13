`vector` 是一个可变容器，表示对象的集合，使用 `vector` 需要包含头文件 `#include <vector>`；`vector` 是一个类模板，所以我们在声明的时候需要提供存放数据的类型；例如

```cpp
std::vector<int> ivec;  //存放类型为 int
std::vector<Person> pvec; //存放类型为 Person 类
std::vector<vector<std::string>> stringList; //嵌套 vector
```

## 定义和初始化

|                               |                                                             |
| ----------------------------- | ----------------------------------------------------------- |
| `vector<T> v1`                | `v1` 是一个空 `vector`，元素类型是 `T`，执行默认初始化      |
| `vector<T> v2(v1)`            | `v2 `中包含所有 `v1 `元素的副本                             |
| `vector<T> v2=v1`             | 等价 `vector<T> v2(v1)`                                     |
| `vector<T> v3(n, val)`        | `v3 `包含了 `n `个重复的 `val`                              |
| `vector<T> v4(n)`             | `v4` 包含了 `n `个 `T `对象，每个对象重复执行了值初始化对象 |
| `vector<T> v5{a, b, c, ...}`  | `v5 `包含了初始值个数，每个元素被赋予相应的初始值           |
| `vector<T> v5={a, b, c, ...}` | 等价于 `vector<T> v5{a, b, c, ...}`                         |

```cpp
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> ivec; //初始值为空
    
    std::vector<int> ivec2(10); //初始值有10个元素，值都是0
    
    std::vector<int> ivec3(10, 42); //初始值有10个元素，值都是42
    
    //拷贝构造
    std::vector<int> ivec4(ivec3); //拷贝ivec3
    
  	//初始化列表
    std::vector<int> ivec5 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; //使用花括号初始化
    
    std::vector<std::string> svec = {"hello", "world"}; 
    
    std::vector<std::string> svec2 = svec; //拷贝svec
    
    std::vector<std::string> svec3{"zhangsan", "lisi"};
    return 0;
}

```

