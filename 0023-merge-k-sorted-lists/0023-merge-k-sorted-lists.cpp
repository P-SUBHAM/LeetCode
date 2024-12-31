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

struct minHeap {
    bool operator()(pair<int, ListNode*> p1, pair<int, ListNode*> p2) {
        return p1.first > p2.first; // Min heap condition
    }
};
class Solution {
public:
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,minHeap> pq;
        for(int i = 0; i < k; i++) {
            if (lists[i] != nullptr) { // Only push non-null pointers
                cout<<(*lists[i]).val<<"\n";
                pq.push({lists[i]->val, lists[i]});
            }
        }
        ListNode *head = new ListNode();
        ListNode *temp = head;
        while(!pq.empty()) {
            ListNode* tope = pq.top().second;
            pq.pop();
            temp->next = tope;
            temp = temp->next;
            if(temp->next != NULL) {
                pq.push({temp->next->val,temp->next});
            }
        }
        return head->next;
    }
};

// in priority queue, the element that satisfies the comparator function is pushed deeper inside the heap
// so if a > b is true, then a satisfies the cond(is greater) and is pushed deeper into heap, making it min-heap