#include "11.4_mytime1.h"
#include <iostream>

Time::Time() {
    this->hours = this->minutes = 0;
    // hours = minutes = 0
}

Time::Time(int h, int m) {
    hours = h;
    minutes = m;
}

void Time::AddMin(int m) {
    minutes += m;
    hours += minutes / 60;
    minutes %= 60;
}

void Time::AddHr(int h) {
    hours += h;
}

void Time::Reset(int h, int m) {
    hours = h;
    minutes = m;
}


//重载操作符
Time Time::operator+(const Time & t) const {
    Time sum;
    sum.minutes = minutes + t.minutes;
    sum.hours = hours + t.hours + sum.minutes/60;
    sum.minutes %= 60;
    return sum;
}

void Time::Show() const {
    std::cout << hours << " hours, " << minutes << " minutes" << std::endl;
}