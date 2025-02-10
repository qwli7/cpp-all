#ifndef VECTOR_H_
#define VECTOR_H_
#include <iostream>

namespace VECTOR { //加上名称空间，避免和内置的 Vector 冲突
    class Vector {
    public:
        enum Mode{RECT, POL};
    private:
        double x;
        double y;
        double mag;
        double ang;
        Mode mode;
        void set_mag();
        void set_ang();
        void set_x();
        void set_y();
    public:
        Vector();
        Vector(double n1, double n2, Mode from = RECT);
        void reset(double n1, double n2, Mode from = RECT);
        ~Vector();

        //内联函数，不会修改数据，设置成 const
        double xval() const {
            return x; //内联函数
        };

        double yval() const {
            return y;
        }
        double magval() const {
            return mag;
        }
        double angval() const {
            return ang;
        }
        // 内联函数结束

        void polar_mode();
        void rect_mode();

        //操作符重载
        Vector operator+(const Vector & b) const;
        Vector operator-(const Vector & b) const;
        Vector operator-() const;
        Vector operator*(double n) const;

        //友元函数
        friend Vector operator*(double n, const Vector & a);
        friend std::ostream & operator<<(std::ostream &os, const Vector& v);

    };
} //namespace 结束


#endif