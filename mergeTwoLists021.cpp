//
// Created by zibo on 19-6-20.
//
/*
 * 将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

示例：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-two-sorted-lists
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        if (l1 == nullptr)
        {
            return l2;
        }

        if (l2 == nullptr)
        {
            return l1;
        }

        ListNode* result = nullptr;
        ListNode* head = nullptr;

        while (l1 && l2)
        {
            ListNode* temp;
            if (l1->val < l2->val)
            {
                temp = l1;
                l1 = l1->next;
            }
            else
            {
                temp = l2;
                l2 = l2->next;
            }

            if (!result)
            {
                result = temp;
                head = temp;
            }
            else
            {
                head = head->next = temp;
            }
        }

        if (l1)
        {
            head = head->next = l1;
        }

        if (l2)
        {
            head = head->next = l2;
        }

        return result;
    }
};