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
    string str2;
    cout << "Enter a string: ";
    cin >> str;
    cout << "Enter another string: ";
    cin >> str2;
    if (str == str2)
    {
        cout << "equal" << endl;
    }
    else
    {
        cout << "not equal" << endl;
        if (str.size() < str2.size())
        {
            cout << str2 << endl;
        }
        else
        {
            cout << str << endl;
        }
    }

    return 0;
}
