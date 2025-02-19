#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
int main()
{

    int grade = 66;
    string finalgrade = (grade > 90) ? "high pass" : (grade < 60) ? "fail"
                                                 : (grade < 75)   ? "low pass"
                                                                  : "pass";
    // if 条件判断版本
    if (grade > 90)
    {
        finalgrade = "high pass";
    }
    else if (grade < 60)
    {
        finalgrade = "fail";
    }
    else if (grade > 60 && grade < 75)
    {
        finalgrade = "low pass";
    }
    else
    {
        finalgrade = "pass";
    }
    cout << finalgrade << endl;
    return 0;
}
