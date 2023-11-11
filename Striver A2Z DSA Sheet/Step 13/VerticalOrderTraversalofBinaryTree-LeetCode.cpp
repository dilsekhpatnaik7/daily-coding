/*
Problem Link: https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/

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
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});

        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            TreeNode* node = p.first;
            int x = p.second.first, y = p.second.second;
            nodes[x][y].insert(node->val);
            
            if(node->left) q.push({node->left, {x - 1, y + 1}});
            if(node->right) q.push({node->right, {x + 1, y + 1}});
        }

        for(auto p: nodes) {
            vector<int> col;
            for(auto qq: p.second) {
                col.insert(col.end(), qq.second.begin(), qq.second.end());
            }
            ans.push_back(col);
        }
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root) return {};
        
        vector<vector<int>> ans;
        solve(root, ans);
        return ans;
    }
};