#ifndef EX_7_31_H
#define EX_7_31_H

// class Y; // 先声明 Y 是一个类，暂时不定义它，避免报错

class X
{
    Y *y;
};

class Y
{
    X x;
};

#endif
