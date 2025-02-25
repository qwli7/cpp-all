#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <list>
using std::cin;
using std::cout;
using std::endl;
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
    std::vector<int> ivec;
    std::list<int> lst;
    for (size_t t = 0; t < sizeof(ia) / sizeof(ia[0]); t++)
    {
        ivec.push_back(ia[t]);
        lst.push_back(ia[t]);
    }
    for (auto i : ia)
    {
        cout << i << " ";
    }
    cout << endl;
    // 删除偶数
    std::vector<int>::iterator it = ivec.begin();
    while (it != ivec.end())
    {
        if (*it % 2 == 0)
        {
            it = ivec.erase(it);
        }
        else
        {
            ++it;
        }
    }
    for (auto i : ivec)
    {
        cout << i << " ";
    }
    cout << endl;

    // 删除奇数
    std::list<int>::iterator lit = lst.begin();
    while (lit != lst.end())
    {
        if (*lit % 2 != 0)
        {
            lit = lst.erase(lit);
        }
        else
        {
            ++lit;
        }
    }
    for (auto i : lst)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
