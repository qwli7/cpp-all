#include <iostream>
#include <string>
#include <list>

using std::cin;
using std::cout;
using std::endl;
using std::list;
using std::string;

int main()
{
    list<string> m_list;
    std::string s;
    while (cin >> s)
    {
        m_list.push_back(s);
    }

    // 打印队列元素
    for (list<string>::const_iterator it = m_list.cbegin(); it != m_list.cend(); ++it)
    {
        cout << *it << " ";
    }
    return 0;
}