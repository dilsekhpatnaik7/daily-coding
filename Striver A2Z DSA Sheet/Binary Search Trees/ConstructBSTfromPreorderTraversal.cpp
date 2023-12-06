/*
Problem Link: https://www.codingninjas.com/studio/problems/construct-bst-from-preorder-traversal_2689307?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(N)
Space Complexity: O(N)
*/

/*************************************************************

    Following is the Binary Tree node structure
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*************************************************************/
TreeNode *solve(vector<int> &preorder, int &i, int bound) {
    if (i == preorder.size() || preorder[i] > bound)
    return nullptr;

    TreeNode *root = new TreeNode(preorder[i++]);
    root->left = solve(preorder, i, root->data);
    root->right = solve(preorder, i, bound);

    return root;
}

TreeNode *preOrderTree(vector<int> &preOrder) {
    int i = 0;
    return solve(preOrder, i, INT_MAX);
}