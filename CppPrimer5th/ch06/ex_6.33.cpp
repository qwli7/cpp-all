#include <iostream>
#include <vector>
#include <cctype>
#include <exception>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

void print(vector<int>::const_iterator begin, vector<int>::const_iterator end)
{
    if (begin == end)
    {
        return;
    }
    cout << *begin << " ";
    print(++begin, end);
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    print(v.cbegin(), v.cend());
    return 0;
}
