#include <iostream>
#include <vector>
#include <new>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

std::vector<int> *CreateVector()
{
    return new std::vector<int>();
}

void ReadValue(std::vector<int> *prev)
{
    int value;
    while (cin >> value)
    {
        prev->push_back(value);
    }
}

void PrintVector(std::vector<int> *vec)
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
    std::vector<int> *pvec = CreateVector();
    if (pvec)
    {
        cout << "Enter values for the vector: " << endl;
        ReadValue(pvec);
        PrintVector(pvec);
    }
    delete pvec;
    pvec = nullptr;
    return 0;
}