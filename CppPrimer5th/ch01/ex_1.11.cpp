#include <iostream>

int main()
{
    int a = 0, b = 0;
    std::cout << "Please enter two numbers: " << std::endl;
    std::cin >> a >> b;
    if (a == b)
    {
        std::cout << a << std::endl;
    }
    else if (a < b)
    {
        for (int i = a; i <= b; i++)
        {
            std::cout << i << " ";
        }
    }
    else
    {
        for (int i = b; i <= a; i++)
        {
            std::cout << i << " ";
        }
    }
    return 0;
}
