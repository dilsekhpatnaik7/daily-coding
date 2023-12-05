/*
Problem Link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/

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
    TreeNode* solve(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, map<int, int>& m) {
        if(preStart > preEnd || inStart >inEnd) return NULL;

        TreeNode* root = new TreeNode(preorder[preStart]);
        int inRoot = m[root->val];
        int numsLeft = inRoot - inStart;

        root->left = solve(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inRoot - 1, m);
        root->right = solve(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot + 1, inEnd, m);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> m;
        for(int i = 0; i < inorder.size(); i++) {
            m[inorder[i]] = i;
        }
        TreeNode* root = solve(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, m);
        return root;
    }
};