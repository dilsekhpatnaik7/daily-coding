/*
Problem Link: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/

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
    void solve(TreeNode* root, vector<vector<int>>& ans) {
        queue<TreeNode*> q;
        q.push(root);
        bool flag = false;

        while(!q.empty()) {
            int size = q.size();
            vector<int> t;
            for(int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                t.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(flag) {
                reverse(t.begin(), t.end());
                flag = !flag;
            } else {
                flag = 1;
            }
            ans.push_back(t);
        }
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};

        vector<vector<int>> ans;
        solve(root, ans);
        return ans;
    }
};