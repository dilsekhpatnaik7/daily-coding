/*
Problem Link: https://www.codingninjas.com/studio/problems/preorder-binary-tree_5948?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(N)
Space Complexity: O(1)
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
vector<int> preOrder(TreeNode<int> * root){
    if(!root) return {};

    vector<int> ans;
    TreeNode<int>* node = root;
    while(node) {
        if(!node->left) {
            ans.push_back(node->data);
            node = node->right;
        } 
        else {
            TreeNode<int>* prev = node->left;
            while(prev->right && prev->right != node) {
                prev = prev->right;
            }

            if(!prev->right) {
                prev->right = node;
                ans.push_back(node->data);
                node = node->left;
            } else {
                prev->right = NULL;
                node = node->right;
            }
        }
    }
    return ans;
}