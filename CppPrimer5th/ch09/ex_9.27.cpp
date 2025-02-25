#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <list>
#include <forward_list>
using std::cin;
using std::cout;
using std::endl;
using std::forward_list;
using std::string;
using std::vector;

struct PersonInfo
{
    std::string name;
    std::vector<std::string> phones;
};

int main()
{
    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
    std::forward_list<int> flist;
    std::list<int> lst;
    for (size_t t = 0; t < sizeof(ia) / sizeof(ia[0]); t++)
    {
        flist.push_front(ia[t]);
    }

    std::forward_list<int>::iterator it = flist.begin();
    std::forward_list<int>::iterator before_begin = flist.before_begin();

    // 删除奇数
    while (it != flist.end())
    {
        if (*it % 2 != 0)
        {
            it = flist.erase_after(before_begin); // 删除它，并移动指向当前元素的 it
        }
        else
        {
            before_begin = it; // 如果不是奇数，则before 和当前的指针都要向后移动
            ++it;
        }
    }
    for (auto i : flist)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
