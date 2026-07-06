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
    ListNode* reverseList(ListNode* head) {
        // for each node, the curr->next needs to point to curr
        // and repeat until the end, then return curr
        if (!head) return head;
        ListNode *curr = head, *next = curr->next;
        curr->next = nullptr;
        while (next) {
            ListNode* nextnext = next->next;
            next->next = curr;
            curr = next;
            next = nextnext;

            /*
            0 1->2->3
            ^
            // point 1 to 0, set curr to 1, next to 2
         0<-1 2->3
            ^
            // save next's next, point next to curr, update curr->2, next to 3
         0<-1<-2 3
               ^
            // save next's next, point next to curr, set next to next's next
            0<-1<-2<-3
            // next is NULL, we return
            
            */
        }
        return curr;
    }
};
