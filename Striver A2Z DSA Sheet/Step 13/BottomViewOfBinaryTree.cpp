/*
Problem Link: https://www.codingninjas.com/studio/problems/bottom-view-of-binary-tree_893110?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

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
    map<int, int> m;
    queue<pair<TreeNode<int>*, int>> q;
    q.push({root, 0});
    
    while(!q.empty()) {
        auto it = q.front();
        q.pop();
        
        TreeNode<int>* node = it.first;
        int line = it.second;
        m[line] = node->data;
        
        if(node->left) q.push({node->left, line - 1});
        if(node->right) q.push({node->right, line + 1});
    }
    for(auto i: m) {
        ans.push_back(i.second);
    }
}

vector<int> bottomView(TreeNode<int> * root){
    if(!root) return {};

    vector<int> ans;
    solve(root, ans);
    return ans;
}