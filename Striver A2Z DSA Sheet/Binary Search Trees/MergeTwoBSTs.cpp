/*
Problem Link: https://www.codingninjas.com/studio/problems/merge-two-bsts_920474?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(N)
Space Complexity: O(N)
*/

/*************************************************************

    Following is the Binary Tree node structure:

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
void inorder(TreeNode* root, vector<int>& v) {
    if(!root) return;

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

vector<int> merge(vector<int>& first, vector<int>& second) {
    vector<int> ans;
    int n = first.size(), m = second.size();
    int i = 0, j = 0;
    while(i < n && j < m) {
        if(first[i] <= second[j]) ans.push_back(first[i++]);
        else ans.push_back(second[j++]);
    }

    while(i < n) {
        ans.push_back(first[i++]);
    }
    while(j < m) {
        ans.push_back(second[j++]);
    }

    return ans;
}

vector<int> mergeBST(TreeNode *root1, TreeNode *root2) {
    vector<int> first, second;
    inorder(root1, first);
    inorder(root2, second);

    return merge(first, second);
}