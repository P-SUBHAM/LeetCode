/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Approach 1: slow and fast pointer
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while(fast!=NULL && fast->next != NULL) {
            slow = slow->next; fast = fast->next->next;
            if(slow == fast) return true;
        }
        return false;
    }
};