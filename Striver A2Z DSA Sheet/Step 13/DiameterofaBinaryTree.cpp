/*
Problem Link: https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
  public:
    int solve(Node* root, int& diameter) {
        if(!root) return 0;

        int leftHeight = solve(root->left, diameter);
        int rightHeight = solve(root->right, diameter);
        diameter = max(diameter, leftHeight + rightHeight + 1);

        return 1 + max(leftHeight, rightHeight);
    }
  
    int diameter(Node* root) {
        int diameter = 0;
        solve(root, diameter);
        return diameter;
    }
};