// Problem Link: https://leetcode.com/problems/invert-binary-tree/
// Leetcode I'd: https://leetcode.com/dilsekhpatnaik7/

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
    void help(TreeNode* root){
        if(!root) return;
        help(root->left);
        help(root->right);
        auto t = root->left;
        root->left = root->right;
        root->right = t;
    }
    TreeNode* invertTree(TreeNode* root) {
        help(root);
        return root;
    }
};