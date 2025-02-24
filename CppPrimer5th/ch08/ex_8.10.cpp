#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    std::ifstream file("book.txt");
    if (!file.is_open())
    {
        std::cout << "open file failed" << std::endl;
        return -1;
    }
    std::vector<string> lines;
    std::string line;
    while (std::getline(file, line))
    {
        std::cout << line << std::endl;
        lines.push_back(line);
    }
    file.close();

    std::cout << "read file done" << std::endl;
    // 从vector中读取数据，每次展示一个单词
    for (auto item : lines)
    {
        std::istringstream iss(item);
        std::string word;
        while (iss >> word)
        {
            std::cout << word << endl;
        }
    }

    return 0;
}
