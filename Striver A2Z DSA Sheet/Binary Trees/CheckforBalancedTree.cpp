/*
Problem Link: https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution{
    public:
    int solve(Node* root) {
        if(!root) return 0;
    
        int leftHeight = solve(root->left);
        if(leftHeight == -1) return -1;
    
        int rightHeight = solve(root->right);
        if(rightHeight == -1) return -1;
    
        if(abs(leftHeight - rightHeight) > 1) return -1;
    
        return 1 + max(leftHeight, rightHeight);
    }
    
    bool isBalanced(Node *root) {
        return solve(root) != -1;
    }
};