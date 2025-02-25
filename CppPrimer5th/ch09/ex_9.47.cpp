#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <list>
#include <forward_list>
using std::cin;
using std::cout;
using std::endl;
using std::forward_list;
using std::string;
using std::vector;

struct PersonInfo
{
    std::string name;
    std::vector<std::string> phones;
};

int func(std::string &s, const char &ch)
{
    std::string::size_type pos = s.find_first_of(ch);
    if (std::string::npos != pos)
    {
        cout << "find " << ch << endl;
        return pos;
    }
    return -1;
}

int func2(std::string &s, const char &ch)
{
    std::string::size_type pos = s.find_last_not_of(ch);
    if (std::string::npos != pos)
    {
        cout << "find last not " << ch << endl;
        return pos;
    }
    return -1;
}

int main()
{
    std::string s1 = "ab2c3d7R4E";
    int pos = func(s1, 'R');
    cout << pos << endl;

    int pos2 = func(s1, '3');
    cout << pos2 << endl;
    return 0;
}
