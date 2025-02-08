#include "coordin.h" //引入自己编写的头文件
#include <iostream>
#include <cmath>

// 实现 .h 里面定义的方法
polar rect_to_polar(rect xypos) {
    using namespace std;

    polar answer;

    answer.distance = sqrt(xypos.x * xypos.x + xypos.y * xypos.y);
    answer.angle = atan2(xypos.y, xypos.x);
    return answer;
}


void show_polar(polar dapos) {
    using namespace std;
    const double Rad_to_deg = 57.29577951;
    cout << "distance = "<< dapos.distance;
    cout << ", angle = " << dapos.angle * Rad_to_deg;
    cout << " degrees\n";
}