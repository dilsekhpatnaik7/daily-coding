/*
Problem Link: https://leetcode.com/problems/delete-node-in-a-bst/description/

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
    TreeNode* findLastRight(TreeNode* root) {
        while(root->right) root = root->right;
        return root;
    }

    TreeNode* solve(TreeNode* root) {
        if(!root->left) return root->right;
        if(!root->right) return root->left;

        TreeNode* rightChild = root->right;
        TreeNode* lastRight = findLastRight(root->left);
        lastRight->right = rightChild;
        
        return root->left;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;

        if(root->val == key) return solve(root);
        TreeNode* node = root;
        while(root) {
            if(key > root->val) {
                if(root->right && root->right->val == key) {
                    root->right = solve(root->right);
                    break;
                } else root = root->right;
            } else {
                if(root->left && root->left->val == key) {
                    root->left = solve(root->left);
                    break;
                } else root = root->left;
            }
        }
        return node;
    }
};