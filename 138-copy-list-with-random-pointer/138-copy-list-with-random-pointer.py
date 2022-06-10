"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if head == None:
            return None
        temp = head
        while temp != None: #made newnode for deepcopy in loop
            nn = Node(x=temp.val,next=temp.next)
            temp.next = nn; temp=nn.next
        newhead = head.next; temp = head;
        while temp != None and temp.next != None: #copied random pointer in loop
            temp.next.random = temp.random.next if temp.random != None else None
            temp=temp.next.next
        temp = head;
        while temp != None and temp.next!=None and temp.next.next != None: #rejoining next pointers in loop
            x = temp
            xcopy = temp.next
            xnext = temp.next.next
            xcopynext = temp.next.next.next
            x.next = xnext
            xcopy.next = xcopynext
            temp = xnext
        return newhead
            