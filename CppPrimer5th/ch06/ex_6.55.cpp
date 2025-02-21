#include <iostream>
#include <vector>
#include <cctype>
#include <exception>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int add(int, int);
int sub(int, int);
int mul(int, int);
int divide(int, int);

using PF = int (*)(int, int);

int main()
{
    int (*funPtr)(int, int);         // 定义一个函数指针
    vector<decltype(funPtr)> funVec; // 定义一个函数指针数组
    // vector<int(*)(int, int)> funVec;
    // vector<PF> funVec; // 定义一个函数指针数组
    funVec.push_back(add);
    funVec.push_back(sub);
    funVec.push_back(mul);
    funVec.push_back(divide);

    for (decltype(funPtr) it : funVec)
    {
        cout << it(10, 2) << endl;
    }

    // for (PF it : funVec)
    // {
    //     cout << it(10, 2) << endl;
    // }
    return 0;
}

int add(int a, int b)
{
    return a + b;
}

int sub(int a, int b)
{
    return a - b;
}

int mul(int a, int b)
{
    return a * b;
}
int divide(int a, int b)
{
    return a / b;
}
