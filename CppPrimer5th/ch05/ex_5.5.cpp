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

        if (score == 100)
        {
            finalgrade = "A++";
        }
        else if (score >= 90)
        {
            finalgrade = "A+";
        }
        else if (score >= 80)
        {
            finalgrade = "A";
        }
        else if (score >= 70)
        {
            finalgrade = "B+";
        }
        else if (score >= 60)
        {
            finalgrade = "B";
        }
        else
        {
            finalgrade = "C";
        }
        cout << "final grade: " << finalgrade << endl;
        --i;
    }

    return 0;
}
