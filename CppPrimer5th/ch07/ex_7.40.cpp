#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class Sales_data
{
public:
    Sales_data(const string &bookNo, unsigned units_sold, double revenue) : m_bookNo(bookNo), m_units_sold(units_sold), m_revenue(revenue)
    {
        cout << "Sales_data(const string& bookNo, unsigned units_sold, double revenue)" << endl;
    }
    // 委托构造函数
    Sales_data() : Sales_data("", 0, 0.0)
    {
        cout << "Sales_data()" << endl;
    }
    Sales_data(const string &bookNo) : Sales_data(bookNo, 0, 0.0)
    {
        cout << "Sales_data(const string& bookNo)" << endl;
    }
    Sales_data(unsigned units_sold) : Sales_data("", units_sold, 0.0)
    {
        cout << "Sales_data(unsigned units_sold)" << endl;
    }
    Sales_data(double revenue) : Sales_data("", 0, revenue)
    {
        cout << "Sales_data(double revenue)" << endl;
    }

private:
    std::string m_bookNo;
    unsigned m_units_sold = 0;
    double m_revenue = 0.0;
};

int main()
{
    Sales_data s1;
    cout << "-------------" << endl;
    Sales_data s2("book1");
    cout << "-------------" << endl;
    Sales_data s3((unsigned)100);
    cout << "-------------" << endl;
    Sales_data s4(100.0);
    cout << "-------------" << endl;
    Sales_data s5("book2", 100, 1000.0);

    return 0;
}
