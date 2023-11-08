/*
Problem Link: https://practice.geeksforgeeks.org/problems/preorder-traversal/1

Time Complexity: O(N)
Space Complexity: O(N)
*/

void solve(Node* root, vector<int>& ans) {
    if(root == NULL) return;

    ans.push_back(root->data);
    solve(root->left, ans);
    solve(root->right, ans);
}

vector<int> preorder(Node* root) {
    vector<int> ans;
    solve(root, ans);
    return ans;
}