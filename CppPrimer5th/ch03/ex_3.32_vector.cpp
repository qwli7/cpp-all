#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<int> v1(10); // 定义一个长度为10的int vector
    for (int i = 0; i < v1.size(); ++i)
    {
        v1[i] = i;
    }
    cout << "v1: ";
    for (auto i : v1)
    {
        cout << i << " ";
    }
    cout << endl;

    // 拷贝v1到v2
    vector<int> v2(v1); // 定义一个长度为10的int vector
    cout << "v2: ";
    for (auto i : v2)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
