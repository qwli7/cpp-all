#ifndef PERSON_H
#define PERSON_H

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

#endif
