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

int main()
{
    std::vector<std::string> svec = {"12", "23", "34"};
    std::vector<string> svec2 = {"12.1", "23.2", "34.9"};
    int sum = 0;
    for (auto &s : svec)
    {
        sum += std::stoi(s);
    }
    cout << "sum = " << sum << endl;

    float sum2 = 0.0f;
    for (auto &s : svec2)
    {
        sum2 += std::stof(s);
    }
    cout << "sum2 = " << sum2 << endl;
    return 0;
}
