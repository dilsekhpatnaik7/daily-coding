/*
Problem Link: https://leetcode.com/problems/symmetric-tree/description/

Time Complexity: O(N)
Space Complexity: O(N)
*/

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
    bool solve(TreeNode* p, TreeNode* q) {
        if(!p || !q) return p == q;

        return p->val == q->val && solve(p->left, q->right) && solve(p->right, q->left);
    }

    bool isSymmetric(TreeNode* root) {
        if(!root) return true;

        return solve(root->left, root->right);
    }
};