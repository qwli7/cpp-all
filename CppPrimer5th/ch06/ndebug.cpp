#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    for (int i = 0; i < 10; ++i)
    {
#ifdef NDEBUG                                                                  // 启用 NDEBUG 宏
        cout << __func__ << " " << __FILE__ << " " << __LINE__ << " " << endl; // 打印调用方法
#endif
        cout << i << "-- ";
    }

    return 0;
}