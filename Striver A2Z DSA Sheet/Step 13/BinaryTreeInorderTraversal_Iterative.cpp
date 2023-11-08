/*
Problem Link: https://leetcode.com/problems/binary-tree-inorder-traversal/description/

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
    void solve(TreeNode* root, vector<int>& ans) {
        stack<TreeNode*> s;
        TreeNode* node = root;

        while(true) {
            if(node) {
                s.push(node);
                node = node->left;
            } else {
                if(s.empty()) break;
                node = s.top();
                s.pop();

                ans.push_back(node->val);
                node = node->right;
            }
        }
    }

    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return {};

        vector<int> ans;
        solve(root, ans);
        return ans;
    }
};