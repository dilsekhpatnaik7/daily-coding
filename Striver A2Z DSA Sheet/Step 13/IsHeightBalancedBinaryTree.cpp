/*
Problem Link: https://www.codingninjas.com/studio/problems/is-height-balanced-binary-tree_975497?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(N)
Space Complexity: O(N)
*/

/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode
    {
    public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val)
        {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
int solve(TreeNode<int>* root) {
    if(!root) return 0;

    int leftHeight = solve(root->left);
    if(leftHeight == -1) return -1;

    int rightHeight = solve(root->right);
    if(rightHeight == -1) return -1;

    if(abs(leftHeight - rightHeight) > 1) return -1;

    return 1 + max(leftHeight, rightHeight);
}

bool isBalancedBT(TreeNode<int>* root){
    return solve(root) != -1;
}