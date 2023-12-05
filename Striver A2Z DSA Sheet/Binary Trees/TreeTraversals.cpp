/*
Problem Link: https://www.codingninjas.com/studio/problems/tree-traversal_981269?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

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
void solve(TreeNode* root, vector<vector<int>>& ans) {
    if(root == NULL) return;;

    ans[1].push_back(root->data);
    solve(root->left, ans);
    ans[0].push_back(root->data);
    solve(root->right, ans);
    ans[2].push_back(root->data);
}

vector<vector<int>> getTreeTraversal(TreeNode *root){
    vector<vector<int>> ans = {{}, {}, {}};
    solve(root, ans);
    return ans;
}