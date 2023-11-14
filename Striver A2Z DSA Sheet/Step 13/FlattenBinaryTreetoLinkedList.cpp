/*
Problem Link: https://www.codingninjas.com/studio/problems/flatten-binary-tree-to-linked-list_1112615?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(N)
Space Complexity: O(1)
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

void flattenBinaryTree(TreeNode<int>* root) {
    TreeNode<int>* node = root;
    while(node) {
        if(node->left) {
            TreeNode<int>* prev = node->left;
            while(prev->right) {
                prev = prev->right;
            }
            prev->right = node->right;
            node->right = node->left;
            node->left = NULL;
        }
        node = node->right;
    }
}