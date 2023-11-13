/*
Problem Link: https://www.codingninjas.com/studio/problems/nodes-in-complete-binary-tree_1281151?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(1)
Space Complexity: O(1)
*/

#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
int findLeftHeight(BinaryTreeNode<int>* root) {
    int height = 0;
    while(root) {
        height++;
        root = root->left;
    }
    return height;
}

int findRightHeight(BinaryTreeNode<int>* root) {
    int height = 0;
    while(root) {
        height++;
        root = root->right;
    }
    return height;
}

int solve(BinaryTreeNode<int>* root) {
    if(!root) return 0;

    int leftHeight = findLeftHeight(root);
    int rightHeight = findRightHeight(root);

    if(leftHeight == rightHeight) return (1 << leftHeight) - 1;
    return 1 + solve(root->left) + solve(root->right);
}

int countNodes(BinaryTreeNode<int> *root) {
    if(!root) return 0;

    return solve(root);
}