// Problem Link: https://leetcode.com/problems/check-completeness-of-a-binary-tree/
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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        bool gotNullSoFar = false;
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if(!node) {
                gotNullSoFar = true;
            }
            else {
                if(gotNullSoFar == true) return false;
                q.push(node->left);
                q.push(node->right);
            }
        }
        return true;
    }
};