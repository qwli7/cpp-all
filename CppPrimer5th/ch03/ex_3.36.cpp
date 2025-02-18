#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main()
{
    int ia[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int ia2[10] = {0, 1, 2, 3, 4, 5, 6, 7, 9, 8};

    bool flag = true;
    for (int i = 0; i < 10; ++i)
    {
        if (ia[i] != ia2[i])
        {
            flag = false;
            break;
        }
    }
    if (flag)
    {
        cout << "The arrays are equal." << endl;
    }
    else
    {
        cout << "The arrays are not equal." << endl;
    }

    // 比较两个vector是否相等
    vector<int> v1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> v2 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    cout << "v1 == v2: " << std::boolalpha << (v1 == v2) << endl;

    return 0;
}