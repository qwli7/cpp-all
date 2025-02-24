#include <iostream>
#include <fstream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

std::vector<std::string> readFileToVector(const std::string &filename)
{
    std::vector<std::string> lines;
    std::ifstream file(filename); // 以只读模式打开文件
    if (!file.is_open())
    {
        std::cerr << "open file " << filename << " failed!" << std::endl;
        return lines;
    }
    std::string line;
    while (std::getline(file, line))
    {
        // 逐行读取文件内容
        lines.push_back(line);
    }
    file.close();
    return lines;
}

int main()
{
    std::string filename = "data/test.txt";
    std::vector<std::string> lines = readFileToVector(filename);
    for (auto line : lines)
    {
        cout << line << endl;
    }

    return 0;
}
