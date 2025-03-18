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
	    if(head == NULL) return NULL;
        if(head->next==NULL && n == 1) return NULL;
        ListNode *iniptr = head;
        int k = n + 1;
        while(k--) {
        if(iniptr == NULL) return head->next;
            iniptr = iniptr->next;
        }
        ListNode *currptr = head;
        while(iniptr != NULL) {
            iniptr = iniptr->next;
            currptr = currptr->next;
        }
        ListNode *deleteNode = currptr->next;
        currptr->next = deleteNode->next;
        // delete deleteNode;
        return head;
	
   }
};
