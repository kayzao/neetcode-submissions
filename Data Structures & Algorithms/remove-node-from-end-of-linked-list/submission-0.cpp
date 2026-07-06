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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // since we need length of list, we need one pass first

        // idea 1: Use a stack to get the nodes in reverse order,
        // pop n-1 times, thats the next, pop n+1 times, thats the prev
        // if next isnt defined, thats ok, if prev isnt defined, just return next;

        // idea 2: just make another pass and do math to get the nth node, same cases

        ListNode *curr = head;
        int len = 0;
        while (curr) {
            len++;
            curr = curr->next;
        }

        // edge case where the first node is removed
        if (n == len) {
            return head->next;
        }

        curr = head;
        for (int i = 1; i < len - n; i++) {
            // 1, 2, 3, 4, n=2, len = 4
            // if n=0, len=4, get next only twice
            curr = curr->next;
        }
        // curr is prev
        curr->next = curr->next->next;
        return head;
        

    }
};
