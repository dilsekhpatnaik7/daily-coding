/*
Problem Link: https://leetcode.com/problems/binary-tree-paths/description/

Time Complexity: O(N)
Space Complexity: O(Height of Tree)
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
    bool isLeaf(TreeNode* root) {
        return root && (!root->left && !root->right);
    }

    void solve(TreeNode* root, string s, vector<string>& ans) {
        if(!root) return;

        string t = to_string(root->val);
        if(isLeaf(root)) {
            ans.push_back(s + t);
            return;
        }

        if(root->left) solve(root->left, s + t + "->", ans);
        if(root->right) solve(root->right, s + t + "->", ans);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return {};

        vector<string> ans;
        solve(root, "", ans);
        return ans;
    }
};