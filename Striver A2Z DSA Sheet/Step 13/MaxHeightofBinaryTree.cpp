/*
Problem Link: https://leetcode.com/problems/maximum-depth-of-binary-tree/description/

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
    int solve(TreeNode* &root) {
        if(!root) return 0;

        return 1 + max(solve(root->left), solve(root->right));
    }

    int maxDepth(TreeNode* root) {
        return solve(root);
    }
};