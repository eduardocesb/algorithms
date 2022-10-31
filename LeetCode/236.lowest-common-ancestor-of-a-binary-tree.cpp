/*
 * @lc app=leetcode id=236 lang=cpp
 *
 * [236] Lowest Common Ancestor of a Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*
Time Complexity: O(N)
Memory Complexity: O(H)
*/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        //Now,the root is nonull and different of the 'p' and 'q'


        //There's no one in the left, so the answer it's the right side
        if (!left) return right;


        //There's someone in the left, but no one in the right, so the answer it's the left
        if (!right) return left;


        //There's in two sides, so the LCA it's the current node.
        return root;
    }
};
// @lc code=end

