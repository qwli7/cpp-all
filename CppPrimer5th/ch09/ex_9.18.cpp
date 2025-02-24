#include <iostream>
#include <string>
#include <deque>

using std::cin;
using std::cout;
using std::deque;
using std::endl;
using std::string;

int main()
{
    deque<string> dq;
    std::string s;
    while (cin >> s)
    {
        dq.push_back(s);
    }

    // 打印队列元素
    for (deque<string>::const_iterator it = dq.cbegin(); it != dq.cend(); ++it)
    {
        cout << *it << " ";
    }
    return 0;
}