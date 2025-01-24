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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL || (left==right)) return head;
        ListNode *dummy = new ListNode(); dummy->next = head;
        ListNode *currptr = head, *prevptr = dummy, *nextptr;
        for(int i = 0; i < left-1; i++) {
            nextptr = currptr->next;
            prevptr = currptr;
            currptr = nextptr;
        }
        ListNode *l = prevptr;
        for(int i = 0; i < (right-left+1); i++) {
            nextptr = currptr->next;
            currptr->next = prevptr;
            prevptr = currptr;
            currptr = nextptr;
        }
        // cout<<l->val<<endl;
        // if(l!=NULL && l->next!=NULL)
            l->next->next = currptr;
        // if(l!=NULL)
            l->next = prevptr;
        // cout<<currptr->val<<endl;
        return dummy->next;
    }
};