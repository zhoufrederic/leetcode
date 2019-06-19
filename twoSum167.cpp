//
// Created by zibo on 19-6-20.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * 给定一个已按照升序排列 的有序数组，找到两个数使得它们相加之和等于目标数。

函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2。

说明:

返回的下标值（index1 和 index2）不是从零开始的。
你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。
示例:

输入: numbers = [2, 7, 11, 15], target = 9
输出: [1,2]
解释: 2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
class Solution
{
public:
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        vector<int> results(2, 0);
        int length = numbers.size();

        for (int i = 0; i < length - 1; ++i)
        {
            int pos = binarySearch(numbers, i + 1, length - 1, target - numbers[i]);
            if (pos != -1)
            {
                results[0] = i + 1;
                results[1] = pos + 1;
                break;
            }
        }

        return results;
    }

    vector<int> twoSum2(vector<int>& numbers, int target)
    {
        vector<int> results;

        int left = 0;
        int right = numbers.size() - 1;

        while (left < right)
        {
            int sum = numbers[left] + numbers[right];
            if (sum == target)
            {
                results.push_back(left + 1);
                results.push_back(right + 1);
                break;
            }
            else if (sum < target)
            {
                ++left;
            }
            else
            {
                --right;
            }
        }


        return results;
    }

    int binarySearch(vector<int>& nums, int left, int right, int target)
    {
        while (left <= right)
        {
            int mid = (right - left) / 2 + left;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] > target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return -1;
    }
};