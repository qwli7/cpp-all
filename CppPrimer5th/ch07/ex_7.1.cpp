#include <iostream>
#include <vector>
#include "Sales_data.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{

    Sales_data total;
    if (read(cin, total))
    {
        Sales_data trans;
        while (read(cin, trans))
        {
            if (total.isbn() == trans.isbn())
            {
                total = add(total, trans);
            }
            else
            {
                print(cout, total);
                total = trans;
            }
        }

        print(cout, total);
    }
    else
    {
        cout << "No data?!" << endl;
        return -1;
    }

    return 0;
}
