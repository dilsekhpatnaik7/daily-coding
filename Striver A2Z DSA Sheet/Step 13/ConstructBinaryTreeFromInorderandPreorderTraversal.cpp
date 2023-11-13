/*
Problem Link: https://www.codingninjas.com/studio/problems/construct-binary-tree-from-inorder-and-preorder-traversal_920539?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(N)
Space Complexity: O(N)
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
TreeNode<int>* solve(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, map<int, int>& m) {
    if(preStart > preEnd || inStart >inEnd) return NULL;

    TreeNode<int>* root = new TreeNode<int>(preorder[preStart]);
    int inRoot = m[root->data];
    int numsLeft = inRoot - inStart;

    root->left = solve(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inRoot - 1, m);
    root->right = solve(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot + 1, inEnd, m);

    return root;
}

TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder) {
     map<int, int> m;
    for(int i = 0; i < inorder.size(); i++) {
        m[inorder[i]] = i;
    }
    TreeNode<int>* root = solve(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, m);
    return root;
}