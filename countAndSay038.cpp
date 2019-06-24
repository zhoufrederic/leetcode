//
// Created by zibo on 19-6-24.
//

/*
 *
 * 报数序列是一个整数序列，按照其中的整数的顺序进行报数，得到下一个数。其前五项如下：

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 被读作  "one 1"  ("一个一") , 即 11。
11 被读作 "two 1s" ("两个一"）, 即 21。
21 被读作 "one 2",  "one 1" （"一个二" ,  "一个一") , 即 1211。

给定一个正整数 n（1 ≤ n ≤ 30），输出报数序列的第 n 项。

注意：整数顺序将表示为一个字符串。

 

示例 1:

输入: 1
输出: "1"
示例 2:

输入: 4
输出: "1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-and-say
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
    string countAndSay(int n)
    {
        string str = "1";
        for (int i = 1; i < n; ++i)
        {
            int count = 1;
            char c = str[0];
            string temp;
            for (int j = 1; j < str.size(); ++j)
            {
                if (str[j] == c)
                {
                    ++count;
                }
                else
                {
                    temp += (count + '0');
                    temp += c;

                    c = str[j];
                    count = 1;
                }
            }
            if (count)
            {
                temp += (count + '0');
                temp += str[str.size() - 1];
            }

            str = temp;
            cout << str << endl;
        }

        return str;
    }
};

int main()
{
    Solution s;
    s.countAndSay(7);

    return 0;
}