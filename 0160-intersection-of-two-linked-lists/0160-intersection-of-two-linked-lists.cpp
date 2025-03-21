/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// Approach 1: Linked List cycle detection
// traverse both LL and at end both will meet at either intersection or at the end at NULL
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *l1 = headA, *l2 = headB;
        while(l1 != l2) {
            if(l1 == NULL) 
                l1 = headB;
            else
                l1 = l1->next;
            
            if(l2 == NULL)
                l2 = headA;
            else
                l2 = l2->next;
        }
        return l1;
    }
};