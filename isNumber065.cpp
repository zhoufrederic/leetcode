//
// Created by zibo on 19-6-26.
//
/*
 * 验证给定的字符串是否可以解释为十进制数字。

例如:

"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
" -90e3   " => true
" 1e" => false
"e3" => false
" 6e-1" => true
" 99e2.5 " => false
"53.5e93" => true
" --6 " => false
"-+3" => false
"95a54e53" => false

说明: 我们有意将问题陈述地比较模糊。在实现代码之前，你应当事先思考所有可能的情况。这里给出一份可能存在于有效十进制数字中的字符列表：

数字 0-9
指数 - "e"
正/负号 - "+"/"-"
小数点 - "."
当然，在输入中，这些字符的上下文也很重要。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool isNumber(string s)
    {
        int state = 0;
        int mask = 0X168;
        int transfer[9][5] = {
                { 0, 1, 6, 2,-1},
                {-1,-1, 6, 2,-1},
                {-1,-1, 3,-1,-1},
                { 8,-1, 3,-1, 4},
                {-1, 7, 5,-1,-1},
                { 8,-1, 5,-1,-1},
                { 8,-1, 6, 3, 4},
                {-1,-1, 5,-1,-1},
                { 8,-1,-1,-1,-1}
        };

        for (const auto& c : s)
        {
            int id = toNum(c);
            if (id < 0)
            {
                return false;
            }
            state = transfer[state][id];
            if (state < 0)
            {
                return false;
            }
        }

        return (mask & (1 << state)) > 0;
    }

    int toNum(char c)
    {
        switch (c)
        {
            case ' ':
                return 0;
            case '+':
            case '-':
                return 1;
            case '.':
                return 3;
            case 'e':
                return 4;
            default:
                if (c >= '0' && c <= '9')
                    return 2;
        }
        return -1;
    }

    bool isNumber2(string s)
    {
        int i = 0;

        for (i = 0; s[i] == ' '; ++i) {}
        if (s[i] == '+' || s[i] == '-')
        {
            ++i;
        }

        int n_number;
        int n_point;
        for (n_number = 0, n_point = 0; (s[i] <= '9' && s[i] >= '0') || s[i] == '.'; ++i)
        {
            s[i] == '.' ? ++n_point : ++n_number;
        }

        if (n_point > 1 || n_number < 1)
        {
            return false;
        }

        if (s[i] == 'e')
        {
            ++i;
            if (s[i] == '+' || s[i] == '-')
            {
                ++i;
            }

            int n = 0;
            for (; s[i] >= '0' && s[i] <= '9'; i++, ++n)
            {
            }

            if (n < 1)
            {
                return false;
            }
        }

        for (; s[i] == ' '; ++i) {}

        return s[i] == '\0';
    }

    bool isNumber3(string s)
    {
        trim(s);
        bool numberSeen = false;
        bool pointSeen = false;
        bool eSeen = false;
        bool numberAfterE = true;

        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                numberSeen = true;
                numberAfterE = true;
            }
            else if (s[i] == '.')
            {
                if (eSeen || pointSeen)
                {
                    return false;
                }
                pointSeen = true;
            }
            else if (s[i] == 'e')
            {
                if (eSeen || !numberSeen)
                {
                    return false;
                }
                eSeen = true;
                numberAfterE = false;
            }
            else if (s[i] == '-' || s[i] == '+')
            {
                if (i != 0 && s[i - 1] != 'e')
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }

        return numberSeen && numberAfterE;
    }

    void trim(string s)
    {
        s.erase(0, s.find_first_not_of(' '));
        s.erase(s.find_last_not_of(' ') + 1);
    }
};

int main()
{
    Solution s;
    s.trim("  dd");

    return 0;
}