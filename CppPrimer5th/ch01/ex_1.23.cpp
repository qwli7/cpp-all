#include <iostream>
#include "Sales_item.h"
#include <vector>
int main()
{
    Sales_item currentItem, nextItem;
    if (std::cin >> currentItem)
    {
        int cnt = 1;
        while (std::cin >> nextItem)
        {
            if (currentItem.isbn() == nextItem.isbn())
            {
                cnt++;
            }
            else
            {
                currentItem = nextItem;
                cnt = 1;
                std::cout << "ISBN: " << currentItem.isbn() << " occurs " << cnt << " times " << std::endl;
                continue;
            }
            std::cout << "ISBN: " << currentItem.isbn() << " occurs " << cnt << " times " << std::endl;
        }
    }

    return 0;
}