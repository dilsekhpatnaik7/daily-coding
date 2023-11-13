/*
Problem Link: https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/

Time Complexity: O(1)
Space Complexity: O(1)
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& m) {
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if(node->left) {
                m[node->left] = node;
                q.push(node->left);
            }
            if(node->right) {
                m[node->right] = node;
                q.push(node->right);
            }
        }
    }

    void solve(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& m, TreeNode* target, int k, vector<int>& ans) {
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        int currentLevel = 0;

        while(!q.empty()) {
            int size = q.size();
            if(currentLevel++ == k) break;

            for(int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                if(node->left && !visited[node->left]) {
                    q.push(node->left);
                    visited[node->left] = true;
                }
                if(node->right && !visited[node->right]) {
                    q.push(node->right);
                    visited[node->right] = true;
                }
                if(m[node] && !visited[m[node]]) {
                    q.push(m[node]);
                    visited[m[node]] = true;
                }
            }
        }

        while(!q.empty()) {
            TreeNode* node = q.front(); q.pop();
            ans.push_back(node->val);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(!root) return {};
     
        unordered_map<TreeNode*, TreeNode*> m;
        markParents(root, m);

        vector<int> ans;
        solve(root, m, target, k, ans);
        return ans;
    }
};