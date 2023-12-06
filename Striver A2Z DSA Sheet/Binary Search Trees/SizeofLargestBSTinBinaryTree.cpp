/*
Problem Link: https://www.codingninjas.com/studio/problems/size-of-largest-bst-in-binary-tree_893103?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

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
class BST {
public:
    int maxNode, minNode, maxSize;
    BST(int maxNode, int minNode, int maxSize) {
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->maxSize = maxSize;
    }
};

BST solve(TreeNode* root) {
    if(!root) return BST(INT_MIN, INT_MAX, 0);

    auto left = solve(root->left);
    auto right = solve(root->right);

    int currentMin = min({root->data, left.minNode});
    int currentMax = max({root->data, right.maxNode});
    int currentMaxSize = left.maxSize + right.maxSize + 1;

    if(root->data > left.maxNode && root->data < right.minNode) {
        return BST(currentMax, currentMin, currentMaxSize);
    }

    return BST(INT_MAX, INT_MIN, max(left.maxSize, right.maxSize));
}

int largestBST(TreeNode* root) {
    return solve(root).maxSize;
}