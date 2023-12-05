/*
Problem Link: https://www.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1

Time Complexity: O(log(N))
Space Complexity: O(N)
*/

class Solution {
  public:
    void solve(Node* root, int k, int& count, int& ans) {
        if(!root) return;

        solve(root->left, k, count, ans);
        count++;
        if(count == k) {
            ans = root->data;
            return;
        }
        solve(root->right, k, count, ans);
    }
  
    int KthSmallestElement(Node *root, int K) {
        int count = 0, ans = -1;
        solve(root, K, count, ans);
        return ans;
    }
};