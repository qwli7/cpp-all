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
    string output;
    cin >> str;
    for (auto c : str)
    {
        if (!ispunct(c))
        { // 判断字符是否是标点符号
            output += c;
        }
    }
    cout << str << endl;

    cout << output << endl;
    return 0;
}
