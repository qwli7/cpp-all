#include <iostream>
#include <string>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;
using std::string;
int main()
{
    string str1 = "hello";
    string str2 = "hello";
    cout << (str1 > str2) << endl;

    char ca[] = {'h', 'e', 'l', 'l', 'o', '\0'};
    char ca2[] = {'w', 'o', 'r', 'l', 'd', '\0'};
    cout << (strcmp(ca, ca2) > 0) << endl;

    return 0;
}
