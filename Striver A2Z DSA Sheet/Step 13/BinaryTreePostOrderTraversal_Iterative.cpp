/*
Problem Link: https://leetcode.com/problems/binary-tree-postorder-traversal/description/

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
        TreeNode* node = root;

        stack<TreeNode*> s1, s2;
        s1.push(root);

        while(!s1.empty()) {
            node = s1.top();
            s1.pop();
            s2.push(node);

            if(node->left) s1.push(node->left);
            if(node->right) s1.push(node->right);
        }

        while(!s2.empty()) {
            ans.push_back(s2.top()->val);
            s2.pop();
        }
    }

    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return {};

        vector<int> ans;
        solve(root, ans);
        return ans;
    }
};