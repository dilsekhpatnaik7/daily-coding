/*
Problem Link: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/

Time Complexity: O(N)
Space Complexity: O(1)
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
    void flatten(TreeNode* root) {
        TreeNode* node = root;
        while(node) {
            if(node->left) {
                TreeNode* prev = node->left;
                while(prev->right) {
                    prev = prev->right;
                }
                prev->right = node->right;
                node->right = node->left;
                node->left = NULL;
            }
            node = node->right;
        }
    }
};