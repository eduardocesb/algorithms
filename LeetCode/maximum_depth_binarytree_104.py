"""
Given the root of a binary tree, return its maximum depth.
A binary tree's maximum depth is the number of nodes along
the longest path from the root node down to the farthest leaf node.
"""

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    
    def maxDepth(self, root: TreeNode) -> int:
        if not root:
            return 0
        return self.height(root)
        
        
    def height(self, root):
        if root is not None:
            return self._height(root, 0)


    def _height(self, cur_level, tree_height):
        if cur_level is None:
            return tree_height
        left_height = self._height(cur_level.left, tree_height + 1)
        right_height = self._height(cur_level.right, tree_height + 1)
        return max(left_height, right_height)
        

        