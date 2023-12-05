/*
Problem Link: https://practice.geeksforgeeks.org/problems/right-view-of-binary-tree/1

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
    public:
    void solve(Node* root, int level, vector<int>& ans) {
        if(!root) return;
        if(ans.size() == level) ans.push_back(root->data);

        solve(root->right, level + 1, ans);
        solve(root->left, level + 1, ans);
    }
    
    vector<int> rightView(Node *root) {
        if(!root) return {};

        vector<int> ans;
        solve(root, 0, ans);
        return ans;
    }
};