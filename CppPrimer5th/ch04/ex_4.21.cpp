#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    vector<int>::iterator it = v.begin();
    while (it != v.end())
    {
        if (*it % 2 != 0)
        {
            *it = *it * 2;
        }
        it++;
    }
    for (auto i : v)
    {
        cout << i << " ";
    }
    return 0;
}
