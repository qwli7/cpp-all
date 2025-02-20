#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

void print(vector<int>::const_iterator begin, vector<int>::const_iterator end)
{
    if (begin == end)
    {
        return;
    }
#ifdef NDEBUG // 如果定义了NDEBUG，则不输出元素的值
    cout << sizeof(*begin) << endl;
#endif

    cout << *begin << " ";
    print(++begin, end);
}

// g++ ex_6.47.cpp -D NDEBUG -o main -std=c++11 -Wall && main
int main()
{

    vector<int> vec{1, 2, 3, 4, 5};
    print(vec.cbegin(), vec.cend());

    return 0;
}