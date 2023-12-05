/*
Problem Link: https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/0

Time Complexity: O(N)
Space Complexity: O(N)
*/

/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T dat)
        {
            this->data = dat;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
bool solve(TreeNode<int>* p, TreeNode<int>* q) {
    if(!p || !q) return p == q;

    return p->data == q->data && solve(p->left, q->right) && solve(p->right, q->left);
}

bool isSymmetric(TreeNode<int> *root) {
    if(!root) return true;

    return solve(root->left, root->right);
}