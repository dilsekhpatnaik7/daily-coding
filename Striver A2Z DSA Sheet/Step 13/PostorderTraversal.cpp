/*
Problem Link: https://www.codingninjas.com/studio/problems/postorder-traversal_2035933?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

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
void solve(TreeNode* root, vector<int>& ans) {
    if(root == NULL) return;

    solve(root->left, ans);
    solve(root->right, ans);
    ans.push_back(root->data);
}

vector<int> postorderTraversal(TreeNode *root) {
    vector<int> ans;
    solve(root, ans);
    return ans;
}