/*
Problem Link: https://www.codingninjas.com/studio/problems/delete-node-in-bst_920381?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(log(N))
Space Complexity: O(N)
*/

/*************************************************************
    Following is the Binary Tree node structure

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

*************************************************************/
BinaryTreeNode<int>* findLastRight(BinaryTreeNode<int>* root) {
    while(root->right) root = root->right;
    return root;
}

BinaryTreeNode<int>* solve(BinaryTreeNode<int>* root) {
    if(!root->left) return root->right;
    if(!root->right) return root->left;

    BinaryTreeNode<int>* rightChild = root->right;
    BinaryTreeNode<int>* lastRight = findLastRight(root->left);
    lastRight->right = rightChild;
    
    return root->left;
}

BinaryTreeNode<int>* deleteNode(BinaryTreeNode<int>* root, int key) {
    if(!root) return root;

    if(root->data == key) return solve(root);
    BinaryTreeNode<int>* node = root;
    while(root) {
        if(key > root->data) {
            if(root->right && root->right->data == key) {
                root->right = solve(root->right);
                break;
            } else root = root->right;
        } else {
            if(root->left && root->left->data == key) {
                root->left = solve(root->left);
                break;
            } else root = root->left;
        }
    }
    return node;
}