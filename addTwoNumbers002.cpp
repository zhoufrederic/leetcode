//
// Created by zibo on 19-6-20.
//
/*
 * 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-two-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        int addition = 0;
        ListNode* head = nullptr;
        ListNode* result = nullptr;

        while (l1 != nullptr && l2 != nullptr)
        {
            int sum = l1->val + l2->val + addition;
            auto temp = new ListNode(sum % 10);
            if (!head)
            {
                head = result = temp;
            }
            else
            {
                head = head->next = temp;
            }

            addition = sum / 10;
            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1 != nullptr)
        {
            int sum = l1->val + addition;
            auto temp = new ListNode(sum % 10);
            if (!head)
            {
                head = result = temp;
            }
            else
            {
                head = head->next = temp;
            }

            addition = sum / 10;
            l1 = l1->next;
        }

        while (l2 != nullptr)
        {
            int sum = l2->val + addition;
            auto temp = new ListNode(sum % 10);
            if (!head)
            {
                head = result = temp;
            }
            else
            {
                head = head->next = temp;
            }

            addition = sum / 10;
            l2 = l2->next;
        }

        if (addition != 0)
        {
            auto temp = new ListNode(addition);
            if (!head)
            {
                head = result = temp;
            }
            else
            {
                head = head->next = temp;
            }
        }


        return result;
    }
};