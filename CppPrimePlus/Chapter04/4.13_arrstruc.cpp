#include <iostream>

//结构体赋值和取值


// 结构定义
struct inflatable {
    char name[20];
    float volume;
    double price;
};

int main() {
    using namespace std;

    //结构体初始化
    inflatable guest[2] = {
        {"zhangsan", 12.34, 22.99},
        {"lisi", 21.89, 99.20}
    };

    //访问第一个 inflatable 属性
    cout << "索引为 0 的 name 属性 " << guest[0].name << endl;
    cout << "索引为 0 的 volume 属性" << guest[0].volume << endl;
    cout << "索引为 0 的 price 属性" << guest[0].price << endl;

    //访问第二个 inflatable 属性
    cout << "索引为 1 的 name 属性 " << guest[1].name << endl;
    cout << "索引为 1 的 volume 属性" << guest[1].volume << endl;
    cout << "索引为 1 的 price 属性" << guest[1].price << endl;

    return 0;
}