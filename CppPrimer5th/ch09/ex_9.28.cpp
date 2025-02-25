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
 * 在链表中查找第一个 string，并将第二个 string 插入到紧接着第一个 string 之后的位置
 * 若第一个 string 未在链表中，则将第二个 string 插入到链表末尾
 */
void func(std::forward_list<std::string> &f_list, std::string str1, std::string str2)
{
    bool exists = false;

    std::forward_list<std::string>::iterator it = f_list.begin();
    std::forward_list<std::string>::iterator end = f_list.before_begin();
    while (it != f_list.end())
    {
        if (*it == str1)
        {
            cout << "founded, insert after it" << endl;
            exists = true;
            f_list.insert_after(it, str2);
            break;
        }
        else
        {
            end = it;
            ++it;
        }
    }

    if (!exists)
    {
        cout << "not found, insert at end" << endl;
        f_list.insert_after(end, str2);
        // f_list.insert_after(f_list.end(), str1); // 不能这样插入，需要记住上一个迭代器指向的位置
    }
}

int main()
{
    std::forward_list<string> flist = {"hello", "world", "begin", "cpp"};
    func(flist, "hello1", "java");

    for (auto it : flist)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}
