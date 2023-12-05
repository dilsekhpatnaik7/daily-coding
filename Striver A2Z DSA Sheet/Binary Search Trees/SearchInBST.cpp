/*
Problem Link: https://www.codingninjas.com/studio/problems/search-in-bst_1402878?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(log(N))
Space Complexity: O(N)
*/

/*
    Following is the Binary Tree node structure:

    template <typename T>
    class BinaryTreeNode
    {
    public:
        T data;
        BinaryTreeNode<T> *left, *right;
        BinaryTreeNode() : data(0), left(NULL), right(NULL) {}
        BinaryTreeNode(T x) : data(x), left(NULL), right(NULL) {}
        BinaryTreeNode(T x, BinaryTreeNode<T> *left, BinaryTreeNode<T> *right) : data(x), left(left), right(right) {}
    };

*/
BinaryTreeNode<int>* solve(BinaryTreeNode<int>* root, int x) {
    if(!root || root->data == x) return root;

    if(x < root->data) return solve(root->left, x);
    else return solve(root->right, x);
}

bool searchInBST(BinaryTreeNode<int> *root, int x) {
    BinaryTreeNode<int>* ans = solve(root, x);
    return ans && ans->data == x;
}