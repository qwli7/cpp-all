#include <iostream>

#include <vector>
#include <string>
#include <list>
#include <deque>

using std::cin;
using std::cout;
using std::endl;
using std::list;
using std::string;
using std::vector;

int main()
{
    vector<int> c;
    // cout << c.at(0) << endl;    // out of range error 报错
    // cout << c.front() << endl;  // 未定义行为，空容器
    // cout << *c.begin() << endl; // 未定义行为，空容器
    // cout << c[0] << endl;       // 未定义行为，空容器

    cout << "---------------" << endl;
    c.push_back(1);
    cout << c.at(0) << endl;    // 1
    cout << c.front() << endl;  // 1
    cout << *c.begin() << endl; // 1
    cout << c[0] << endl;       // 1
    return 0;
}