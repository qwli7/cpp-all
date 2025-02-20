#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int a1 = 10, a2 = 20;
    cout << "before: " << a1 << " " << a2 << endl;
    swap(&a1, &a2);
    cout << "after: " << a1 << " " << a2 << endl;
    return 0;
}
