#include <iostream>

void simple(); //函数原型

int main() {

    using namespace std;
    cout << "main() will call the simple() func: " << endl;
    simple(); //函数调用
    cout << "main() is finished with the simple() func. " << endl;
    return 0;
}


void simple() { //函数定义
    using namespace std;
    cout << "hello world" << endl;
}