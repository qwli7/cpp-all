#include <cmath>
#include "11.13_vector.h"

using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;

namespace VECTOR {
    const double Rad_to_deg = 45.0 / atan(1.0);

    //私有方法
    void Vector::set_mag() {
        mag = sqrt(x*x + y*y);
    }

    void Vector::set_ang() {
        if(x == 0.0 && y == 0.0) {
            ang = 0.0;
        }
        else {
            ang = atan2(y, x);
        }
    }

    void Vector::set_x() {
        x = mag * cos(ang);
    }

    void Vector::set_y() {
        y = mag *  sin(ang);
    }


    Vector::Vector() {
        x = y = mag = ang = 0.0;
        mode = RECT;
    }

    Vector::Vector(double n1, double n2, Mode from) {
        mode = from;
        if(from == RECT) {
            x = n1;
            y = n2;
            set_mag();
            set_ang();
        } else if(from == POL) {
            mag = n1;
            ang = n2/Rad_to_deg;
            set_x();
            set_y();
        } else {
            cout << "Incorrect 3rd argument to Vector() --";
            cout <<" vector set to 0\n";
            x = y = mag = ang = 0.0;
            mode = RECT;
        }
    }

    void Vector::reset(double n1, double n2, Mode from) {
        mode = from;
        if(from == RECT) {
            x = n1;
            y = n2;
            set_mag();
            set_ang();
        } else if(from == POL) {
            mag = n1;
            ang = n2/Rad_to_deg;
            set_x();
            set_y();
        } else {
            cout << "Incorrect 3rd argument to Vector() --";
            cout <<" vector set to 0\n";
            x = y = mag = ang = 0.0;
            mode = RECT;
        }
    }

    Vector::~Vector(){

    }

    void Vector::polar_mode() {
        mode = POL;
    }

    void Vector::rect_mode() {
        mode = RECT;
    }
    
    Vector Vector::operator+(const Vector& b) const {
        return Vector(x + b.x, y+b.y);
    }

    Vector Vector::operator-(const Vector & b) const {
        return Vector(x-b.x, y-b.y);
    }
    
};