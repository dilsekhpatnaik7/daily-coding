/*
Problem Link: https://www.geeksforgeeks.org/problems/merge-two-bst-s/1

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
    public:
    void inorder(Node* root, vector<int>& v) {
        if(!root) return;
    
        inorder(root->left, v);
        v.push_back(root->data);
        inorder(root->right, v);
    }
    
    vector<int> mergeBoth(vector<int>& first, vector<int>& second) {
        vector<int> ans;
        int n = first.size(), m = second.size();
        int i = 0, j = 0;
        while(i < n && j < m) {
            if(first[i] <= second[j]) ans.push_back(first[i++]);
            else ans.push_back(second[j++]);
        }
    
        while(i < n) {
            ans.push_back(first[i++]);
        }
        while(j < m) {
            ans.push_back(second[j++]);
        }
    
        return ans;
    }
    
    vector<int> merge(Node *root1, Node *root2) {
        vector<int> first, second;
        inorder(root1, first);
        inorder(root2, second);
    
        return mergeBoth(first, second);
    }
};