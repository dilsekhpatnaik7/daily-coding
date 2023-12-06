/*
Problem Link: https://www.codingninjas.com/studio/problems/fix-bst_873137?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(N)
Space Complexity: O(N)
*/

/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
void inorder(TreeNode* root, TreeNode*& first, TreeNode*& second, TreeNode*& prev) {
    if(!root) return;
    inorder(root->left, first, second, prev);

    if(prev && root->data < prev->data) {
        if(!first) {
            first = prev;
            second = root;
        } else second = root;
    }
    prev = root;
    inorder(root->right, first, second, prev);
}

TreeNode* FixBST(TreeNode * root){
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* prev = nullptr;
    
    inorder(root, first, second, prev);
    swap(first->data, second->data);

    return root;
}