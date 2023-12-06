/*
Problem Link: https://www.codingninjas.com/studio/problems/check-bst_5975?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(N)
Space Complexity: O(N)
*/

#include<bits/stdc++.h>
/**********************************************************
	Following is the Binary Tree Node class structure

	template <typename T>
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

***********************************************************/
bool solve(BinaryTreeNode<int>* root, long long minVal, long long maxVal) {
	if(!root) return true;
	if(root->data >= maxVal || root->data <= minVal) return false;

	return solve(root->left, minVal, root->data) && solve(root->right, root->data, maxVal);
}

bool isBST(BinaryTreeNode<int> *root) {
	return solve(root, LONG_MIN, LONG_MAX);
}