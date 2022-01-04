""" You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order, and each of their nodes contains a single digit.
Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself. """


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:

    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        pointer_l1 = l1
        pointer_l2 = l2
        l1_list = []
        l2_list = []
        while pointer_l1 is not None:
            l1_list.append(pointer_l1.val)
            pointer_l1 = pointer_l1.next

        while pointer_l2 is not None:
            l2_list.append(pointer_l2.val)
            pointer_l2 = pointer_l2.next

        smaller = min(len(l1_list), len(l2_list))
        larger = max(len(l1_list), len(l2_list))
        diff_num = larger - smaller
        add_list = [0] * diff_num
        if len(l1_list) < len(l2_list):
            l1_list.extend(add_list)
        else:
            l2_list.extend(add_list)

        carry = 0
        result = []

        for num in range(larger):
            if l1_list[num] + l2_list[num] + carry >= 10 and num == larger-1:
                sum_num = l1_list[num] + l2_list[num] + carry
                result.append(sum_num % 10)
                result.append(sum_num//10)
            elif l1_list[num] + l2_list[num] + carry >= 10:
                sum_num = l1_list[num] + l2_list[num] + carry
                result.append(sum_num % 10)
                carry = 1

            else:
                result.append(l1_list[num] + l2_list[num] + carry)
                carry = 0

        result = result[::-1]
        head = None
        for i in range(len(result)):
            node = ListNode(result[i], head)
            head = node

        return head
