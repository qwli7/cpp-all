#include <iostream>
int main()
{
    int i = 100, sum = 0;
    for (int i = 0; i != 10; ++i)
    {
        sum += i;
    }
    std::cout << "sum = " << sum << std::endl; //输出 0-9 的累加和

    return 0;
}
