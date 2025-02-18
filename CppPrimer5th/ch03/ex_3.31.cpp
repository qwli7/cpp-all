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

    for (decltype(get_size()) i = get_size() - 1; i >= 0; --i)
    {
        ia[i] = i;
        cout << ia[i] << " ";
    }
    cout << endl;
    return 0;
}