/*
Problem Link: https://practice.geeksforgeeks.org/problems/maximum-path-sum-from-any-node/1

Time Complexity: O(N)
Space Complexity: O(log(N))
*/

class Solution {
  public:
     int solve(Node* root, int& maximum) {
        if(!root) return 0;

        int leftSum = max(0, solve(root->left, maximum));
        int rightSum = max(0, solve(root->right, maximum));

        maximum = max(maximum, leftSum + rightSum + root->data);
        return root->data + max(leftSum, rightSum);
    }
  
    int findMaxSum(Node* root) {
        int maximum = INT_MIN;
        solve(root, maximum);
        return maximum;
    }
};