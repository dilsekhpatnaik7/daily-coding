/*
Problem Link: https://www.codingninjas.com/studio/problems/maximum-sum-path-of-a-binary-tree._1214968?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(N)
Space Complexity: O(log(N))
*/

#include<bits/stdc++.h>
/************************************************************

    Following is the BinaryTreeNode class structure

    template <typename T>
    class BinaryTreeNode {
       public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
int solve(BinaryTreeNode<int>* root, int& maximum) {
    if(!root) return 0;

    int leftSum = max(0, solve(root->left, maximum));
    int rightSum = max(0, solve(root->right, maximum));

    maximum = max(maximum, leftSum + rightSum + root->data);
    return root->data + max(leftSum, rightSum);
}

int maxPathSum(BinaryTreeNode<int> *root) {
    int maximum = INT_MIN;
    solve(root, maximum);
    return maximum;
}