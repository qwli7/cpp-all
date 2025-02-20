#include "Chapter6.h"

long long fact(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    return n * fact(n - 1);
}

int abs2(int n)
{
    return n >= 0 ? n : -n;
}
