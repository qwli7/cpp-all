#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    string maxWord;   // 记录出现最大单词的字符串
    int maxCount = 0; // 记录出现最大单词的次数
    string lastWord;
    int count = 0;
    string str;
    while (cin >> str)
    {
        if (lastWord.empty() && count == 0)
        {
            // 第一次进来，初始化lastWord和count
            lastWord = str;
            count++;
        }
        else
        {
            // 判断下一次进来的单词是否和上一次一样，如果一样，则累加次数
            if (str == lastWord)
            {
                count++;
            }
            else
            {
                // 如果不一样，则赋值，且重置 count 的次数为 1
                if (count > maxCount)
                {
                    maxCount = count;
                    maxWord = lastWord;
                }
                count = 1; // 重置为1次
                lastWord = str;
            }
        }
    }
    if (maxCount <= 1)
    {
        // 说明每个单词都只出现了一次，没有连续出现的单词
        cout << "no continuous words" << endl;
        return 0;
    }
    cout << "max word: " << maxWord << " count: " << maxCount << endl;

    return 0;
}