/*
Problem Link: https://practice.geeksforgeeks.org/problems/inorder-traversal/1

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
public:
    void solve(Node* root, vector<int>& ans) {
        if(root == NULL) return;
        
        solve(root->left, ans);
        ans.push_back(root->data);
        solve(root->right, ans);
    }  
  
    vector<int> inOrder(Node* root) {
        vector<int> ans;
        solve(root, ans);
        return ans;
    }
};