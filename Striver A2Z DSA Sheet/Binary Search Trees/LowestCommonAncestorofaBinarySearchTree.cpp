/*
Problem Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/

Time Complexity: O(N)
Space Complexity: O(N)
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return root;

        int value = root->val;
        if(p->val < value && q->val < value) return solve(root->left, p, q);
        else if(p->val > value && q->val > value) return solve(root->right, p, q);
        else return root;
    } 

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root, p, q);
    }
};

// Iterative
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int small = min(p->val, q->val);
        int large = max(p->val, q->val);
        while(root) {
            if(root->val > large) root = root->left;
            else if(root->val < small) root = root->right;
            else return root;
        }
        return nullptr;
    }
};