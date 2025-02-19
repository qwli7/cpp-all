#include <iostream>
#include <string>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;
using std::string;
int main()
{
    char ca1[] = "hello";
    char ca2[] = "world";

    char ca3[20];     // 确保长度一定要够长度
    strcpy(ca3, ca1); // 把 ca1 的字符串拷贝到ca3中
    strcat(ca3, ca2); // 把 ca2 的字符串拷贝到 ca3 中;
    cout << ca3 << endl;

    return 0;
}
