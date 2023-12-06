/*
Problem Link: https://www.codingninjas.com/studio/problems/predecessor-and-successor-in-bst_893049?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(log(N))
Space Complexity: O(1)
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
int getPre(TreeNode* root, int key) {
    TreeNode* predecessor = nullptr;
    while(root) {
        if(key > root->data) {
            predecessor = root;
            root = root->right;
        } else root = root->left;
    }
    return predecessor ? predecessor->data : -1;
}

int getSuc(TreeNode* root, int key) {
    TreeNode* successor = nullptr;
    while(root) {
        if(key >= root->data) root = root->right;
        else {
            successor = root;
            root = root->left;
        }
    }
    return successor ? successor->data : -1;
}

pair<int, int> predecessorSuccessor(TreeNode *root, int key) {
    return {getPre(root, key), getSuc(root, key)};
}