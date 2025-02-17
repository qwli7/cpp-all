#include <iostream>
#include "Sales_item.h"

int main()
{

    Sales_item currentItem, nextItem;
    if (std::cin >> currentItem)
    {
        while (std::cin >> nextItem)
        {
            if (currentItem.isbn() == nextItem.isbn())
            {
                currentItem += nextItem;
            }
            else
            {
                currentItem = nextItem;
                std::cout << "ISBN: " << currentItem << std::endl;
                continue;
            }
            std::cout << "ISBN: " << currentItem << std::endl;
        }
    }

    return 0;
}