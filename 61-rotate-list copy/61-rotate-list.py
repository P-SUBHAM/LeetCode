# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        temp = head ; n = 0
        while temp != None: 
            n=n+1; temp = temp.next
        temp = end = head; 
        if n == 0:
            return head
        k %= n
        for i in range(k):
            end = end.next
        while end.next != None:
            temp=temp.next; end = end.next
        # NewLinks
        end.next = head
        head = temp.next
        temp.next = None
        return head