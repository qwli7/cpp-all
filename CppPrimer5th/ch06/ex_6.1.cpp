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

int fact(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    return fact(n - 1) * n;
}

int main()
{
    cout << fact(5) << endl;

    return 0;
}
