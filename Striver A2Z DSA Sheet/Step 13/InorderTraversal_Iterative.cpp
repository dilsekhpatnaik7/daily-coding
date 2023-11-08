/*
Problem Link: https://www.codingninjas.com/studio/problems/inorder-traversal_3839605?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(N)
Space Complexity: O(N)
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
void solve(TreeNode* root, vector<int>& ans) {
    stack<TreeNode*> s;
    TreeNode* node = root;

    while(true) {
        if(node) {
            s.push(node);
            node = node->left;
        } else {
            if(s.empty()) break;
            node = s.top();
            s.pop();

            ans.push_back(node->data);
            node = node->right;
        }
    }
}

vector<int> getInOrderTraversal(TreeNode *root) {
    if(!root) return {};

    vector<int> ans;
    solve(root, ans);
    return ans;
}