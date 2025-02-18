#include <iostream>
#include "Sales_data.h"

int main()
{

    Sales_data data1, data2;
    double price = 0;
    std::cin >> data1.bookNo >> data1.units_sold >> price;
    // 计算销售收入
    data1.revenue = data1.units_sold * price;

    std::cin >> data2.bookNo >> data2.units_sold >> price;
    // 计算销售收入
    data2.revenue = data2.units_sold * price;

    if (data1.bookNo == data2.bookNo)
    {
        unsigned totalCnt = data1.units_sold + data2.units_sold;
        double totalRevenue = data1.revenue + data2.revenue;

        // 输出结果
        std::cout << data1.bookNo << " " << totalCnt << " " << totalRevenue << std::endl;
        if (totalCnt != 0)
        {
            std::cout << totalRevenue / totalCnt << std::endl;
        }
        else
        {
            std::cout << "Invalid data" << std::endl;
        }
        return 0;
    }
    else
    {
        std::cerr << "ISBN must same" << std::endl;
        return -1;
    }
}
