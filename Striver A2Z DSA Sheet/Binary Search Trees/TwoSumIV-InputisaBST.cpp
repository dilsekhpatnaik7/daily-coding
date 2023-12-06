/*
Problem Link: https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/

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
    void inorder(TreeNode* root, vector<int>& v) {
        if(!root) return;

        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> v;
        inorder(root, v);

        int start = 0, end = v.size() - 1;
        while(start < end) {
            if(v[start] + v[end] == k) return true;
            if(v[start] + v[end] > k) end--;
            else start++;
        }
        return false;
    }
};