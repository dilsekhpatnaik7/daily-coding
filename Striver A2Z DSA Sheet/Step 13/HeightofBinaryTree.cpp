/*
Problem Link: https://www.codingninjas.com/studio/problems/height-of-binary-tree_4609628?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

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
int solve(TreeNode<int>* &root) {
    if(!root) return 0;

    return 1 + max(solve(root->left), solve(root->right));
}

int heightOfBinaryTree(TreeNode<int> *root) {
    return solve(root);
}
