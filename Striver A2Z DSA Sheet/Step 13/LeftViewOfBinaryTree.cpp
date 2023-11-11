/*
Problem Link: https://www.codingninjas.com/studio/problems/left-view-of-binary-tree_625707?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(N)
Space Complexity: O(N)
*/

void solve(BinaryTreeNode<int>* root, int level, vector<int>& ans) {
    if(!root) return;
    if(ans.size() == level) ans.push_back(root->data);

    solve(root->left, level + 1, ans);
    solve(root->right, level + 1, ans);
}

vector<int> printLeftView(BinaryTreeNode<int>* root) {
    if(!root) return {};

    vector<int> ans;
    solve(root, 0, ans);
    return ans;
}