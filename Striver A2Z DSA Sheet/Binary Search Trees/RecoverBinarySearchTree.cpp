/*
Problem Link: https://leetcode.com/problems/recover-binary-search-tree/description/

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
    void inorder(TreeNode* root, TreeNode*& first, TreeNode*& second, TreeNode*& prev) {
        if(!root) return;
        inorder(root->left, first, second, prev);

        if(prev && root->val < prev->val) {
            if(!first) {
                first = prev;
                second = root;
            } else second = root;
        }
        prev = root;
        inorder(root->right, first, second, prev);
    }

    void recoverTree(TreeNode* root) {
        TreeNode* first = nullptr;
        TreeNode* second = nullptr;
        TreeNode* prev = nullptr;
        
        inorder(root, first, second, prev);
        swap(first->val, second->val);
    }
};