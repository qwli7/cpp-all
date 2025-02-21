#ifndef SCREEN_H_
#define SCREEN_H_
#include <string>
#include <vector>
class Screen
{

public:
    void some_member() const;

private:
    mutable size_t access_ctr; // 即使在一个 const 对象内也能被修改

public:
    Screen &display(std::ostream &os)
    {
        do_display(os);
        return *this;
    }
    const Screen &display(std::ostream &os) const
    {
        do_display(os);
        return *this;
    }

private:
    void do_display(std::ostream &os) const
    {
        os << contents;
    }

public:
    typedef std::string::size_type pos; // 定义了别名pos
    // using pos = std::string::size_type; // 等价于上一行代码

    Screen() = default;
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) {}
    char get() const
    { // 隐式内联
        return contents[cursor];
    };
    inline char get(pos ht, pos wd) const; // 显式内联
    Screen &move(pos r, pos c);

public:
    Screen &set(char);
    Screen &set(pos, pos, char);

private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
};

inline Screen &Screen::move(pos r, pos c) // 显式指定 inline
{
    pos row = r * width;
    cursor = row + c;
    return *this;
}
char Screen::get(pos ht, pos wd) const // 声明的时候已经指定 inline 了，这里可以省略 inline
{
    pos row = ht * width;
    return contents[row + wd];
}

inline void Screen::some_member() const
{
    ++access_ctr; // 即使在 const 对象内也能被修改
}

inline Screen &Screen::set(char c)
{
    contents[cursor] = c;
    return *this;
}
inline Screen &Screen::set(pos r, pos c, char ch)
{
    pos row = r * width;
    contents[row + c] = ch;
    return *this;
}

class Window_mgr
{
private:
    std::vector<Screen> screens{Screen(24, 80, ' ')};
};

#endif
