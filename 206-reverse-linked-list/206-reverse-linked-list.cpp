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
    ListNode* reverseList(ListNode* A) {
        //Iterative
        if(A == 0 || A->next == 0) {
            return A;
        }
        ListNode *temp, *prev;
        prev = A;
        temp = A->next;
        while(temp != 0) {
            ListNode* nextPtr = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nextPtr;
        }
        A->next = 0;
        return prev;
    }
};