/*
Problem Link: https://www.codingninjas.com/studio/problems/pair-sum-in-bst._920493?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(N)
Space Complexity: O(N)
*/

#include<bits/stdc++.h>
/**********************************************************
    Following is the Binary Tree Node structure:

    class BinaryTreeNode
    {
    public:
        int data;
        BinaryTreeNode *left, *right;
        BinaryTreeNode() : data(0), left(NULL), right(NULL) {}
        BinaryTreeNode(int x) : data(x), left(NULL), right(NULL) {}
        BinaryTreeNode(int x, BinaryTreeNode *left, BinaryTreeNode *right) : data(x), left(left), right(right) {}
    };
***********************************************************/
bool solve(BinaryTreeNode* root, int k, unordered_map<int, int>& m) {
    if(!root) return false;
    if(m.count(k - root->data)) return true;

    m[root->data]++;
    return solve(root->left, k, m) || solve(root->right, k, m);
}

bool pairSumBst(BinaryTreeNode *root, int k) {
    unordered_map<int, int> m;
    return solve(root, k, m);
}