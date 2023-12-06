/*
Problem Link: https://leetcode.com/problems/all-elements-in-two-binary-search-trees/description/

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

    vector<int> merge(vector<int>& first, vector<int>& second) {
        vector<int> ans;
        int n = first.size(), m = second.size();
        int i = 0, j = 0;
        while(i < n && j < m) {
            if(first[i] <= second[j]) ans.push_back(first[i++]);
            else ans.push_back(second[j++]);
        }

        while(i < n) {
            ans.push_back(first[i++]);
        }
        while(j < m) {
            ans.push_back(second[j++]);
        }

        return ans;
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> first, second;
        inorder(root1, first);
        inorder(root2, second);

        return merge(first, second);
    }
};