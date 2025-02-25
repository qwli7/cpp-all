## ch08 IO库


## ch08练习题
### ex8.1
编写函数，接收一个 istream& 参数，返回类型也是 istream&。此函数须从给定的流中读取数据，直至遇到文件结束标识时停止。它将读取的数据打印在标准输出上。完成这些操作后，在返回流之前对流进行复位。使其处于有效状态
```cpp
std::istream &read(std::istream &is)
{
    int n;
    while (is >> n)
    {
        cout << n << " ";
    }
    if (is.eof()) // 遇到文件结束符
    {
        cout << "EOF" << endl;
    }
    if (is.fail()) // 输入失败，如果输入的类型不是 int
    {
        cout << "Fail" << endl;
    }
    if (is.bad())
    {
        cout << "Bad" << endl;
    }

    is.clear();
    return is;
}
```

### ex8.2
测试函数，调用参数 cin
```cpp
int main() {
  read(std::cin)
}
```

### ex8.3
什么情况下 while 循环会中止
```cpp
while(cin >> i) {}; //读取到文件末尾，读取不正确的数，读取到结束符 etc
```

### ex8.4
编写函数，以只读模式打开一个文件，将其内容读入到一个 string 的 vector 中，将每一行作为一个独立的元素存于 vector 中
```cpp
std::vector<std::string> readFileToVector(const std::string &filename)
{
    std::vector<std::string> lines;
    std::ifstream file(filename); // 以只读模式打开文件
    if (!file.is_open())
    {
        std::cerr << "open file " << filename << " failed!" << std::endl;
        return lines;
    }
    std::string line;
    while (std::getline(file, line))
    {
        // 逐行读取文件内容
        lines.push_back(line);
    }
    file.close();
    return lines;
}
```
[ex_8.4.cpp](ex8.4.cpp)

### ex8.5.cpp
重写上面的程序，将每个单词作为一个独立的元素存储。
```cpp
std::vector<std::string> readFileToVector(const std::string &filename)
{
    std::vector<std::string> lines;
    std::ifstream file(filename); // 以只读模式打开文件
    if (!file.is_open())
    {
        std::cerr << "open file " << filename << " failed!" << std::endl;
        return lines;
    }
    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream iss(line); // 字符串流
        std::string word;
        while (iss >> word)
        {
            lines.push_back(word);
        }
    }
    file.close();
    return lines;
}
```
[ex_8.5.cpp](ex8.5.cpp)

### ex8.6
重写 7.1.1 节的书店程序，从一个文件中读取交易记录，将文件名作为一个参数传递给 main

[ex_8.6.cpp](ex8.6.cpp)


### ex8.7
修改上一节的书店程序，将结果保存到一个文件中。将输出文件名作为第二个参数传递给 main 函数

[ex_8.7.cpp](ex8.7.cpp)

### ex8.8
修改上一题的程序，将结果追加到指定的文件末尾。对同一个输出文件，运行程序至少两次，检验数据是否得以保留。

[ex_8.8.cpp](ex8.8.cpp)

模式可通过位或（|）组合，如ios::out | ios::binary。
|模式|解释|
|----|----|
|ios::in| 读取 `ifstream` 默认|
|ios::out| 写入 `ofstream` 默认|
|ios::app| 追加，写入文件到末尾|
|ios::binary| 二进制模式，避免文本转换|
|ios::ate| 打开后定位到文件末尾(at end)|

### ex8.9
使用 ex8.5.cpp 节的练习，打印 istringstream 对象的内容
```cpp
std::vector<std::string> readFileToVector(const std::string &filename)
{
    std::vector<std::string> lines;
    std::ifstream file(filename); // 以只读模式打开文件
    if (!file.is_open())
    {
        std::cerr << "open file " << filename << " failed!" << std::endl;
        return lines;
    }
    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream iss(line); // 字符串流
        std::string word;
        while (iss >> word) //读取单词
        {
            lines.push_back(word);
        }
    }
    file.close();
    return lines;
}
```

### ex8.10
编写程序，将来自一个文件中的行保存在一个 vector<string> 中，然后使用一个 istringstream 从 vector 中读取元素，每次读取一个单词；

[ex_8.10.cpp](ex_8.10.cpp)


### ex8.11
本节的程序在外层 while 循环中定义了 istringstream 对象。如果 record 对象定义在循环之外，你需要对程序进行怎样的修改？重写程序，将 record 的定义转移到 while 循环之外，验证你设想的修改方法是否正确

[ex8.11.cpp](ex_8.11.cpp)

### ex8.12
我们为什么没有在PersonInfo 中使用类内初始化？
>  PersonInfo 的属性由 cin 提供，在该例子中不需要使用类内初始化的能力

### ex8.13
重写本节的电话号码程序，从一个命名文件而非 cin 读取数据。

[ex_8.13.cpp](ex_8.13.cpp)

### ex8.14
我们为什么将 entry 和 nums 定义为 const auto & ？
> 仅仅只是打印，不需要修改，所以声明为 const，声明为引用是为了避免值传递
