//
// Created by zibo on 19-6-24.
//
/*
 * 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例:

输入: [-2,1,-3,4,-1,2,1,-5,4],
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
进阶:

如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-subarray
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>

using namespace std;


class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        return maxSubSum(nums, 0, nums.size() - 1);
    }

    int maxSubSum(const vector<int>& nums, int left, int right)
    {
        if (left == right)
        {
            return nums[left];
        }

        int mid = left + (right - left) / 2;
        int maxLeftSum = maxSubSum(nums, left, mid);
        int maxRightSum = maxSubSum(nums, mid + 1, right);

        int maxLeftBorderSum = 0;
        int leftBorderSum = 0;
        for (int i = mid; i >= left; --i)
        {
            leftBorderSum += nums[i];
            if (leftBorderSum > maxLeftBorderSum)
            {
                maxLeftBorderSum = leftBorderSum;
            }
        }


        int maxRightBorderSum = 0;
        int rightBorderSum = 0;
        for (int i = mid + 1; i <= right; ++i)
        {
            rightBorderSum += nums[i];
            if (maxRightBorderSum < rightBorderSum)
            {
                maxRightBorderSum = rightBorderSum;
            }
        }

        return maxThree(maxLeftSum, maxRightSum, maxLeftBorderSum + maxRightBorderSum);
    }

    int maxThree(int a, int b, int c)
    {
        if (a < b)
        {
            a = b;
        }

        if (a > c)
        {
            return a;
        }
        else
        {
            return c;
        }
    }

    int maxSubArray2(vector<int>& nums)
    {
        if (nums.empty())
        {
            return 0;
        }

        int sum = nums[0];
        int maxSum = nums[0];

        for (int i = 1; i < nums.size(); ++i)
        {
            if (sum < 0)
            {
                sum = 0;
            }

            sum += nums[i];
            if (sum > maxSum)
            {
                maxSum = sum;
            }
        }

        return maxSum;
    }
};

int main()
{
    Solution s;
    vector<int> nums{-2, -1};

    s.maxSubArray(nums);

    return 0;
}