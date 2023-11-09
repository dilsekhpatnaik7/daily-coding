/*
Problem Link: https://leetcode.com/problems/same-tree/description/

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

        return (p->val == q->val) && solve(p->left, q->left) && solve(p->right, q->right);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        return solve(p, q);
    }
};