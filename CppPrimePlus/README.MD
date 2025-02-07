

## 02.开始学习C++
### C++注释
注释分为两种
- `C`风格注释 `/*注释内容*/` 
- `C++`风格注释， 以 `//` 开头

### C++预处理器
`#include <iostream>` 就是一个预编译指令，会在源代码被编译之前，将 `iostream` 的头文件添加进来；只做添加和替换，不检查语法错误；
可以使用预处理参数 `-E` 来进行验证

```cpp
#include <iostream>
int main() {
    using namespace std;
    std::cout << "hello world" << std::endl;
    return 0;
}
```
通过如下命令来验证
```cpp
g++ -E hello.cpp -o hello.i    //只做添加和替换
```

## 03.处理数据
程序的本质就是处理数据；计算机按照  `0` `1` 的方式来存储数据；

计算机内存的基本单位是位 `bit`；一位只能用 `0` 或者 `1` 来表示；字节 `byte` 通常指的是 `8` 位的内存单元；`1KB` 等于 `1024`字节，`1MB` 等于 `1024KB`

如果 `int` 占用 `16` 位，那么 `int` 可以存储的范围就是 `2^{15}`，也就是 `-32768~32767` （第一位必须是符号位）

使用 `sizeof` 关键字可以查看数据类型所占用的字节大小，输出单位是**字节**

[Chapter03/sizeof.cpp](Chapter03/sizeof.cpp)


数据类型分为 **基本类型**和**复合类型**；变量存储在计算机中，必须要记住三个基本属性：
- 信息存在哪里
- 存储什么值
- 存储什么类型的信息

### 基本类型
基本类型主要是整型和浮点型，还有一些基于当前类型的变体
- 整型  `short` `int` `long`
- `C99`标准新增的 `long long` 以及 `unsigned long long`，类型至少为 `64`位
- 字符型 `char`，使用一个字节存储 `8 bit`
- 布尔类型 `bool` 一个字节存储 `8 bit`，任何非 `0` 的数都是 `true`，`false` 都会被转换成 `0`
- 浮点型  `float` `double` `long double`

### 复合类型
- 由基本数据类型组成

### 无符号类型
- 整型的 `short` `int` `long` 都有无符号的变体，可以增大变量能够存储的最大值
- 假设 `short` 表示的范围是 `-32768~32767 (2^{15})`，那么无符号位则可以表示的范围是 `0~65535 (2^{16})`，将近扩大到了一倍
- 哪些数据可以使用无符号类型？
    - 客观事实存在的，比如年龄，人口数量这些等，从客观上来说不可能存在负数
    - 定义无符号类型只需要在类型前面加上 `unsigned` 即可；注意 `unsigned` 本身是 `unsigned int` 的缩写


### 变量初始化
变量在声明后，其内存储的是一些奇奇怪怪的值；为了避免不必要的麻烦，建议在声明变量的时候就对其进行初始化；

以下几种初始化的方式均可
```cpp
int owls = 101; //C初始化
int wrens(432);  // C 初始化

int hamburgers = {24}; //C11初始化方式，也可以省略 = 
int emus{5}; // C11

int rocs = {}; //变量将被初始化成0
int psychics{};  //变量将被初始化成0
```

使用 `{}` 进行初始化的方式被称之为**列表初始化**


### 进制类型
`C++` 使用前一（两）位来表示进制类型
- 第一位是 1~9，则基数为十（十进制）
- 第一位是 0，第二位是 1~7，则基数为八（八进制），例如 `042` 等同于十进制的 `34` (4*8+2=34)
- 如果前两位是 `0x` 或者 `0X`，则表示为十六进制；例如 `0xF`等同于十进制的 `15`

[进制输出展示](Chapter03/hexoct.cpp)

### const限定词
在 `C` 中通常使用预编译指令 `#define` 来定义常量，但在 `C++` 中有了更好的做法，使用 `const` 来进行限定，两者作用是相同的；如果你的程序要兼容 `C`，那么使用 `#define` 是最好的选择，否则使用 `const`

### 运算符
`C++` 中有 5 种基本的运算符
- `+` 表示对操作数进行加法运算
- `-` 表示对操作数进行减法运算
- `*` 表示对操作数进行乘法运算
- `/` 表示对操作数进行除法运算
    - 操作数都是整数，结果为商的部分；例如 `9/2=4`，小数部分被直接丢弃
- `%` 对操作数进行取模（两个操作数必须都是整型，该操作符用于浮点型将导致编译错误）

![各种除法](images/image_divide.png)


## 04.复合类型
复合类型使用多个基本数据类型组成，包括但不限于数组，`C-风格`字符串、`string` 类字符串、结构、共用体、枚举以及指针等

### 数组
数组是一类可以存储多个相同类型的数据格式，在内存中的存储位置是连续的；

声明数组需要满足以下三个规则
- 存储在每个元素中的值的类型
- 数组名
- 数组中的元素个数

```cpp
typeName arrayName[arraySize]; //定义数组的格式

short months[12]; //定义了一个类型为 short、长度为 12 的数组
```
数组的访问通过下标来进行访问，编号从 `0` 开始；数组的长度也可以通过 `sizeof(数组名)/sizeof(元素类型)`来进行计算；如果数组在使用之前，不进行赋值，那么它的值将是不确定的；

[数组的定义和赋值以及获取数组长度](Chapter04/arrayone.cpp)

### 数组初始化规则
```cpp
float hotelTips[5] = {5.0, 2.5}; //只对前两个位置上的元素赋值，其他位置上的元素都被设置成 0
long totals[500] = {0}; //所有位置上的元素都被赋值成0
long totals[500] = {1}; //只对第一个位置上的元素赋值为1，其他位置上的元素都初始化为0

short things[] = {1,2,3,4}; //编译器会自动计算数组的长度为4，但一般不推荐这么做
```
在 `C++11` 中，如果采用初始化列表的方式初始化数组，可以省略 `=`; 例如
```cpp
double earnings[4] {1.2e4, 1.6e4, 1.1e4, 1.7e4};
unsigned int counts[10] = {}; //不包含任何东西，则所有的元素都被初始化成 0 
float balances[100] {}; //同上，全部为 0
```


### 字符串
字符串是存储在内存的连续字节中的一系列字符；在 `C++` 中可以使用两种，一种来自于 `C` 语言，通常称为 `C-风格字符串`，还有一种是 `string` 类库中的方法；

#### 1.C风格字符串

C 风格字符串具有特殊的性质，以空字符（`null character`）结尾，空字符被写作 `\0`，其 `ASCII` 码值为 `0`，用来标记字符串结尾；例如
```cpp
char dog[8] = {'b', 'e', 'a', 'u', 'x', ' ', 'I', 'I'}; //不是字符串，是一个字符数组
char cat[8] = {'f', 'a', 't', 'e', 's', 's', 'a', '\0'}; //字符串
```
还有一种字符串常量的方式初始化，但结尾仍然有隐式的空字符
```cpp
char bird[11] = "Mr. Cheeps"; // \0 会被自动添加到结尾，注意长度需要包含 \0 字符
char fish[] = "Bubbles"; //编译器会自动推导长度
```

注意：`sizeof(数组名)` 计算的是整个数组的长度，而 `strlen(数组名)` 计算的是存储在字符串中的长度，且不包含空字符；

[字符串练习](Chapter04/4.2_string.cpp)

`cin` 在确定完成输入的时候，会通过 **空格**、**制表符**、**换行符**来确定字符的结尾位置；这意味着 `cin` 在湖区字符数组输入时，只读取一个单词，获取到该单词后，`cin` 将字符串放到数组中，并在结尾添加空字符；
例如
```cpp
#include <iostream>
int main() {
    using namespace std;
    const int size = 20;
    char name[size];
    char name2[size];

    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter your another name: ";
    cin >> name2;

    cout << name1 << "===" << name2 << endl;

    return 0;
}
```
当你输入 `John Mack` 时，最后一行输出语句就会自动执行，不会等到你第二次输入 `name`; 原因就是因为它把 `John` 放入了 `name1`，把 `Mack` 放入了 `name2`;

如果你要读取一行输入，那么就需要使用 `getline()` 或者 `get()`；两者的区别就是 `getline()` 会丢弃换行符，而 `get()` 不会，会将换行符保留在输入队列中;

```cpp
cin.getline(name,20); //这一行输入的字符不能超过 19 个

```
![cin_getline()](images/image_cin_getline.png)

#### 2.string类
`C++98` 中添加了 `string` 类扩展了 `C++` 的类库，使得字符串的使用更加简单；`string` 对象和字符串数组之间的主要区别就是可以将 `string` 对象声明为简单变量，而不是数组；

```cpp
// 需要引入 string 头文件 
// #include <string>
string str1;
string str2 = "panther";

cin >> str1; //输入到 str1 中时，string 对象会自动调整大小
```

初始化方式（不管是 `string` 还是 `C-风格字符串`，都可以使用列表初始化的方式去进行初始化）
```cpp
char first_date[] = {"Le Chapon Dodu"};
char second_date[] {"The Elegant Plate"};
string third_date = {"The Bread Bowl"};
string fourth_date {"Hank's Fine Eats"};
```

### string类的操作
在没有增加 `string` 类之前，对字符串的操作需要使用 `C string` 库来完成操作；例如 `strcpy()` 将字符串赋值到字符数组中、`strcat()` 将字符串附加到字符数组末尾
```cpp
strcpy(charr1, charr2); //把 charr2 拷贝到 charr1中
strcat(charr1, charr2); //把 charr2 追加到 charr1 中
```

`string` 则可直接使用赋值和 `+` 操作符来处理，简化了不少；

[c风格字符串和string类操作字符串的操作比较](Chapter04/4.9_strtype3.cpp)

在输入上也有些不同
```cpp
cin.getline(charr1, 20); //需要指明长度，可能会有越界的风险
getline(cin, str1); //会自动计算长度
```


### 结构
和 `C` 语言一样，`C++` 也支持结构
```cpp
//定义结构
struct inflatable {
    char name[20];
    float volume;
    double price;
};

//使用结构，可以省略 struct 关键字，这点与 C 不同
inflatable hat;
inflatable woopie_cushion;

struct inflatable goose; //C 必须要有 struct 关键字
inflatable vincent; //C++ 中 strcut 不是必须的
```
