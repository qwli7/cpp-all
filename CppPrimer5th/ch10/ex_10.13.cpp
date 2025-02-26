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


bool compare_str(const string &s1)
{
    return s1.size() > 5;
}


int main()
{
    std::vector<std::string> strs = {"hello", "world", "apple", "banana", "orange", "pear"};
    std::partition(strs.begin(), strs.end(), compare_str);
    for (auto &it : strs)
    {
        cout << it << " ";  
    }
    cout << endl;

    //output orange banana apple world hello pear 
    //返回的指针指向 apple，可以通过判断指针是否等于 end 指针来判断是否有满足条件的字符串
    return 0;
}
