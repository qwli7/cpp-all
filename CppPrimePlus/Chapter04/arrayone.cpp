#include <iostream>

int main() {
    using namespace std;

    int yams[3]; //定义了一个类型为 int，长度为 3 的数组

    //指定位置赋值
    yams[0] = 1;
    yams[2] = 3;

    short yamcosts[4] = {10, 12, 13, 14}; //初始化列表赋值

    //计算数组的长度
    std::cout << "yamcosts 长度为 " << sizeof(yamcosts)/sizeof(short) << std::endl;

    for(int i = 0; i < 3; i++) {
        std::cout << "yams["<< i << "]=" << yams[i] << std::endl;
    }

    return 0;
}