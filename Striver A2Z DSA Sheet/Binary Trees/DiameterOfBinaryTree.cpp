/*
Problem Link: https://www.codingninjas.com/studio/problems/diameter-of-binary-tree_920552?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(N)
Space Complexity: O(N)
*/

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
int solve(TreeNode<int>* root, int& diameter) {
    if(!root) return 0;

    int leftHeight = solve(root->left, diameter);
    int rightHeight = solve(root->right, diameter);
    diameter = max(diameter, leftHeight + rightHeight);

    return 1 + max(leftHeight, rightHeight);
}

int diameterOfBinaryTree(TreeNode<int> *root){
	int diameter = 0;
    solve(root, diameter);
    return diameter;
}