/*
Problem Link: https://www.codingninjas.com/studio/problems/lca-of-binary-tree_920541?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(N)
Space Complexity: O(Height of Tree)
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
int solve(TreeNode<int>* root, int p, int q) {
    if(!root) return -1;
    if(root->data == p || root->data == q) return root->data;

    int left = solve(root->left, p, q);
    int right = solve(root->right, p, q);

    if(left == -1) return right;
    else if(right == -1) return left;
    else return root->data;
} 

int lowestCommonAncestor(TreeNode<int> *root, int x, int y) {
    if(!root) return -1;

    return solve(root, x, y);
}