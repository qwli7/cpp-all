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

// 这里不要用 int 如果超出范围了，可能会溢出
long long fact(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    return fact(n - 1) * n;
}

int main()
{
    int x;
    while (cin >> x)
    {
        try
        {
            if (x < 0)
            {
                throw std::invalid_argument("Input must be non-negative");
            }
            cout << fact(x) << endl;
        }
        catch (std::invalid_argument &e)
        {
            cout << e.what() << endl;
        }
    }

    return 0;
}
