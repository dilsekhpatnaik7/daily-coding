/*
Problem Link: https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1

Time Complexity: O(N)
Space Complexity: O(Height of Tree)
*/

class Solution {
    public:
    Node* solve(Node* root, int p, int  q) {
        if(!root || root->data == p || root->data == q) return root;

        Node* left = solve(root->left, p, q);
        Node* right = solve(root->right, p, q);

        if(!left) return right;
        else if(!right) return left;
        else return root;
    } 
    
    Node* lca(Node* root, int n1, int n2) {
        if(!root) return root;
        
        return solve(root, n1, n2);
    }
};