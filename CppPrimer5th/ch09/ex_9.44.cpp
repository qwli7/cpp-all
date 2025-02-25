
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <list>
#include <forward_list>
using std::cin;
using std::cout;
using std::endl;
using std::forward_list;
using std::string;
using std::vector;

struct PersonInfo
{
    std::string name;
    std::vector<std::string> phones;
};

/**
 * 编写一个函数，接受三个 string 参数 s、oldVal 和 newVal。使用迭代器及 insert 和 erase 函数将 s 中所有 oldVal 替换威 newVal。测试你的程序，用他替换通用的简写形式。
 * 如，将 `tho` 替换为 `though`, 将 `thru` 替换称 `through`;
 */
void func(std::string &str1, const std::string &oldVal, const std::string &newVal)
{
    std::string::iterator it = str1.begin();
    while (it != str1.end())
    {
        if (std::string(it, it + oldVal.size()) == oldVal)
        {
            // 删除旧字符串
            it = str1.erase(it, it + oldVal.size());
            // 插入新字符串
            it = str1.insert(it, newVal.begin(), newVal.end());
            it += newVal.size(); // 移动到插入的内容之后
        }
        else
        {
            ++it;
        }
    }
}

/**
 * 下标和 replace 版本
 */
void func2(std::string &str1, const std::string &oldVal, const std::string &newVal)
{
    for (decltype(str1.size()) i = 0; i < str1.size(); ++i)
    {
        if (str1.substr(i, oldVal.size()) == oldVal)  //截取一个子串
        {
            str1.replace(i, oldVal.size(), newVal); //替换成新值
            i += newVal.size() - 1; //移动i
        }
    }
}

int main()
{
    std::string s1 = "tho thru tho";
    func2(s1, "tho", "though");
    cout << s1 << endl; // though thru though
    func2(s1, "thru", "through");
    cout << s1 << endl; // though through though
    return 0;
}
