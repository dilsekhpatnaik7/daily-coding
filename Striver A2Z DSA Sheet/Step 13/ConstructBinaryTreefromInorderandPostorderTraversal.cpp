/*
Problem Link: https://www.codingninjas.com/studio/problems/construct-binary-tree-from-inorder-and-postorder-traversal_1266106?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(N)
Space Complexity: O(N)
*/

#include<bits/stdc++.h>
/************************************************************
   
   Following is the TreeNode class structure
   
   class TreeNode<T>
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
  		{ 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };
   
   
 ************************************************************/
TreeNode<int>* solve(vector<int>& inorder, int is, int ie, vector<int>& postorder, int ps, int pe, map<int, int>& m) {
     if(is > ie || ps > pe) return nullptr;

     TreeNode<int>* root = new TreeNode<int>(postorder[pe]);
     int inRoot = m[postorder[pe]];
     int numsLeft = inRoot - is;

     root->left = solve(inorder, is, inRoot - 1, postorder, ps, ps + numsLeft - 1, m);
     root->right = solve(inorder, inRoot + 1, ie, postorder, ps + numsLeft, pe - 1, m);

     return root;
}

TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder){
	if(inOrder.size() != postOrder.size()) return nullptr;

     map<int, int> m;
     for(int i = 0; i < inOrder.size(); i++) {
          m[inOrder[i]] = i;
     }
     return solve(inOrder, 0, inOrder.size() - 1, postOrder, 0, postOrder.size() - 1, m);
}