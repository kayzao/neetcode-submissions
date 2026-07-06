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
    void reorderList(ListNode* head) {
        // we must reorder the addresses themselves of this singly linked list
        // Since we are esentially combining two linked lists, one is the reverse of the other,
        // we may be able to use a stack
        
        // plan: Make a first pass to add all nodes to the stack and get the length of list
        // On second pass, for each node, we insert the top of the stack inbetween curr and next
        // repeat until length/2 is surpassed

        ListNode *curr = head;
        int length = 0;
        stack<ListNode *> st;
        while (curr) {
            st.push(curr);
            curr = curr->next;
            length++;
        }
        curr = head;
        int i = 0;

        // this should be unnecessary since the pointers should be reorganized but in case,
        while (i < length / 2) {
            auto tp = st.top(); // 8
            ListNode *next = curr->next; // 4
            curr->next = tp; //2
            tp->next = next;
            st.pop();
            curr = next;
            i++;
        }
        if (curr) curr->next = nullptr;
    }
};
