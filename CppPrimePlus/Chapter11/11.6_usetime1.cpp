#include <iostream>
#include "11.4_mytime1.h"

int main() {
    using std::cout;
    using std::endl;

    Time planning;
    Time coding(2, 40);
    Time fixing(5, 55);

    Time total;

    cout << "planning time = ";
    planning.Show();
    cout << endl;

    cout <<"coding time = ";
    coding.Show();
    cout << endl;

    cout <<"fixing time = ";
    fixing.Show();
    cout << endl;

    //计算总时间
    // total = coding.Sum(fixing);
    total = coding + fixing; //已经对操作符+进行了重载，可以直接使用 + 来对两个时间进行相加
    cout << "coding.sum(fixing) = ";
    total.Show();
    cout << endl;
    return 0;
}