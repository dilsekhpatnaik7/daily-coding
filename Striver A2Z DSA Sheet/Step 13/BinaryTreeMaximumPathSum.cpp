/*
Problem Link: https://leetcode.com/problems/binary-tree-maximum-path-sum/description/

Time Complexity: O(N)
Space Complexity: O(log(N))
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
    int solve(TreeNode* root, int& maximum) {
        if(!root) return 0;

        int leftSum = max(0, solve(root->left, maximum));
        int rightSum = max(0, solve(root->right, maximum));

        maximum = max(maximum, leftSum + rightSum + root->val);
        return root->val + max(leftSum, rightSum);
    }

    int maxPathSum(TreeNode* root) {
        int maximum = INT_MIN;
        solve(root, maximum);
        return maximum;
    }
};