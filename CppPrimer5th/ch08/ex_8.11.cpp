#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

struct PersonInfo
{
    std::string name;
    std::vector<std::string> phones;
};
int main()
{
    string line, word;
    vector<PersonInfo> persons;
    std::istringstream record;
    while (getline(cin, line))
    {
        PersonInfo info;
        record.str(line); //重新绑定
        record >> info.name;
        while (record >> word)
        {
            info.phones.push_back(word);
        }
        persons.push_back(info);
        record.clear(); //清除
    }

    for (auto person : persons)
    {
        for (auto phone : person.phones)
        {
            cout << person.name << " " << phone << endl;
        }
    }

    return 0;
}
