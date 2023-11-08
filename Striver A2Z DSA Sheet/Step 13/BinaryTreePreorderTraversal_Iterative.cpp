/*
Problem Link: https://leetcode.com/problems/binary-tree-preorder-traversal/description/

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
        s.push(root);

        while(!s.empty()) {
            TreeNode* node = s.top();
            s.pop();

            ans.push_back(node->val);
            if(node->right) s.push(node->right);
            if(node->left) s.push(node->left);
        }
    }

    vector<int> preorderTraversal(TreeNode* root) {
        if(!root) return {};

        vector<int> ans;
        solve(root, ans);
        return ans;
    }
};