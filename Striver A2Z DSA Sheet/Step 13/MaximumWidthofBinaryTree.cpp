/*
Problem Link: https://leetcode.com/problems/maximum-width-of-binary-tree/description/

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
    int solve(TreeNode* root) {
        int ans = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while(!q.empty()) {
            int size = q.size();
            int minimum = q.front().second;
            int first, last;
            for(int i = 0; i < size; i++) {
                long long current = q.front().second - minimum;
                TreeNode* node = q.front().first;
                q.pop();

                if(i == 0) first = current;
                if(i == size - 1) last = current;
                if(node->left) q.push({node->left, current*2+1});
                if(node->right) q.push({node->right, current*2+2});
            }
            ans = max(ans, last - first + 1);
        } 
        return ans;
    }

    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;

        return solve(root);
    }
};