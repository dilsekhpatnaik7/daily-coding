/*
Problem Link: https://www.codingninjas.com/studio/problems/postorder-traversal_2035933?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

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
    TreeNode* node = root;

    stack<TreeNode*> s1, s2;
    s1.push(root);

    while(!s1.empty()) {
        node = s1.top();
        s1.pop();
        s2.push(node);

        if(node->left) s1.push(node->left);
        if(node->right) s1.push(node->right);
    }

    while(!s2.empty()) {
        ans.push_back(s2.top()->data);
        s2.pop();
    }
}

vector<int> postorderTraversal(TreeNode *root) {
    if(!root) return {};

    vector<int> ans;
    solve(root, ans);
    return ans;
}