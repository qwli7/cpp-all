#include <iostream>
#include <vector>
#include <string>

// 使用 using 来声明，避免每次都需要写域作用符 std::cout std::cin std::endl

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
int main()
{
    vector<int> v1;              // 初始化了一个模板，容量为0
    vector<int> v2(10);          // 初始化了一个vector，容量为10，初始值为0
    vector<int> v3(10, 42);      // 初始化了一个 vector，容量为10，初始值为 42
    vector<int> v4{10};          // 容量为1，初始值为 10
    vector<int> v5{10, 42};      // 容量为2，初始值为 42
    vector<string> v6{10};       // 容量为10，初始值为 ""
    vector<string> v7{10, "hi"}; // 容量为10，初始值为十个 "hi"
    cout << "v1:size() =" << v1.size() << " v1:capacity() =" << v1.capacity() << endl;
    cout << "v2:size() =" << v2.size() << " v2:capacity() =" << v2.capacity() << endl;
    cout << "v3:size() =" << v3.size() << " v3:capacity() =" << v3.capacity() << endl;
    cout << "v4:size() =" << v4.size() << " v4:capacity() =" << v4.capacity() << endl;
    cout << "v5:size() =" << v5.size() << " v5:capacity() =" << v5.capacity() << endl;
    cout << "v6:size() =" << v6.size() << " v6:capacity() =" << v6.capacity() << endl;
    cout << "v7:size() =" << v7.size() << " v7:capacity() =" << v7.capacity() << endl;
    cout << "v1 ";
    for (auto i : v1)
    {
        cout << i << " ";
    }
    cout << endl
         << "v2 ";
    for (auto i : v2)
    {
        cout << i << " ";
    }
    cout << endl
         << "v3 ";
    for (auto i : v3)
    {
        cout << i << " ";
    }
    cout << endl
         << "v4 ";
    for (auto i : v4)
    {
        cout << i << " ";
    }
    cout << endl
         << "v5 ";
    for (auto i : v5)
    {
        cout << i << " ";
    }
    cout << endl
         << "v6 ";
    for (auto i : v6)
    {
        cout << i << " ";
    }
    cout << endl
         << "v7 ";
    for (auto i : v7)
    {
        cout << i << " ";
    }
    return 0;
}
