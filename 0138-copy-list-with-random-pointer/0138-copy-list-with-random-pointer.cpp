/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
// Approach 1: Iterative
// Create Node clone(val) make p->next = newp
// 1 iter to fix random ptr links
// 1 iter to fix next links
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *p = head;
        if(head == NULL) return head;
        while(p != NULL) {
            Node *newp = new Node(p->val); // creating deepcopy nodes
            newp->next = p->next;
            p->next = newp;
            p = p->next->next;
        }
        p = head;
        Node *newhead = p->next;
        while(p != NULL) { // move random ptr links
            if(p->random != NULL) p->next->random = p->random->next;
            p = p->next->next;
        }
        p = head;
        while(p != NULL) { // moves next ptr links
            Node *newp = p->next;
            if(!newp->next) {p->next = NULL; break;}
            p->next = newp->next; // og next link restore
            newp->next = p->next->next;
            p = p->next;
        }
        return newhead;
    }
};