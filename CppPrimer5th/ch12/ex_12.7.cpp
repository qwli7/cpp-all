#include <iostream>
#include <vector>
#include <new>
#include <memory>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

std::shared_ptr<std::vector<int>> CreateVector()
{
    return std::make_shared<std::vector<int>>();
}

void ReadValue(std::shared_ptr<std::vector<int>> prev)
{
    int value;
    while (cin >> value)
    {
        prev->push_back(value);
    }
}

void PrintVector(std::shared_ptr<std::vector<int>> vec)
{
    auto it = vec->cbegin();
    while (it != vec->cend())
    {
        cout << *it << " ";
        ++it;
    }
    cout << endl;
}

int main()
{
    std::shared_ptr<std::vector<int>> pvec = CreateVector();
    if (pvec)
    {
        cout << "Enter values for the vector: " << endl;
        ReadValue(pvec);
        PrintVector(pvec);
    }
    return 0;
}