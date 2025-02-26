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

class Sales_data
{
private:
    std::string bookNo;

public:
    Sales_data() = default;
    Sales_data(const std::string &b) : bookNo(b) {}
    const std::string &isbn() const { return bookNo; }
};

bool compare_str(const string &s1)
{
    return s1.size() >= 5;
}

int compareIsbn(const Sales_data &sd1, const Sales_data &sd2)
{
    return sd1.isbn() < sd2.isbn();
}

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

    std::vector<Sales_data> data;
    data.emplace_back("java");
    data.emplace_back("cpp");
    data.emplace_back("python");
    data.emplace_back("js");
    data.emplace_back("flutter");
    data.emplace_back("web");
    for (auto &it : data)
    {
        cout << it.isbn() << " ";
    }
    cout << endl;

    std::sort(data.begin(), data.end(), compareIsbn);
    for (auto &it : data)
    {
        cout << it.isbn() << " ";
    }
    cout << endl;

    std::vector<std::string> strs = {"hello", "world", "apple", "banana", "orange", "pear"};
    // output orange banana apple world hello pear
    // 返回的指针指向 apple，可以通过判断指针是否等于 end 指针来判断是否有满足条件的字符串
    std::partition(strs.begin(), strs.end(), compare_str);
    for (auto &it : strs)
    {
        cout << it << " ";
    }
    cout << endl;

    std::vector<string>::iterator it = std::partition(words.begin(), words.end(), compare_str);
    // 打印从 begin 到 it 之间的元素
    for (int i = 0; i < it - words.begin(); i++)
    {
        cout << words[i] << " ";
    }
    cout << endl;
    return 0;
}
