## forward_list（C++11）
单向链表，只能向前遍历，不能随机访问。

```cpp
#include <iostream>
#include <array>
#include <forward_list>

int main()
{
    using namespace std;
    forward_list<int> fl = {1, 2, 3, 4, 5};                                // 1 -> 2 -> 3 -> 4 -> 5
    forward_list<std::string> fl2{"hello", "world", "cpp", "programming"}; // hello -> world -> cpp -> programming
    fl.insert_after(begin(fl), 100);                                       // 1 -> 100 -> 2 -> 3 -> 4 -> 5
    // fl.insert_after(before_begin(fl), 200);
    fl2.erase_after(begin(fl2)); // hello-> cpp -> programming
    for (auto &i : fl)
    {
        cout << i << " ";
    }
    cout << endl;

    for (auto &i : fl2)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}

```