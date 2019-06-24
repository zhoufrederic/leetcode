//
// Created by zibo on 19-6-24.
//
/*
 * 给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。

最高位数字存放在数组的首位， 数组中每个元素只存储一个数字。

你可以假设除了整数 0 之外，这个整数不会以零开头。

示例 1:

输入: [1,2,3]
输出: [1,2,4]
解释: 输入数组表示数字 123。
示例 2:

输入: [4,3,2,1]
输出: [4,3,2,2]
解释: 输入数组表示数字 4321。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/plus-one
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int>& digits)
    {
        int i = 0;
        for (i = 0; i < digits.size(); ++i)
        {
            if (digits[i] != 9)
            {
                break;
            }
        }

        if (i == digits.size())
        {
            digits[0] = 1;
            for (int j = 1; j < digits.size(); ++j)
            {
                digits[j] = 0;
            }
            digits.push_back(0);
        }
        else
        {
            int length = digits.size() - 1;
            int sum = digits[length] + 1;
            int addition = sum / 10;
            digits[length--] = sum % 10;

            while (addition != 0)
            {
                sum = digits[length] + addition;
                digits[length--] = sum % 10;
                addition = sum / 10;
            }
        }

        return digits;
    }
};