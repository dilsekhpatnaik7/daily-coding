/*
Problem Link: https://practice.geeksforgeeks.org/problems/children-sum-parent/1

Time Complexity: O(N)
Space Complexity: O(Height of Tree)
*/

class Solution{
    public:
    int solve(Node* root) {
        if(!root) return 1;
        if(!root->left && !root->right) return 1;
        
        int sum = 0;
        if(root->right) sum += root->right->data;
        if(root->left) sum += root->left->data;
        
        return sum == root->data && solve(root->left) && solve(root->right);
    }
    
    int isSumProperty(Node *root) {
        if(!root) return 1;
        
        return solve(root);
    }
};