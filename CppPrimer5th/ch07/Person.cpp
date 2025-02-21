#include "Person2.h"
#include <iostream>

std::istream &read(std::istream &is, p &person)
{
    is >> person.name >> person.address;
    return is;
}

std::ostream &print(std::ostream &os, const p &person)
{
    os << person.name << " " << person.address;
    return os;
}
