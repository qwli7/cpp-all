#include <iostream>
#include <ctime>

using std::cin;
using std::cout;
using std::endl;
using std::string;
int main()
{

    srand(time(nullptr));

    string finalgrade;
    int i = 10;
    while (i >= 0)
    {
        int score = rand() % 100 + 1;

        finalgrade = score >= 90 ? "A+" : (score >= 80 ? "A" : (score >= 70 ? "B+" : (score >= 60 ? "B" : "C")));
        cout << "final grade: " << finalgrade << endl;
        --i;
    }

    return 0;
}
