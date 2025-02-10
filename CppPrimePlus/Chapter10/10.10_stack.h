#ifndef STACK_H_
#define STACK_H_


typedef unsigned long Item; //给 long 起一个别名，用 item 就像是使用 long

class Stack {
private:
    enum {MAX = 10};
    Item items[MAX];
    int top;

public:
    Stack(); //默认构造方法
    bool isEmpty() const; //判断队列是否空
    bool isFull() const; //判断队列是否已经满了

    bool push(const Item &item); //添加进队列
    bool pop(Item & item); //从队列中移除
};


#endif