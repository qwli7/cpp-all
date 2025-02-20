#include <iostream>
#include <vector>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;
using std::string;

bool isContainUpperChar(const string &str)
{
    for (auto &c : str)
    {
        if (isupper(c))
        {
            return true;
        }
    }
    return false;
}

void toLowerCase(string &str)
{
    for (auto &c : str)
    {
        c = tolower(c);
    }
}

int main()
{
    string str1 = "Hello";
    string str2("World");
    cout << std::boolalpha << isContainUpperChar(str1) << endl;
    toLowerCase(str2);
    cout << str2 << endl;
    return 0;
}
