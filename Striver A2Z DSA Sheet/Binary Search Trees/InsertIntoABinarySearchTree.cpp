/*
Problem Link: https://www.codingninjas.com/studio/problems/insert-into-a-binary-search-tree_1279913?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(N)
Space Complexity: O(1)
*/

/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode
    {
    public:
        T val;
        TreeNode<T> *left, *right;
        TreeNode() : val(0), left(NULL), right(NULL) {}
        TreeNode(T x) : val(x), left(NULL), right(NULL) {}
        TreeNode(T x, TreeNode<T> *left, TreeNode<T> *right) : val(x), left(left), right(right) {}
    };


************************************************************/

TreeNode<int>* insertionInBST(TreeNode<int>* root, int val) {
    if(!root) return new TreeNode<int>(val);

    TreeNode<int>* node = root;
    while(true) {
        if(val >= node->val) {
            if(node->right) node = node->right;
            else {
                node->right = new TreeNode<int>(val);
                break;
            }
        } else {
            if(node->left) node = node->left;
            else {
                node->left = new TreeNode<int>(val);
                break;
            }
        }
    }
    return root;
}