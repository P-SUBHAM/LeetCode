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
// Approach 1:
// reverse first k nodes, (if cnt < k reverse cnt nodes again and ret)
// reverseK for next right ptr onwards, modify linke (last ptr after k rev)head->next = rptr, return prevptr
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *currptr=head, *prevptr=NULL, *nextptr; int cnt = 0;
        while(currptr != NULL && cnt < k) {
            cnt++;
            nextptr = currptr->next;
            currptr->next = prevptr;
            prevptr = currptr;
            currptr = nextptr;
        }
        if(cnt != k) {
            return reverseKGroup(prevptr,cnt);
        }
        if(currptr!=NULL) {
            ListNode *rptr = reverseKGroup(currptr,k);
            head->next = rptr;
            return prevptr;
        }
        else {
            return prevptr;
        }
        return NULL;
    }
};