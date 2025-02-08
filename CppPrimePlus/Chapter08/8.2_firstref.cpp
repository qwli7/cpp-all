#include <iostream>

//验证引用和变量有相同的地址和相同的内存单元

//output
/**
 *  rat = 10, rodents = 10
    rat = 11, rodents = 11
    rat = 12, rodents = 12
    rat address = 0x7ffc0d30ee6c,  rodents address = 0x7ffc0d30ee6c
 * 
 */

int main() {

    using namespace std;

    int rats = 10;
    int & rodents = rats; //创建 rats 的引用

    cout  << "rat = " << rats  << ", rodents = " << rodents << endl;

    rodents++;

    cout << "rat = " << rats << ", rodents = " << rodents << endl;

    rats++;
    cout << "rat = " << rats << ", rodents = " << rodents << endl;

    //输出打印地址
    cout << "rat address = " << &rats << ",  rodents address = "<< &rodents << endl;

    return 0;
}