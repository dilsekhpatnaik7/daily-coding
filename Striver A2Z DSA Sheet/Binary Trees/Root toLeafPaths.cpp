/*
Problem Link: https://practice.geeksforgeeks.org/problems/root-to-leaf-paths/1

Time Complexity: O(N)
Space Complexity: O(Height of Tree)
*/

bool isLeaf(Node* root) {
    return root && (!root->left && !root->right);
}

void solve(Node* root, vector<int> t, vector<vector<int>>& ans) {
    if(!root) return;
    
    t.push_back(root->data);
    if(isLeaf(root)) {
        ans.push_back(t);
        return;
    }

    if(root->left) solve(root->left, t, ans);
    if(root->right) solve(root->right, t, ans);
    
    t.pop_back();
} 

vector<vector<int>> Paths(Node* root) {
    if(!root) return {};
    
    vector<int> t;
    vector<vector<int>> ans;
    solve(root, t, ans);
    
    return ans;
}