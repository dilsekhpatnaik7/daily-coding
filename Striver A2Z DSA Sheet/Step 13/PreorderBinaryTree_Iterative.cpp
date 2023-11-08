/*
Problem Link: https://www.codingninjas.com/studio/problems/preorder-binary-tree_5948?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(N)
Space Complexity: O(N)
*/

#include<bits/stdc++.h>
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

void solve(TreeNode<int>* root, vector<int>& ans) {
    stack<TreeNode<int>*> s;
    s.push(root);

    while(!s.empty()) {
        TreeNode<int>* node = s.top();
        s.pop();

        ans.push_back(node->data);
        if(node->right) s.push(node->right);
        if(node->left) s.push(node->left);
    }
}

vector<int> preOrder(TreeNode<int> * root){
    if(!root) return {};

    vector<int> ans;
    solve(root, ans);
    return ans;
}