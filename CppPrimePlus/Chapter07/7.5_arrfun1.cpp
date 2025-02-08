#include <iostream>

#define size 8 //等同于 const int size = 8

int sum_arr(int arr[], int n); //函数原型
int sum_arr2(int* arr, int n); //函数原型
int main() {
    using namespace std;

    int cookies[size] {1,2,4,8,6,32,64,128};
    
    int sum = sum_arr(cookies, size);
    int sum2 = sum_arr2(cookies, size);

    //两者输出相同，间接说明两者的原型是等效的
    cout <<"Total cookies eaten: " << sum << "\n";
    cout << "Total cookies eaten2: " << sum2 << "\n";

    return 0;
}


int sum_arr(int arr[], int n) {
    int total = 0;
    for(int i = 0; i < n; i++) {
        total = total + arr[i]; //使用下标的方式取值
    }
    return total;
}

int sum_arr2(int* arr, int n) {
    int total = 0;
    for(int i = 0; i < n; i++) {
        total = total + (*arr); //使用指针的方式取值
        arr++;
    }
    return total;
}