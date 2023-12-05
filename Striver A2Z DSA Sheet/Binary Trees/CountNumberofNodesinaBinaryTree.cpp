/*
Problem Link: https://practice.geeksforgeeks.org/problems/count-number-of-nodes-in-a-binary-tree/1

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
  public:
    int solve(Node* root) {
        if(root == NULL) return 0;
        if(root != NULL) {
            return 1 + solve(root->left) + solve(root->right);
        }
    }
  
    int countNodes(Node* root) {
        return solve(root);
    }
};