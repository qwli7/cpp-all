#include <iostream>

typedef struct inflatable {
    char name[20];
    float volume;
    double price;
} inf; //inf 为别名

int main() {
    using namespace std;
    inf *ps = new inf;
    cout << "Enter name of inf item: ";
    cin.get(ps->name, 20);  // -> 操作符
    cout <<"Enter volume in cubic feet: ";
    cin >> (*ps).volume; // . 操作符
    cout <<"Enter price: ";
    cin >> ps->price;

    cout << "Name: " << (*ps).name << endl;
    cout << "Volume: " << ps->volume << endl;
    cout << "Price: $" << (*ps).price << endl;

    delete ps; //释放内存
    
    return 0;
}