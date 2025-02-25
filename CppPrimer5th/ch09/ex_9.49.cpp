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

bool hasNoExtendingHeads(const std::string &word)
{
    std::string upperExtendingHeads = "df";
    std::string lowerExtendingHeads = "pg";
    for (char ch : word)
    {
        if (upperExtendingHeads.find(ch) != std::string::npos || lowerExtendingHeads.find(ch) != std::string::npos)
            return false;
    }
    return true;
}

int main()
{
    std::ifstream ifs("data/test.txt");
    if (!ifs.is_open())
    {
        std::cerr << "Failed to open file" << std::endl;
        return -1;
    }
    std::string longestWord;
    std::string word;
    while (ifs >> word)
    {
        if (hasNoExtendingHeads(word))
        {
            if (word.length() > longestWord.length())
            {
                longestWord = word;
            }
        }
    }
    ifs.close();
    if (longestWord.empty())
    {
        cout << "Not found" << endl;
    }
    else
    {
        cout << "founded " << longestWord << endl;
    }
    return 0;
}
