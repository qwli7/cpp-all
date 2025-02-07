#include <iostream>
#include <fstream>
#include <cstdlib> //支持 exit() 方法退出程序

const int size = 60;

int main() {
    using namespace std;
    char filename[size];
    ifstream inFile; //文件处理对象

    cout << "Enter name of data file:" ;
    cin.getline(filename, size);
    inFile.open(filename); //关联文件

    //检查文件是否能正常打开
    if(!inFile.is_open()) { //文件打开失败
        cout << "Could not open the file " << filename << endl;
        cout << "Program terminating.\n";
        exit(EXIT_FAILURE);
    }
    double value;
    double sum = 0.0;
    int count = 0;
    
    inFile >> value; //读取第一个值
    
    // 判断是否正常读取
    while(inFile.good()) { //是否是结束符EOF，并且是否正确读取到数值（value 类型必须为 double）
        ++count;
        sum+=value;
        inFile >> value;
    }
    if(inFile.eof()) {
        cout << "End of file reached. \n";
    } else if(inFile.fail()) {
        cout << "Input terminated by data mismatch.\n";  //读取到数据不匹配的类型
    } else {
        cout << "Input terminated for unknown reason.\n";
    }
    if(count == 0) {
        cout << "No data processed. \n";
    } else {
        cout << "Items read: "<< count << endl;
        cout << "Sum: " << sum << endl;
        cout << "Average: " << sum/count << endl;
    }
    inFile.close(); //关闭文件
    return 0;
}