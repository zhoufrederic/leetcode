//
// Created by zibo on 19-6-20.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

/*
 * 给定一个二叉搜索树和一个目标结果，如果 BST 中存在两个元素且它们的和等于给定的目标结果，则返回 true。

案例 1:

输入:
    5
   / \
  3   6
 / \   \
2   4   7

Target = 9

输出: True
 

案例 2:

输入:
    5
   / \
  3   6
 / \   \
2   4   7

Target = 28

输出: False

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/two-sum-iv-input-is-a-bst
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    bool findTarget(TreeNode* root, int k)
    {
        vector<int> nums;
        map<int, int> hash;
        convertToVector(root, nums);

        int left = 0;
        int right = nums.size() - 1;

        while (left < right)
        {
            int sum = nums[left] + nums[right];
            if (sum == k)
            {
                return true;
            }
            else if (sum > k)
            {
                --right;
            }
            else
            {
                ++left;
            }
        }

        return false;
    }

    void convertToVector(TreeNode* root, vector<int>& nums)
    {
        if (root && root->left != NULL)
        {
            convertToVector(root->left, nums);
        }

        if (root != NULL)
        {
            nums.push_back(root->val);
        }

        if (root && root->right != NULL)
        {
            convertToVector(root->right, nums);
        }
    }
};