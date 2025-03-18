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

// 1h1 2 3s N
// 1 2s 3f N
// 1 2 N
// 4h2 5 N
// Approach 1: Merge Sort for Linked List sorting
// Take care to handle when there are 2 nodes
class Solution {
public:
  ListNode* sortList(ListNode* head) {
    if (head == NULL || head->next == NULL)
      return head;
    ListNode *slow = head, *fast = head;
    if(head->next->next == NULL) {// if you don't use fast->next->next != NULL for 2 node
      if(head->val > head->next->val)
        swap(head->val,head->next->val);
      return head;
    }
    while (fast != NULL && fast->next != NULL){ // && fast->next->next != NULL) {
      slow = slow->next;
      fast = fast->next->next;
    }
    ListNode *head1 = head, *head2 = slow->next; // spliting to halves
    slow->next = NULL;                           // breaking the link
    head1 = sortList(head1);
    head2 = sortList(head2);
    ListNode* dummy = new ListNode;
    ListNode* ptr = dummy;
    while (head1 != NULL && head2 != NULL) {
      if(head1->val < head2->val) {
        ptr->next = head1;
        ptr = ptr->next;
        head1 = head1->next;
      }
      else {
        ptr->next = head2;
        ptr = ptr->next;
        head2 = head2->next;
      }
    }
    while(head1 != NULL) {
      ptr->next = head1;
      ptr = ptr->next;
      head1 = head1->next;
    }
    while(head2 != NULL) {
      ptr->next = head2;
      ptr = ptr->next;
      head2 = head2->next;
    }
    return dummy->next;
  }
};