#include <iostream>
#include <cstring>  //旧式 string.h 实现，使用 strlen() 方法来获取字符串长度

int main() {

    using namespace std;

    const int size = 15;  //定义长度为 15
    char name1[size];
    char name2[size] = "C++owboy";

    cout << "Howdy! I'm " << name2;
    cout << "! What's your name? \n";

    cin >> name1;  //输入到字符串数组中

    cout << "Well, " << name1 << ", your name has " << strlen(name1) << " letters and is stored\n";
    cout << "in an array of " << sizeof(name1) << " bytes.\n";

    cout << "Your initial is " << name1[0] << ".\n";

    name2[3] = '\0';  //提前截断字符串

    cout << "Here are the first 3 characters of my name: "; 
    cout << name2 << endl; // C++


    return 0;
}

