/*
Problem Link: https://practice.geeksforgeeks.org/problems/level-order-traversal/1

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
    public:
    void solve(Node* &root, vector<int>& ans) {
        queue<Node*> q;
        q.push(root);
    
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0 ; i < size; i++) {
                Node* node = q.front();
                q.pop();
    
                if(node) {
                    ans.push_back(node->data);
                    if(node->left) q.push(node->left);
                    if(node->right) q.push(node->right);
                }
            }
        }
    }
    
    vector<int> levelOrder(Node* node) {
        if(!node) return {};

        vector<int> ans;
        solve(node, ans);
        return ans;
    }
};