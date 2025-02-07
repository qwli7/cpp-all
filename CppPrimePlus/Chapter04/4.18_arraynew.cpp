#include <iostream>

int main() {
    using namespace std;

    double *ps = new double[3]; //申请了3个double元素的内存空间，返回数组首元素的地址

    ps[0] = 0.2;
    ps[1] = 0.5;
    ps[2] = 0.8;

    cout <<"ps[1] is " << ps[1] << endl; //ps[1] is 0.5
    ps = ps + 1; //指针向后移动一个
    cout << "ps[0] is " << ps[0]  << " and ps[1] is " << ps[1] << endl; //ps[0] is 0.5 and ps[1] is 0.8

    ps = ps -1 ;

    delete[] ps;


    return 0;


}