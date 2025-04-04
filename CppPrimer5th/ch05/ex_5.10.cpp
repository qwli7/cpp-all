#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
int main()
{
    int a_cnt = 0;
    int o_cnt = 0;
    int e_cnt = 0;
    int i_cnt = 0;
    int u_cnt = 0;
    string str;
    // cin >> str; // 读取一个字符串，用空格分隔
    getline(cin, str); // 读取一行
    for (auto c : str)
    {
        switch (c)
        {
        case 'a':
        case 'A':
            a_cnt++;
            break;
        case 'o':
        case 'O':
            o_cnt++;
            break;
        case 'u':
        case 'U':
            u_cnt++;
            break;
        case 'e':
        case 'E':
            e_cnt++;
            break;
        case 'i':
        case 'I':
            i_cnt++;
            break;
        default:
            break;
        }
    }
    cout << "a_cnt: " << a_cnt << endl;
    cout << "o_cnt: " << o_cnt << endl;
    cout << "u_cnt: " << u_cnt << endl;
    cout << "e_cnt: " << e_cnt << endl;
    cout << "i_cnt: " << i_cnt << endl;

    return 0;
}
