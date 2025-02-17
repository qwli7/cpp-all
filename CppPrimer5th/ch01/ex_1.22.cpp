#include <iostream>
#include "Sales_item.h"

int main()
{
    int cnt;
    Sales_item total;
    if (std::cin >> cnt)
    {
        std::cout << "Enter " << cnt << " items of sales data:" << std::endl;
        while (cnt > 0)
        {
            Sales_item item;
            std::cin >> item;
            total += item;
            cnt--;
        }
        std::cout << "Total items of: " << total << std::endl;
    }
}