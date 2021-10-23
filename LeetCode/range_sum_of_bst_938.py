class Solution:
    
    def range_sum(self, root, low, high):
        if root:

            if root.val < low:
                return self.range_sum(root.right, low, high)
            elif root.val > high:
                return self.range_sum(root.left, low, high)
            return root.val + self.range_sum(root.left, low, high) + self.range_sum(root.right, low, high)

        