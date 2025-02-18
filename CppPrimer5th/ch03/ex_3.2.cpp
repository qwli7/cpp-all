#include <iostream>
#include <string>

// 使用 using 来声明，避免每次都需要写域作用符 std::cout std::cin std::endl

using std::cin;
using std::cout;
using std::endl;
using std::string;
int main()
{
    string str;
    // while (getline(cin, str)) //一次读取一整行
    // {
    //     cout << str << endl;
    // }
    while (cin >> str)
    {
        cout << str << endl;
    }
    return 0;
}
