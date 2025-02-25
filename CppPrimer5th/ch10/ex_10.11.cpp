#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <list>
#include <forward_list>
#include <algorithm>
#include <numeric>
using std::cin;
using std::cout;
using std::endl;
using std::forward_list;
using std::string;
using std::vector;

int is_shooter(const string &str1, const string &str2)
{
    return str1.size() < str2.size();
}

void elimDups(std::vector<string> &words)
{
    cout << "before: " << endl;
    for (auto it : words)
    {
        cout << it << " ";
    }
    cout << endl
         << endl;
    // 先排序
    std::sort(words.begin(), words.end());
    cout << "sorted: " << endl;
    for (auto it : words)
    {
        cout << it << " ";
    }
    cout << endl
         << endl;
    // 创建unique, unique_end 指向最后一个不重复元素的下一个位置
    std::vector<string>::iterator unique_end = std::unique(words.begin(), words.end());
    cout << "unique after:" << endl;
    for (auto it : words)
    {
        cout << it << " ";
    }
    cout << endl
         << endl;
    // 擦除重复的数据
    words.erase(unique_end, words.end());
    cout << "erase after:" << endl;
    for (auto it : words)
    {
        cout << it << " ";
    }
    cout << endl;
}

int main()
{
    std::vector<string> words = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    elimDups(words);
    cout << endl;
    cout << "stable sort:"
         << endl;
    std::stable_sort(words.begin(), words.end(), is_shooter);
    for (auto &it : words)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}
