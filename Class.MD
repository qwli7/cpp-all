`vscode` 控制台打印中文乱码，通过输入 `chcp 65001` 可以成功显示中文；

## 类定义





## 访问权限

类的访问权限分为三种

- `Public` 		在类的内部可以访问，在类的外部也可以访问
- `Protected`           在类的内部可以访问，在类的外部不可以访问
- `Private `             在类的内部可以访问，在类的外部不可以访问



```cpp
#include <iostream>
#include <string>
using namespace std;

class Animal
{
public: // 公有成员，类的内部可以访问，外部也可以访问
    string m_Name;
    int m_Age;

private: // 私有成员，类的内部可以访问，外部不可以访问
    int m_Weight;

public:
    void show() // 公有方法，类的内部可以访问，外部也可以访问
    {
        cout << m_Name << ": " << m_Age << endl;
    }

private:
    void setName(string name) // 私有方法，类的内部可以访问，外部不可以访问
    {
        m_Name = name;
    }
};

int main()
{

    Animal a;
    a.m_Name = "dog"; // 公有成员
    a.m_Age = 18;     // 公有成员
    // a.m_Weight = 20;  // 私有访问权限，在类的内部可以访问，在类的外部不可以访问

    // a.setName("cat"); // 私有方法，在类的内部可以访问，在类的外部不可以访问；
    a.show();

    cout << a.m_Name << endl;
    cout << a.m_Age << endl;

    return 0;
}
```



## 对象的初始化和清理

如果我们自己不提供构造函数，编译器会为我们提供默认的构造函数和析构函数；



- 构造函数：主要作用在于创建对象时为对象的成员属性赋值，构造函数由编译器自动调用，无需手动调用
- 析构函数：主要作用在于对象销毁前系统的自动调用，执行一些清理工作；



**构造函数语法：** `类名(){}`

1. 构造函数，没有返回值，也不写 `void`
2. 函数名称与类名称相同
3. 构造函数可以有参数，因此可以发生重载
4. 程序在调用对象的时候，会自动调用构造函数；无须手动调用，而且只会调用一次

**析构函数语法：**`~类名(){}`

1. 析构函数，没有返回值也不写 `void`
2. 函数名称与类名相同，在名称前加上符号`~`
3. 析构函数不可以有参数，因此不可以发生重载
4. 程序在对象销毁前会自动调用析构；无须手动调用，而且只会调用一次



```cpp
#include <iostream>
#include <string>
using namespace std;


//构造函数分类
//按照参数分类：有参和无参，无参为默认构造函数
//按照类型分类：普通和拷贝构造函数

class Person
{

public:
    // 构造函数
    // 实例化对象会被调用
    // 只会被调用一次
    // 有参数，可以发生重载
    Person()
    {
        cout << "无参构造函数调用" << endl;
    } // 默认构造函数
    Person(int a)
    { // 有参构造函数
        age = a;
        cout << "有参构造函数调用" << endl;
    }
    Person(const Person &p)
    { // 拷贝构造函数
        age = p.age;
        cout << "拷贝构造函数调用" << endl;
    }

    // 析构函数（没有参数，方法名和类名相同，在前面加上 ~）
    // 只能被调用一次
    // 不能发生重载
    // 不需要手动调用，离开作用域后，编译器会自动调用，释放空间
    ~Person()
    {
        // 析构函数
        cout << "析构函数调用" << endl;
    }

    int age;
};

// 括号法调用构造函数
void test01()
{
    Person p; // 调用默认构造函数，默认构造函数不要添加()
    // Person p4();  //不会调用默认构造函数，编译器会将下面一行当作方法声明 和 int func(); 是方法声明一样
    Person p2(10); // 调用有参构造函数
    cout << "p2.age = " << p2.age << endl;
    Person p3(p2); // 拷贝构造函数
    cout << p3.age << endl;
}

// 显式法
void test02()
{
    Person p1;
    Person p2 = Person(10); // 有参构造
    Person p3 = Person(p2); // 拷贝构造函数

    Person(10); // 匿名对象，在当前行执行结束后，系统会立即回收掉匿名对象

    // 不要用拷贝构造函数，初始化匿名对象，编译器会认为 Person (p3) == Person p3; 对象重定义
    // Person(p3);
}

// 隐式转换法
void test03()
{
    Person p = 10; // 隐式调用 Person(int a); 这个构造函数等同于 Person p = Person(10);
    Person p2 = p; // 隐式调用 Person(const Person& p) 拷贝构造函数
}

int main()
{

    // test01();
    // test02();
    test03();

    return 0;
}
```



### 禁用隐式转换

调用构造函数时，可以使用隐式转换规则；在构造函数前加上 `explict` 关键字，可以禁止编译器使用隐式转换规则；



```cpp
#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
    // 不加 explicit 可以使用隐式转换 Person p = 19;
    // 加了后，就必须使用显式的方式去实例化对象
    explicit Person(int age)
    {
        m_Age = age;
    }

    int m_Age;
};

int main()
{

    // Person p = 19; //隐式转换 添加 explicit 这样声明会报错
    Person p2(19); // 显式调用有参构造函数

    cout << "p2.m_Age = " << p2.m_Age << endl;
    return 0;
}
```









## 构造函数提供规则

在不写任何构造函数的情况下，编译器默认会为我们提供以下三个构造函数

- 默认构造函数（空参数，空实现）
- 析构函数
- 拷贝构造函数（简单值拷贝）



```cpp
#include <iostream>
#include <string>
using namespace std;

// 不写任何构造函数的情况下，编译器会默认提供三种构造函数
// 默认构造函数（空实现）
// 默认析构函数（空实现）
// 拷贝构造函数
class Person
{
public:
    int m_Age;
};

int main()
{

    Person p; // 编译器默认提供构造函数
    p.m_Age = 19;
    Person p2(p); // 编译器默认提供的拷贝构造函数

    cout << "p.m_Age = " << p.m_Age << endl;
    cout << "p2.m_Age = " << p2.m_Age << endl;
    return 0;
}

```



#### 规则

- 提供了默认构造函数，编译器将不再提供默认构造函数，但提供拷贝构造函数和析构函数

- 提供了有参构造函数，编译器将不再提供默认构造函数，但提供拷贝构造函数和析构函数

- 提供了拷贝构造函数，编译器将不再提供默认构造函数，但提供析构函数

  

```cpp
class Person
{
public:

    //自定义了默认构造函数，编译器将不再提供默认构造函数，但提供拷贝构造函数
    Person() {

    }

    //自定义了有参构造函数，编译器将不再提供默认构造函数，但提供拷贝构造函数
    Person(int age) {
        m_Age = age;
    }

    // 自定义了拷贝构造函数，编译器将不再提供默认构造函数
    Person(const Person &p)
    {
        m_Age = p.m_Age;
    }
    int m_Age;
};
```









## 拷贝构造函数调用时机

- 用一个类去初始化另一个对象时；
- 当函数的形参是类的对象时（值传递），引用传递不会调用拷贝构造函数；
- 当函数的返回值时类的对象时；



## 浅拷贝和深拷贝

编译器提供的拷贝构造函数，只是做了简单的值拷贝；当类中存在指针变量时，编译器提供的拷贝构造函数会导致程序崩溃



```cpp
#include <iostream>
#include <string>
using namespace std;

// 浅拷贝和深拷贝
// 存在在堆区开辟的内存空间，编译器提供的拷贝构造函数是简单的值拷贝
class Person
{
public:
    Person(int age, int height)
    {
        m_Age = age;
        m_Height = new int(height); 
    }

 

    ~Person()
    {
        if (m_Height != nullptr)
        {
            cout << m_Height << endl;
            cout << "析构函数调用" << endl;
            delete m_Height;
            m_Height = nullptr;
        }
    }

    int m_Age;
    int *m_Height; // 指针变量
};

int main()
{

    Person p(24, 160);
    Person p2(p); // 调用编译器默认提供的拷贝构造函数

    cout << "p.m_Age = " << p.m_Age << endl;
    cout << "p.height =  " << *p.m_Height << endl;
    cout << "p2.m_Age =  " << p2.m_Age << endl;
    cout << "p2.height =  " << *p2.m_Height << endl;
    return 0;
}
```



存在在堆区开辟的内存空间，就一定要自己实现拷贝构造函数**；没有在堆区开辟对象的操作，不需要重写拷贝构造方法**；

```cpp
class Person
{
public:
    Person(int age, int height)
    {
        m_Age = age;
        m_Height = new int(height);
    }
	//自己实现拷贝构造函数，避免两个指针指向同一块内存区域，从而导致该区域被释放两次
    Person(const Person &p)
    {
        m_Age = p.m_Age;
        m_Height = new int(*p.m_Height);
    }

    ~Person()
    {
        if (m_Height != nullptr)
        {
            cout << m_Height << endl;
            cout << "析构函数调用" << endl;
            delete m_Height;
            m_Height = nullptr;
        }
    }

    int m_Age;
    int *m_Height; // 指针变量
};
```



## C11新特性-初始化列表

`c11` 提供了一个初始化对象的方法（赋初始值），相比传统的方式，更加简洁；

定义方式如下 `类名(传入参数): 属性(参数1), 属性(参数2)... {}`



```cpp
#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
    // 传统赋值方法
    // Person(int age, string name)
    // {
    //     m_Age = age;
    //     m_Name = name;
    // }

    // 初始化列表
    Person(int age, string name) : m_Age(age), m_Name(name)
    {
    }

    int m_Age;
    string m_Name;
};

int main()
{

    Person p(24, "hello");

    cout << "p.m_Age = " << p.m_Age << endl;
    cout << "p.name =  " << p.m_Name << endl;
    return 0;
}
```







## 静态成员变量

- 静态成员变量，所有对象共享同一份数据
- 编译阶段分配内存
- 类内声明，类外初始化
- 静态成员函数也是有访问权限的



**访问方式：**

- 通过对象访问
- 通过类名访问



```cpp
#include <iostream>
#include <string>
using namespace std;

// 静态成员变量
class Person
{
public:
    // 静态成员变量，所有对象共享同一份数据
    // 编译阶段分配内存
    // 类内声明，类外初始化
    static int m_Age;

    // 静态成员变量也是有访问权限的
private:
    static int m_B;
};

int Person::m_Age = 10;
int Person::m_B = 20;

void test1()
{
    Person p;
    cout << p.m_Age << endl;
    Person p2;
    p2.m_Age = 200;
    cout << p.m_Age << endl;
    cout << p2.m_Age << endl;
}

void test2()
{
    // 静态成员变量不属于某个对象,所有的对象共享同一份数据
    //  因此静态成员变量有两种访问方式
    // 1. 通过对象访问
    Person p;
    cout << p.m_Age << endl;
    // 2. 通过类名访问
    cout << Person::m_Age << endl;
}

void test3()
{
    // cout << Person::m_B << endl;
}

int main()
{
    // test1();
    test2();
    // tets3();
    return 0;
}
```





## 静态成员函数

- 所有对象共享共一个函数
- 静态成员函数只能访问静态成员变量
- 静态成员函数也是有访问权限的



访问方式：

- 通过对象访问
- 通过类名访问



```cpp
#include <iostream>
using namespace std;

// 静态成员函数
// 所有对象共享共一个函数
// 静态成员函数只能访问静态成员变量
class Person
{
public:
    static void func()
    {
        m_A = 30;
        // m_B = 200; // 静态成员函数只能访问静态变量 无法区分到底是哪个对象的 m_B;
        cout << "static void func() " << endl;
    }

    static int m_A; // 静态成员变量
    int m_B;        // 非静态成员变量

    // 静态成员函数也是有访问权限的
private:
    static void func()
    {
        cout << "static void func" << endl;
    }
};

int Person::m_A = 20;

void test1()
{
    // 1 通过对象访问
    Person p;
    p.func();

    // 2 通过类名访问
    Person::func();

    // Person::func2(); // 类外访问不到私有作用域的静态函数
}

int main()
{

    test1();

    return 0;
}
```







## 成员函数和成员方法分开存储

- 空对象占用对象的空间为1字节
  - C++编译器会给每个空对象分配一个字节的空间,为了区分空对象占用的内存位置
- 非静态成员变量, 属于对象
- 静态成员变量，不属于对象
- 成员函数，不属于对象
- 静态成员函数，不属于对象



```cpp
#include <iostream>
using namespace std;

// C++对象模型和this指针
// 成员和方法是分开存储的

class Person
{
};

class Person2
{
public:
    int m_A; // 非静态成员变量,属于对象
};

class Person3
{
public:
    int m_A;
    static int m_B; // 静态成员变量

    void func()
    { // 不属于对象上
    }

    static void func2()
    { // 不属于对象上
    }
};

int Person3::m_B = 1;

void test1()
{
    Person p;
    // 空对象占用对象的空间为1字节
    // C++编译器会给每个空对象分配一个字节的空间,为了区分空对象占用的内存位置
    cout << sizeof(p) << endl;
}

void test2()
{
    Person2 p;
    cout << sizeof(p) << endl; // 4字节, 存在一个 int 类型
}

void test3()
{
    Person3 p;
    cout << sizeof(p) << endl; //4字节，存在一个非静态成员类型 int
}

int main()
{
    // test1();
    // test2();
    test3();
    return 0;
}
```





## this 指针

- this 指针指向被调用的成员函数所属的对象
- this 指针隐含在每一个非静态函数内的一种指针; 
- 不需要定义，直接使用即可



主要用来解决两类问题

- 解决名称冲突
- `*this` 返回对象本身



```cpp
#include <iostream>
using namespace std;

// this指针
// this指针指向被调用的成员函数所属的对象
// this指针隐含在每一个非静态函数内的一种指针; 不需要定义,直接使用即可
class Person
{
public:
    int age;
    Person(int age)
    {
        // this 指针指向的是被调用的成员函数所使用的对象
        this->age = age; // 解决名称冲突
    }

    // 返回对象本身
    Person &addPerson(Person &p)
    {
        this->age += p.age;
        // 返回对象本身
        return *this;
    }
};

// 解决名称冲突
void test01()
{
    Person p(20);
    cout << p.age << endl;
}

// 返回对象本身 *this
void test02()
{
    Person p1(10);
    Person p2(20);
    // 链式编程
    p2.addPerson(p1).addPerson(p1);
    cout << p2.age << endl;
}

int main()
{
    // test01();
    test02();
    return 0;
}
```







## 空指针访问成员函数



空指针也可以调用成员函数



```cpp
#include <iostream>
using namespace std;

// 空指针也可以调用成员函数
class Person
{

public:
    int m_Age;

    void showName()
    {
        cout << "showName" << endl;
    }
    // 报错, 使用了成员函数,默认会传入一个 this 指针
    void showAge()
    {
        cout << "showAge " << m_Age << endl; // this->m_Age  this 是 nullptr
        // cout << "showAge " << this->m_Age << endl;
    }
};

// 空指针也可以调用成员函数
void test1()
{
    Person *p = nullptr;
    // p->showName();
    p->showAge();
}

int main()
{
    test1();
    return 0;
}
```











## `const`修饰成员函数



常函数：

- 成员函数后加上 `const` 后，我们称这个函数为常函数
- 常函数内不可以修改成员属性
- 成员属性声明时加关键字 `mutable `后，在常函数中依然可以修改



常对象：

- 声明对象前加上 `const` 称该对象为常对象
- 常对象只能调用常函数





## 友元

### 全局函数做友元

全局函数可以访问类中的私有函数

```cpp
class Building
{
    //全局函数是 Building类的友元，可以访问私有成员
    friend void goodGay(Building *building);

public:
    Building()
    {
        m_SittingRoom = "客厅";
        m_BedRoom = "卧室";
    }

public:
    string m_SittingRoom;

private:
    string m_BedRoom;
};

void goodGay(Building *building)
{
    cout << "visit " << building->m_SittingRoom << endl;
    cout << "visit " << building->m_BedRoom << endl; //访问类中的私有成员
}

void test01()
{
    Building building;
    goodGay(&building);
}

int main()
{
    test01();

    return 0;
}
```





### 类做友元

类作为当前类的友元；`friend class B`；类 `B` 作为声明中某个类的友元

```cpp
// 类做友元
class Building; // 前向声明

class GoodGay
{
public:
    GoodGay();
    Building *building;

    // 函数访问Building的公共成员和私有成员
    void visit();
};

class Building
{
    friend class GoodGay; // GoodGay 是 Building 的友元，可以访问私有权限

public:
    Building(); // 在类外写成员函数

public:
    string m_SittingRoom;

private:
    string m_BedRoom;
};

// 类外写成员函数
Building::Building()
{
    m_SittingRoom = "客厅";
    m_BedRoom = "卧室";
}

GoodGay::GoodGay()
{
    building = new Building;
}

void GoodGay::visit()
{
    cout << "visit " << building->m_SittingRoom << endl;
    cout << "visit " << building->m_BedRoom << endl;
}

void test01()
{
    GoodGay goodGay;
    goodGay.visit();
}

int main()
{
    test01();

    return 0;
}
```



### 成员函数做友元

```cpp
class Building; // 前向声明

class GoodGay
{
public:
    GoodGay();
    Building *building;

    // 函数访问Building的公共成员和私有成员
    void visit();

    void visit2(); // 只可以访问公共成员
};

class Building
{
    // 成员函数做友元，告诉编译器，GoodGay 中的 visit() 是本类的友元函数，可以访问本类中的私有成员变量
    friend void GoodGay::visit();

public:
    Building(); // 在类外写成员函数

public:
    string m_SittingRoom;

private:
    string m_BedRoom;
};

// 类外写成员函数
Building::Building()
{
    m_SittingRoom = "客厅";
    m_BedRoom = "卧室";
}

GoodGay::GoodGay()
{
    building = new Building;
}

void GoodGay::visit()
{
    cout << "visit " << building->m_SittingRoom << endl;
    cout << "visit " << building->m_BedRoom << endl; //友元函数可以访问私有成员
}

void GoodGay::visit2()
{
    cout << "visit2 " << building->m_SittingRoom << endl;
    // cout << "visit" << building->m_BedRoom << endl; 不可以访问，不是友元方法
}

void test01()
{
    GoodGay goodGay;
    goodGay.visit();
    cout << "=================" << endl;
    goodGay.visit2();
}

int main()
{
    test01();

    return 0;
}
```



## 运算符重载

内置数据类型，编译器知道该如何处理 `+ - * / `这些运算规则；如果是自定义类型，如果要实现相加，需要对运算符进行重载



通过自己写一个成员函数，可以实现两个自定义对象相加；







## 继承

### 继承语法

语法：`class 类名: [public, protected, private] 继承类名`



继承权限

> 一个原则：父类 `private` 权限的成员，在子类无法访问，也无法被继承



### 继承方式

- `public` 继承（公有继承）：
  - 父类 `public` 权限成员，继承过来也是 `public` 权限（类内部和外部都可以访问）
  - 父类 `protected` 权限成员，继承过来也是 `protected` 权限（类内部可以访问，类外部无法访问）
- `protected` 继承（保护继承）：
  - 父类 `public` 权限成员，继承过来是 `protected` 权限（类内部可以访问，类外部无法访问）
  - 父类 `protected` 权限成员，继承过来也是 `protected` 权限（类内部可以访问，类外部无法访问）
- `private` 继承（隐私继承）：
  - 父类 `public` 权限成员，继承过来是 `private` 权限（类内部可以访问，类外部无法访问）
  - 父类 `protected` 权限成员，继承过来是 `private` 权限（类内部可以访问，类外部无法访问）



```cpp
#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
    int m_A;

private:
    int m_B;

protected:
    int m_C;
};

// public 继承，继承过来的 public 的成员，仍然是 public权限，继承过来的 protected 权限，仍然是 protected 权限
class Son1 : public Person
{

public:
    void func()
    {
        m_C = 200;
        m_A = 200;
        // m_B = 200; //父类隐私的成员子类无法访问
    }
};

// protected 继承，继承过来的 public 和 protected 成员权限统一都变成 protected权限
class Son2 : protected Person
{
public:
    void fun()
    {
        m_C = 200;
        m_A = 200;
        // m_B = 200; //父类隐私的成员子类无法访问
    }
};

// private 继承，继承过来的 public 和 protected 成员权限统一都变成 private 权限
class Son3 : private Person
{
public:
    void fun()
    {
        m_C = 200;
        m_A = 200;
        // m_B = 100; //父类隐私的成员子类无法访问
    }
};

void test01()
{
    Son1 son;
    son.m_A = 100; // 公有成员可以访问
    // son.m_C = 200; // protected 继承过来也是 protected 权限，类外部无法访问
}

void test02()
{
    Son2 son2;
    // son2.m_A = 100; //保护权限，类外无法访问
    // son2.m_C = 100; //保护权限，类外无法访问
}

void test03()
{
    Son3 son3;
    // son3.m_A = 100; // private 权限，类外无法访问
    // son3.m_B = 100; // 父类隐私的成员子类无法访问
    // son3.m_C = 100; // private 权限，类外无法访问
}

int main()
{
    return 0;
}
```





### 继承中的对象模型

父类的 `private` 成员，会被继承下去，只是被隐藏了；

- 父类中非静态成员，都会被继承下去
- 父类中的私有成员，只是被编译器隐藏了，因此只是访问不到；



通过 `vs` 提供的工具可以查看对象的内存模型

`cl /d1 reportSingleClassLayoutSon "main.cpp"`





```cpp
#include <iostream>
#include <string>
using namespace std;

class Base
{
public:
    int m_A = 30;

protected:
    int m_B = 20;

private:
    int m_C = 10;
};

//父类中非静态的所有成员，都会被继承下去
//父类中私有的成员，只是被编译器隐藏了，只是访问不到
class Child : public Base
{
public:
    int m_D;
   
};

void test01()
{
    Child child;
    cout << sizeof(child) << endl; // 16, m_C 被继承下来了，只是被隐藏了，不可以直接访问；不过通过指针手段仍然可以访问 m_C 的值
}

int main()
{

    test01();

    return 0;
}
```



### 继承中的构造和析构顺序

子类继承父类后，当创建子类对象，也会调用父类的构造函数；



问题：父类和子类的构造和析构顺序谁先谁后？



**示例：**

```cpp
#include <iostream>
#include <string>
using namespace std;

class Base
{
public:
    Base()
    {
        cout << "Base 构造函数" << endl;
    }
    ~Base()
    {
        cout << "Base 析构函数" << endl;
    }
};

class Son : public Base
{
public:
    Son()
    {
        cout << "Son 构造函数" << endl;
    }
    ~Son()
    {
        cout << "Son 析构函数" << endl;
    }
};

void test01()
{
    //构造顺序：先调用父类构造函数，再调用子类构造函数
    //析构顺序：先调用子类析构函数，再调用父类析构函数
    Son son;
}
int main()
{

    test01();

    return 0;
}

```

构造/析构函数调用顺序：（满足先进后出的原则）

- 先调用父类构造函数，再调用子类构造函数
- 先调用子类析构函数，再调用父类析构函数





### 同名成员处理

当父类和子类中存在相同的成员时，如何通过子类对象，访问到子类对象，访问到子类或者父类中同名的数据呢？



- 访问子类同名成员，直接访问即可；
- 访问父类名称成员，需要加作用域；



**示例：**

```cpp
#include <iostream>
#include <string>
using namespace std;

class Base
{
public:
    int m_A = 20;
    void func()
    {
        cout << "Base func " << endl;
    }
};

class Son : public Base
{
public:
    int m_A = 30;
    void func()
    {
        cout << "Son func " << endl;
    }
};

void test01()
{
    Son son;
    cout << "Son m_A = " << son.m_A << endl;
    cout << "Base m_A = " << son.Base::m_A << endl;

    cout << "---------------" << endl;
    Son *son2 = new Son;
    cout << "Son2 m_A = " << son2->m_A << endl;
    cout << "Base2 m_A = " << son2->Base::m_A << endl;
    delete son2;
}

void test02()
{
    Son son;
    son.func();
    son.Base::func();

    cout << "---------------" << endl;
    Son *son2 = new Son;
    son2->func();
    son2->Base::func();
}
int main()
{

    // test01();
    test02();

    return 0;
}
```



总结：

1. 子类对象可以直接访问到子类中同名成员
2. 子类对象加作用域可以访问到父类同名成员
3. 当子类与父类拥有同名的成员函数，子类会隐藏父类中同名成员，加作用域可以访问到父类中同名函数





### 同名静态成员处理

问题：继承中同名的静态成员在子类对象中如何进行访问？



静态成员和非静态成员出现同名，处理方式一致；子类直接通过 `.` 调用，调用父类需要加作用域



- 访问子类同名成员，直接访问即可
- 访问父类同名成员，需要加作用域



**示例：**

```cpp
#include <iostream>
#include <string>
using namespace std;

class Base
{
public:
    static int m_A;
    static void func()
    {
        cout << "Base - static void func() " << endl;
    }
};

class Son : public Base
{
public:
    static int m_A;

    static void func()
    {
        cout << "Son - static void func()" << endl;
    }
};

int Base::m_A = 100;
int Son::m_A = 200;

// 同名静态成员属性
void test01()
{
    // 1，通过对象访问
    Son s;
    cout << "Son m_A = " << s.m_A << endl;              // 子类 200
    cout << "Son Base m_A = " << s.::Base::m_A << endl; // 父类 100

    // 2.通过类名访问
    cout << Son::m_A << endl;
    cout << Son::Base::m_A << endl;
}

// 同名静态函数
void test02()
{
    // 1.通过对象访问
    Son s;
    s.func();

    s.Base::func();

    cout << "------------------" << endl;

    // 2.通过类名访问
    Son::func();
    Son::Base::func();
}

int main()
{

    // test01();
    test02();
    return 0;
}
```



总结：

同名的静态成员处理方式和非静态处理方式一样，只不过有两种访问的方式（通过对象调用和通过类名调用）



### 多继承语法

