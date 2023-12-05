/*
Problem Link: https://www.codingninjas.com/studio/problems/time-to-burn-tree_1469067?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(1)
Space Complexity: O(1)
*/

#include<bits/stdc++.h>
/************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) 
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
BinaryTreeNode<int>* markParents(BinaryTreeNode<int>* root, map<BinaryTreeNode<int>*, BinaryTreeNode<int>*>& m, int start) {
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    BinaryTreeNode<int>* res = nullptr;

    while(!q.empty()) {
        BinaryTreeNode<int>* node = q.front();
        if(node->data == start) res = node;
        q.pop();
        if(node->left) {
            m[node->left] = node;
            q.push(node->left);
        }
        if(node->right) {
            m[node->right] = node;
            q.push(node->right);
        }
    }
    return res;
}

int solve(BinaryTreeNode<int>* root, map<BinaryTreeNode<int>*, BinaryTreeNode<int>*>& m, BinaryTreeNode<int>* target) {
    queue<BinaryTreeNode<int>*> q;
    q.push(target);

    map<BinaryTreeNode<int>*, int> vis;
    vis[target] = 1;
    int ans = 0;

    while(!q.empty()) {
        int size = q.size();
        int flag = 0;
        for(int i = 0; i < size; i++) {
            BinaryTreeNode<int>* node = q.front(); q.pop();
            if(node->left && !vis[node->left]) {
                flag = 1;
                vis[node->left] = 1;
                q.push(node->left);
            }
            if(node->right && !vis[node->right]) {
                flag = 1;
                vis[node->right] = 1;
                q.push(node->right);
            }
            if(m[node] && !vis[m[node]]) {
                flag = 1;
                vis[m[node]] = 1;
                q.push(m[node]);
            }
        }
        if(flag) ans++;
    }
    return ans;
}

int timeToBurnTree(BinaryTreeNode<int>* root, int start) {
    if(!root) return 0;

    map<BinaryTreeNode<int>*, BinaryTreeNode<int>*> m;
    BinaryTreeNode<int>* target = markParents(root, m, start);
    if(!target) return 0;

    return solve(root, m, target);
}