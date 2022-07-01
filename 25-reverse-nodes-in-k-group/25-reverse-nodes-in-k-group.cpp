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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==0) return 0;
        int x = 0; ListNode* temp = head;
        while(x < k && temp!= NULL) {
            temp=temp->next;
            x++;
        }
        if(x!=k) {
            return head;
        }
        ListNode *prev = 0, *next, *curr = head;
        int count = 0;
        while(curr != 0 && count < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        ListNode *rPtr = reverseKGroup(curr,k);
        head->next = rPtr;
        return prev;
        
    }
};