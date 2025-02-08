#include <iostream>
#include "coordin.h"

using namespace std;

//编译需要将 coordin.cpp 同时编译
//g++ 9.3_file1.cpp coordin.cpp 

int main() {

    rect rplace;
    polar pplace;

    cout << "Enter the x and y values: ";
    while(cin>>rplace.x >> rplace.y) {
        pplace = rect_to_polar(rplace);
        show_polar(pplace);
        cout << " Next two numbers (q  to quit): ";
    }
    cout << "Bye! \n";
    return 0;
}