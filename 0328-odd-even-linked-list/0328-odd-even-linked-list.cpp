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
// 1 2 3 4 N
// 1 3 
// 2 4

// 1 2 3 4 5 N
// 1 3 5
// 2 4 N

// 1 2 3 N
// 1 3
// 2 N
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL) {
            return head;
        }
        ListNode *oddptr = head, *evenptr = head->next, *evenhead = head->next;
        while(oddptr->next != NULL && evenptr->next != NULL) {
            oddptr->next = oddptr->next->next;
            oddptr = oddptr->next;
            evenptr->next = evenptr->next->next;
            evenptr = evenptr->next;
        }
        oddptr->next = evenhead;
        return head;
    }
};