#include <iostream>
#include <string>
#include <cassert>

using std::cin;
using std::cout;
using std::endl;
using std::string;

const string sought = "the";

void f()
{
    cout << "f() called" << endl;
}

void f(int)
{
    cout << "f(int) overload called" << endl;
}

void f(int, int)
{
    cout << "f(int, int) overload called" << endl;
}
void f(double, double = 3.14)
{
    cout << "f(double, double) overload called" << endl;
}

int main()
{
    f(2.56, 3.14);
    // f(2.56, 42); //二义性，编译报错
    f(42);
    f(42, 0);

    return 0;
}