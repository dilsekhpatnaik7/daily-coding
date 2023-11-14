/*
Problem Link: https://www.codingninjas.com/studio/problems/inorder-traversal_3839605?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(N)
Space Complexity: O(1)
*/

#include<bits/stdc++.h>
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
vector<int> getInOrderTraversal(TreeNode *root) {
    if(!root) return {};

    vector<int> ans;
    TreeNode* node = root;
    while(node) {
        if(!node->left) {
            ans.push_back(node->data);
            node = node->right;
        } 
        else {
            TreeNode* prev = node->left;
            while(prev->right && prev->right != node) {
                prev = prev->right;
            }

            if(!prev->right) {
                prev->right = node;
                node = node->left;
            } else {
                prev->right = NULL;
                ans.push_back(node->data);
                node = node->right;
            }
        }
    }
    return ans;
}