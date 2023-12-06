/*
Problem Link: https://www.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/1

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution{
    public:
        Node* solve(Node* root, int n1, int n2) {
            if(!root) return root;
    
            int value = root->data;
            if(n1 < value && n2 < value) return solve(root->left, n1, n2);
            else if(n1 > value && n2 > value) return solve(root->right, n1, n2);
            else return root;
        }
        
        Node* LCA(Node *root, int n1, int n2) {
            return solve(root, n1, n2);
        }

};