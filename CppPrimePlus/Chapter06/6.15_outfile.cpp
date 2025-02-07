#include <iostream>
#include <fstream>

int main() {
    using namespace std;

    char automobile[50];
    int year;
    double a_price;
    double d_price;

    ofstream outFile; //为文件创建一个输出对象

    outFile.open("carinfo.txt"); //关联文件
    cout << "Enter the make and model of automobile: "; 
    cin.getline(automobile, 50);

    cout << "Enter the model year: ";
    cin >> year;

    cout << "Enter the original asking price: ";
    cin >> a_price;

    d_price = 0.913* a_price;

    //在控制台输出信息
    cout << fixed;
    cout.precision(2); //设置精度
    cout.setf(ios_base::showpoint);
    cout << "Make and model: "<< automobile << endl;
    cout << "Year: "<< year << endl;
    cout <<"Was asking $" << a_price << endl;
    cout << "Now asking $" << d_price << endl;

    //输出到文件
    outFile << fixed;
    outFile.precision(2);
    outFile.setf(ios_base::showpoint);
    outFile << "Make and model: " << automobile << endl; //把内容写向文件
    outFile << "Year: "<< year << endl; //把内容写向文件
    outFile <<"Was asking $" << a_price << endl; //把内容写向文件
    outFile << "Now asking $" << d_price << endl; //把内容写向文件
 

    outFile.close(); //关闭文件

    return 0;
}