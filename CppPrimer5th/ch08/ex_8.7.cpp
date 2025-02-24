#include <iostream>
#include <fstream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;


int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        std::cerr << "Usage: " << argv[0] << " filename outputfilename" << std::endl;
        return -1;
    }
    std::string filename(argv[1]);
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "open file " << filename << " failed!" << std::endl;
        return -1;
    }
    std::string outputfilename(argv[2]);
    std::ofstream outputfile(outputfilename, std::ios::out); //out 写入文件
    if (!outputfile.is_open())
    {
        std::cerr << "open file " << outputfilename << " failed!" << std::endl;
        file.close();
        return -1;
    }
    std::string line;
    while (std::getline(file, line))
    {
        outputfile << line << endl;
        cout << line << endl;
    }
    file.close();
    outputfile.close();
    return 0;
}
