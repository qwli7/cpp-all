#ifndef COORDIN_H_
#define COORDIN_H_

struct polar{
    double distance;
    double angle;
};
struct rect {
    double x;
    double y;
};


//方法原型
polar rect_to_polar(rect xypos);
void show_polar(polar dapos);


#endif