#include <iostream>
#include <string>
#include <cassert>

using std::cin;
using std::cout;
using std::endl;
using std::string;

const string sought = "the";

void manip(int, int);
double dobj;

int main()
{
    // a
    manip('a', 'z'); // a z 转换成 int

    // b
    manip(55.4, dobj); // 55.4 dobj 转换成 int

    return 0;
}