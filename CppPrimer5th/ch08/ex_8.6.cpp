#include <iostream>
#include <fstream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

// main book.txt
int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " filename" << std::endl;
        return -1;
    }
    std::string filename(argv[1]);
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "open file " << filename << " failed!" << std::endl;
        return -1;
    }
    std::string line;
    while (std::getline(file, line))
    {
        cout << line << endl;
    }
    return 0;
}
