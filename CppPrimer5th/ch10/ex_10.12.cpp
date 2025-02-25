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
    Sales_data() = default; //让编译器为我们生成默认的构造函数
    Sales_data(const std::string &b) : bookNo(b) {}
    const std::string &isbn() const { return bookNo; }
};

int compareIsbn(const Sales_data &sd1, const Sales_data &sd2)
{
    return sd1.isbn() < sd2.isbn();
}

int main()
{
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
    return 0;
}
