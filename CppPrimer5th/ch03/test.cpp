#include <iostream>

using std::cout;
using std::endl;
int main()
{

    int ia2[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *p1 = &ia2[1];
    int *p2 = &ia2[5];
    cout << *p1 << endl; // 1
    cout << *p2 << endl; // 5
    cout << endl;
    p1 += p2 - p1;
    cout << *p1 << endl; // 5
    cout << *p2 << endl; // 5

    return 0;
}