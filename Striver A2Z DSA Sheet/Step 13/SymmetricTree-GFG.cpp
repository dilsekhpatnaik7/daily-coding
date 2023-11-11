/*
Problem Link: https://practice.geeksforgeeks.org/problems/symmetric-tree/1

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution{
    public:
    bool solve(Node* p, Node* q) {
        if(!p || !q) return p == q;

        return p->data == q->data && solve(p->left, q->right) && solve(p->right, q->left);
    }
    
    bool isSymmetric(struct Node* root) {
        if(!root) return true;

        return solve(root->left, root->right);
    }
};