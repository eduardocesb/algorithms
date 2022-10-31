"""
Given the root of a binary tree, return the inorder traversal of its nodes' values
"""

# Definition for a binary tree node.


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    
    def inorder_traversal(self, root:TreeNode):
        arr = []

        def _inorder_traversal(node, arr):
            if node is not None:
                _inorder_traversal(node.left, arr)
                arr.append(node.val)
                _inorder_traversal(node.right, arr)
            
        _inorder_traversal(root, arr)
        return arr
    



d = TreeNode(4)
c = TreeNode(3)
b = TreeNode(2, d)
a = TreeNode(1, b, c)


sol = Solution()
print(sol.inorder_traversal(a))

