#ifndef PERSON2_H
#define PERSON2_H

#include <string>
typedef struct Person
{
    std::string name;
    std::string address;
    std::string get_name() const
    {
        return name;
    };
    std::string get_address() const
    {
        return address;
    }

} p;

// 读取
std::istream &read(std::istream &is, p &person);

// 打印
std::ostream &print(std::ostream &os, const p &person);

#endif
