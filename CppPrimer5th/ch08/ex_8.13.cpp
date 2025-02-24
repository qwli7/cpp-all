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

    std::ifstream infile("data/person.txt");
    if(!file.is_open()) {
        cout << "Read file failed." << endl;
        return -1;
    }

    while (std::getline(infile, line))
    {
        PersonInfo info;
        record.str(line);
        record >> info.name; //读取每一行的第一个单词，作为姓名
        while (record >> word)
        {
            info.phones.push_back(word);
        }
        persons.push_back(info);
        record.clear();
    }
    infile.close(); //关闭流

    for (auto person : persons)
    {
        for (auto phone : person.phones)
        {
            cout << person.name << " " << phone << endl;
        }
    }

    return 0;
}
