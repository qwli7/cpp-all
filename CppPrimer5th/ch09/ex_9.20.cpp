#include <iostream>
#include <string>
#include <list>
#include <deque>

using std::cin;
using std::cout;
using std::deque;
using std::endl;
using std::list;
using std::string;

int main()
{
    std::list<int> slist;
    for (decltype(slist.size()) i = 0; i < 20; ++i)
    {
        slist.push_back(i);
    }

    std::deque<int> odds;
    std::deque<int> evens;
    for (auto i : slist)
    {
        if (i % 2 == 0)
        {
            evens.push_back(i);
        }
        else
        {
            odds.push_back(i);
        }
    }

    for (auto i : odds)
    {
        cout << i << " ";
    }
    cout << endl;
    for (auto i : evens)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}