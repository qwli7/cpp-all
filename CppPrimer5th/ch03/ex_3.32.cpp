#include <iostream>

using std::cout;
using std::endl;

constexpr int get_size()
{
    return 10;
}

int main()
{
    int ia[get_size()];
    for (decltype(get_size()) i = 0; i < get_size(); ++i)
    {
        ia[i] = i;
        cout << ia[i] << " ";
    }
    cout << endl;

    int ia2[get_size()];
    int j = 0;
    for (auto i : ia)
    {
        ia2[j++] = i;
    }

    for (decltype(get_size()) i = 0; i < get_size(); ++i)
    {
        cout << ia2[i] << " ";
    }
    cout << endl;
    return 0;
}