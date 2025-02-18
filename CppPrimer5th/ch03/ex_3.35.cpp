#include <iostream>

using std::cout;
using std::endl;
int main()
{
    int ia[] = {1, 2, 3, 4, 5};
    int *p = ia; // 等同与 int *p = &ia[0];
    for (size_t i = 0; i < 5; ++i)
    {
        *p++ = 0;
    }
    for (auto i : ia)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}