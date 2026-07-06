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

class Solution {
public:
    bool hasCycle(ListNode* head) {
        // have one slow, one fast. Move fast forwards twice each time slow moves once
        // unless there's a cycle, they should never point to the same node
        // return once fast is NULL
        ListNode *fast = head, *slow = head;
        while (fast) {
            slow = slow->next;
            if (!fast->next) return false;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;

    }
};
