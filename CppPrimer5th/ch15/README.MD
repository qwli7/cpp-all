## ch15 面向对象程序设计
**虚函数**：父类希望子类各自定义适合自己的版本，基类就将该方法标注为虚函数（virtual function）
```cpp
class Quote {
public:
  std::string isbn() const;
  virtual double net_price(std::size_t n) const; //子类可以重写该方法 
}
```

子类必须明确指定它是从哪一个类派生出来的。
```cpp
class Animal {

};

class Dog: public Animal { //指明由 Animal 派生出来的

}
```


## ch15 练习
### ex15.1
什么是虚成员？
> 需要被子类覆盖的成员为虚成员。子类覆盖时加上 override 关键字


### ex15.2
protected 访问说明符与 private 有何区别？
> protected 可以被子类继承过去，private 只属于当前这个类，不能被改写，继承

### ex15.3
定义你自己的 Quote 类和 print_total 函数
```cpp
class Quote
{
public:
    Quote() = default;
    Quote(const std::string &book, double sales_price) : bookNo(book), price(sales_price) {}
    std::string isbn() const { return bookNo; }
    // 由子类改写
    virtual double net_price(std::size_t n) const { return n * price; }
    // 定义打印函数
    virtual void print_total();

private:
    std::string bookNo;

protected:
    double price = 0.0;
};
```
