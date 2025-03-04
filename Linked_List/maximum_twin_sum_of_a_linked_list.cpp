// https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/?envType=study-plan-v2&envId=leetcode-75

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    // Function to reverse a linked list
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *curr = head;

        while (curr)
        {
            ListNode *nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev; // New head of the reversed list
    }

    int pairSum(ListNode *head)
    {
        auto fast = head;
        auto slow = head;

        while (fast and fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        auto secondHalf = reverseList(slow);
        auto firstHalf = head;

        int ans = 0;

        while (secondHalf)
        {
            ans = max(ans, firstHalf->val + secondHalf->val);
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }
        return ans;
    }
};