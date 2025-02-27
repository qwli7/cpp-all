#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <list>
#include <forward_list>
#include <algorithm>
#include <functional>
#include <set>
#include <numeric>
#include <map>
#include <typeinfo>
#include <memory>
using std::cin;
using std::cout;
using std::endl;
using std::forward_list;
using std::string;
using std::vector;

class StrBlob
{
public:
    typedef std::vector<std::string>::size_type size_type;
    StrBlob();
    StrBlob(std::initializer_list<std::string> il);
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    // 添加和删除元素
    void push_back(const std::string &t) { data->push_back(t); }
    void pop_back();

    // 元素访问
    std::string &front();
    std::string &back();

private:
    std::shared_ptr<std::vector<std::string>> data; // 智能指针，指向一个 vector<string>
    // 检查下标是否有效，如果无效，将抛出一个异常
    void check(size_type i, const string &msg) const;
};

StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()) {}
StrBlob::StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<std::vector<std::string>>(il)) {}

void StrBlob::check(size_type i, const string &msg) const
{
    if (i >= data->size())
    {
        throw std::out_of_range(msg);
    }
}

std::string &StrBlob::front()
{
    // 检查是否为空
    check(0, "front on empty StrBlob");
    return data->front();
}

std::string &StrBlob::back()
{
    check(0, "back on empty StrBlob");
    return data->back();
}
void StrBlob::pop_back()
{
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}
