/*
Problem Link: https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/0

Time Complexity: O(N)
Space Complexity: O(N)
*/

void solve(Node* root, int level, vector<int>& ans) {
    if(!root) return;
    if(ans.size() == level) ans.push_back(root->data);

    solve(root->left, level + 1, ans);
    solve(root->right, level + 1, ans);
}

vector<int> leftView(Node *root) {
    if(!root) return {};

    vector<int> ans;
    solve(root, 0, ans);
    return ans;
}