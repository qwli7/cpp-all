#include <iostream>

// 声明了一个函数模板
template <typename T> // 可以使用 template <class T> 来代替
void Swap(T& a, T& b);

int main()
{
	using namespace std;
	int a = 10;
	int b = 20;
	// 交换 a b 的值
	Swap(a, b); //编译器会自动生成该函数的 int 交换版本
	cout << "a, b = " << a << ", " << b << endl;

	// 交换 cd 的值
	double c = 3.14;
	double d = 2.71;
	Swap(c, d);  //编译器会自动生成该函数的 double 交换版本
	cout << "c, d = " << c << ", " << d << endl;

	return 0;
}

// 函数定义
template <typename T>
void Swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}