/*
Problem Link: https://www.geeksforgeeks.org/problems/find-a-pair-with-given-target-in-bst/1

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution{
  public:
    bool solve(Node* root, int k, unordered_map<int, int>& m) {
        if(!root) return false;
        if(m.count(k - root->data)) return true;
    
        m[root->data]++;
        return solve(root->left, k, m) || solve(root->right, k, m);
    }
    
    int isPairPresent(struct Node *root, int target) {
        unordered_map<int, int> m;
        return solve(root, target, m);
    }
};