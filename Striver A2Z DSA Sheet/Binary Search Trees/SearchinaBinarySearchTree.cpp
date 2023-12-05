/*
Problem Link: https://leetcode.com/problems/search-in-a-binary-search-tree/description/

Time Complexity: O(log(N))
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
    TreeNode* solve(TreeNode* root, int val) {
        if(!root || root->val == val) return root;
        
        if(val < root->val) return solve(root->left, val);
        else return solve(root->right, val);
    }

    TreeNode* searchBST(TreeNode* root, int val) {
        return solve(root, val);
    }
};