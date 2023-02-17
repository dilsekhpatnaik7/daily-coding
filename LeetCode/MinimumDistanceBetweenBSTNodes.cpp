// Problem Link: https://leetcode.com/problems/minimum-distance-between-bst-nodes/
// Leetcode I'd: https://leetcode.com/dilsekhpatnaik7/

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
    vector<int> ans;
    void inorder(TreeNode* root) {
        if(!root) return;
        if(root->left) inorder(root->left);
        ans.push_back(root->val);
        if(root->right) inorder(root->right);
    }
    int minDiffInBST(TreeNode* root) {
        inorder(root);
        int k = INT_MAX;
        for(int i = 1; i < ans.size(); i++) {
            k = min(k, ans[i] - ans[i - 1]);
        }
        return k;
    }
};