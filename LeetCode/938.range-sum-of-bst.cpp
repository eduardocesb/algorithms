/*
 * @lc app=leetcode id=938 lang=cpp
 *
 * [938] Range Sum of BST
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (root == NULL) return 0;
        
        if (low <= root->val && root ->val <= high)
            return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
        
        if (root->val > low)
            return rangeSumBST(root->left, low, high);
        
        return rangeSumBST(root->right, low, high);
    }
};
// @lc code=end

