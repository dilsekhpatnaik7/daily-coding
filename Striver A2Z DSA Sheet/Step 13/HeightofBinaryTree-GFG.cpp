/*
Problem Link: https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution{
    public:
    int solve(struct Node* root) {
        if(!root) return 0;
        
        return 1 + max(solve(root->left), solve(root->right));
    }
    
    int height(struct Node* node){
        return solve(node);
    }
};