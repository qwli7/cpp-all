#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using int_array = int[4];
// typedef int int_array[4]
typedef int int_array2[4];
int main()
{
    int ia[3][4] = {
        {1, 2, 3, 4},
        {2, 4, 6, 8},
        {3, 6, 9, 12},
    };

    // 版本1，使用范围 for
    for (int_array &row : ia)
    {
        for (int col : row)
        {
            cout << col << " ";
        }
        cout << endl;
    }
    cout << endl;

    // 版本3 使用指针
    for (int_array2 *p = ia; p != ia + 3; ++p)
    {
        for (int *q = *p; q != *p + 4; ++q)
        {
            cout << *q << " ";
        }
        cout << endl;
    }

    return 0;
}
