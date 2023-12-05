/*
Problem Link: https://practice.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
    public:
    bool solve(Node* p, Node* q) {
        if(!p || !q) return p == q;

        return (p->data == q->data) && solve(p->left, q->left) && solve(p->right, q->right);
    }
    
    bool isIdentical(Node *r1, Node *r2) {
        solve(r1, r2);
    }
};