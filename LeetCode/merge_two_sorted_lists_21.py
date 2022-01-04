class Node:

    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:

    def merge_two_lists(self, l1:Node, l2:Node):

        head = Node()
        curr = head

        while l1 and l2:
            if l1.val < l2.val:
                curr.next = l1
                l1 = l1.next
            else:
                curr.next = l2
                l2 = l2.next
            curr = curr.next

        if l1:
            curr.next = l1
        if l2:
            curr.next = l2

        return head.next



