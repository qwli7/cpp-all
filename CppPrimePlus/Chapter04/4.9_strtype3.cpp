#include <iostream>
#include <cstring> // c-style 字符串
#include <string>  // string 类

int main() {
    using namespace std;

    char charr1[20]; 
    char charr2[20] = "jaguar";

    string str1;
    string str2 = "panther";

    //copy
    str1 = str2; // 对比 strcpy();
    strcpy(charr1, charr2);

    //append
    str1 += " paste";
    strcat(charr1,  " juice");

    //len
    int len1 = str1.size();
    int len2 = strlen(charr1);

    cout << "The string '" << str1 << "' contains " << len1 << " characters " << endl;
    cout << "The string '" << charr1 << "' contains " << len2 << " characters "<< endl;


    return 0;
}