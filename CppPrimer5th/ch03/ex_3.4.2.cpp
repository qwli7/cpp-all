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
    cout << "Enter two string: ";
    cin >> str >> str2;
    if (str.size() == str2.size())
    {
        cout << "length same" << endl;
    }
    else
    {
        cout << "max length str is " << (str.size() > str2.size() ? str : str2) << endl;
    }

    return 0;
}
