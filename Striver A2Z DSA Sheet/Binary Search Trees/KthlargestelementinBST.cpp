/*
Problem Link: https://www.geeksforgeeks.org/problems/kth-largest-element-in-bst/1

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
    public:
    void solve(Node* root, int k, int& count, int& ans) {
        if(!root) return;

        solve(root->right, k, count, ans);
        count++;
        if(count == k) {
            ans = root->data;
            return;
        }
        solve(root->left, k, count, ans);
    }
    
    int kthLargest(Node *root, int K) {
        int count = 0, ans = -1;
        solve(root, K, count, ans);
        return ans;
    }
};