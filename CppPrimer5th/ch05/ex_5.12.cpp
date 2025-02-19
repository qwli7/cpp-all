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
    int space_cnt = 0;
    int tab_cnt = 0;
    int line_cnt = 0;
    int ff_cnt = 0;
    int fl_cnt = 0;
    int fi_cnt = 0;
    bool is_start_f = false;
    string str;
    // cin >> str; // 读取一个字符串，用空格分隔
    getline(cin, str); // 读取一行
    for (const char &c : str)
    {
        switch (c)
        {
        case 'a':
        case 'A':
            a_cnt++;
            is_start_f = false;
            break;
        case 'o':
        case 'O':
            o_cnt++;
            is_start_f = false;
            break;
        case 'u':
        case 'U':
            u_cnt++;
            is_start_f = false;
            break;
        case 'e':
        case 'E':
            e_cnt++;
            is_start_f = false;
            break;
        case 'i':
        case 'I':
            i_cnt++;
            break;
        case '\n':
            line_cnt++;
            is_start_f = false;
            break;
        case '\t':
            tab_cnt++;
            is_start_f = false;
            break;
        case ' ':
            space_cnt++;
            is_start_f = false;
            break;
        case 'f':
            if (!is_start_f)
            {
                is_start_f = true;
            }
            else
            {
                ff_cnt++;
                is_start_f = false;
            }
            break;
        case 'l':
            if (is_start_f)
            {
                fl_cnt++;
                is_start_f = false;
            }
            else
            {
                is_start_f = false;
            }
            break;
        default:
            is_start_f = false;
            break;
        }
    }
    cout << "a_cnt: " << a_cnt << endl;
    cout << "o_cnt: " << o_cnt << endl;
    cout << "u_cnt: " << u_cnt << endl;
    cout << "e_cnt: " << e_cnt << endl;
    cout << "i_cnt: " << i_cnt << endl;
    cout << "space_cnt: " << space_cnt << endl;
    cout << "tab_cnt: " << tab_cnt << endl;
    cout << "line_cnt: " << line_cnt << endl;
    cout << "ff_cnt: " << ff_cnt << endl;
    cout << "fl_cnt: " << fl_cnt << endl;
    cout << "fi_cnt: " << fi_cnt << endl;
    return 0;
}
