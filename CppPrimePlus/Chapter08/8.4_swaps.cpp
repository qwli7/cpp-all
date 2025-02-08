#include <iostream>

void swapr(int & a, int & b); //引用
void swapp(int * p, int * q); //指针
void swap(int a, int b); //值拷贝

int main() {
    using namespace std;

    int wallet1 = 300;
    int wallet2 = 500;
    cout << "wallet1 = " << wallet1 << ", wallet2 = " << wallet2 << endl;

    cout << "Using references to swap contents: \n";
    swapr(wallet1, wallet2); // 引用交换
    cout << "wallet1 = " << wallet1 << ", wallet2 = " << wallet2 << endl;

    cout << "Using pointer to swap contents: \n";
    swapp(&wallet1, &wallet2); // 指针交换
    cout << "wallet1 = " << wallet1 << ", wallet2 = " << wallet2 << endl;

    cout << "Trying to use passing by value: \n";
    swap(wallet1, wallet2); // 值拷贝交换，会交换失败
    cout << "wallet1 = " << wallet1 << ", wallet2 = " << wallet2 << endl;

    return 0;
}

void swapr(int & a, int & b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void swapp(int* a, int * b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void swap(int a, int b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}