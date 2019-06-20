//
// Created by zibo on 19-6-20.
//

#include <cstdint>
#include <vector>
#include <iostream>

/*
 * 颠倒给定的 32 位无符号整数的二进制位。

 

示例 1：

输入: 00000010100101000001111010011100
输出: 00111001011110000010100101000000
解释: 输入的二进制串 00000010100101000001111010011100 表示无符号整数 43261596，
      因此返回 964176192，其二进制表示形式为 00111001011110000010100101000000。
示例 2：

输入：11111111111111111111111111111101
输出：10111111111111111111111111111111
解释：输入的二进制串 11111111111111111111111111111101 表示无符号整数 4294967293，
      因此返回 3221225471 其二进制表示形式为 10101111110010110010011101101001。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-bits
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
using namespace std;

class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        vector<int> bits(32, 0);
        uint32_t result = 0;
        int i = 0;

        while (n)
        {
            bits[i++] = n % 2;
            n /= 2;
        }

        for (int j = 0;  j < 32; ++j)
        {
            cout << bits[j];
            result = result * 2 + bits[j];
        }

        cout << endl << result << endl;
        return result;
    }
};

int main()
{
    Solution s;
    s.reverseBits(4294967293);

    return 0;
}