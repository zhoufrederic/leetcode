//
// Created by zibo on 19-6-20.
//

/*
 * 判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

示例 1:

输入: 121
输出: true
示例 2:

输入: -121
输出: false
解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
示例 3:

输入: 10
输出: false
解释: 从右向左读, 为 01 。因此它不是一个回文数。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/palindrome-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <iostream>

using namespace std;

class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
        {
            return false;
        }

        char strNum[32] = {0};
        int length = 0;

        while (x)
        {
            strNum[length++] = x % 10 + '0';
            x /= 10;
        }

        for (int i = 0; i < length / 2; ++i)
        {
            if (strNum[i] != strNum[length - 1 - i])
            {
                return false;
            }
        }

        return true;
    }

    bool isPalindrome2(int x)
    {
        if (x < 0)
        {
            return false;
        }

        int nums[10] = {1,
                      10,
                      100,
                      1000,
                      10000,
                      100000,
                      1000000,
                      10000000,
                      100000000,
                      1000000000};
        int length = 0;
        for (int i = 9; i > 0; --i)
        {
            if (x >= nums[i])
            {
                length = i + 1;
                break;
            }
        }

        for (int i = 0; i < length / 2; ++i)
        {
            if ((x / nums[i] % 10) != (x / nums[length - 1 - i] % 10))
            {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    Solution s;
    if (s.isPalindrome2(10))
    {
        cout << "true!\n";
    }
    else
    {
        cout << "false\n";
    }
}