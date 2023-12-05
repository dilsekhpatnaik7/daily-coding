/*
Problem Link: https://www.codingninjas.com/studio/problems/maximum-width-in-binary-tree_763671?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(N)
Space Complexity: O(Height of Tree)
*/

#include<bits/stdc++.h>
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
int solve(TreeNode<int>* root) {
    int ans = 0;
    queue<TreeNode<int>*> q;
    q.push(root);
    
    while(!q.empty()) {
        int size = q.size();
        ans = max(ans, size);
        
        for(int i = 0; i < size; i++) {
            TreeNode<int>* node = q.front();
            q.pop();
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
    }
    return ans;
}

int getMaxWidth(TreeNode<int> *root) {
    if(!root) return 0;
        
    return solve(root);
}