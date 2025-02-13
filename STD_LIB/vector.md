`vector` 是一个可变容器，表示对象的集合，使用 `vector` 需要包含头文件 `#include <vector>`；`vector` 是一个类模板，所以我们在声明的时候需要提供存放数据的类型；例如

```cpp
std::vector<int> ivec;  //存放类型为 int
std::vector<Person> pvec; //存放类型为 Person 类
std::vector<vector<std::string>> stringList; //嵌套 vector
```

## 定义和初始化

|  定义                         | 解释                                                            |
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



## Vector操作

### 遍历

使用 `for` 和范围 `for`、迭代器都可以访问 `vector` 中间的元素

```cpp
int main()
{

    std::vector<int> ivec = {1, 2, 3, 4, 5};
    //范围 for
    for (auto i : ivec)
    {
        std::cout << i << " ";
    }
  
    for (auto &i : ivec)
    {
        std::cout << i << " ";
    }
   
	//迭代器
    for (std::vector<int>::iterator it = ivec.begin(); it != ivec.end(); ++it)
    {
        std::cout << *it << " ";
    }
    
    //下标访问
    for (int i = 0; i < ivec.size(); ++i)
    {
        std::cout << ivec[i] << " ";
    }

    return 0;
}

```

迭代器中的 `begin` 指向第一个元素，`end` 指向末尾元素的下一个元素；

**使用了迭代器的循环体，都不要向迭代器中所属的容器添加元素**



利用迭代器计算每个阶段分数人数多少

```cpp
int main()
{

    std::vector<int> ivec = {21, 23, 45, 57, 89, 99, 100, 64, 68, 92};
    // 定义存储每个分数阶段的容器
    std::vector<int> score_stage(11);
    std::vector<int>::iterator it = ivec.begin();
    std::vector<int>::iterator end = ivec.end();
    for (; it != end; ++it)
    {
        score_stage[(*it) / 10] += 1;
    }
    for (auto i : score_stage)
    {
        std::cout << i << " "; //0 0 2 0 1 1 2 0 1 2 1
    }
    std::cout << std::endl;
    return 0;
}

```

