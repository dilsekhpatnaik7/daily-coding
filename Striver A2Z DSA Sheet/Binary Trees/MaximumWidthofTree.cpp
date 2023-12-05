/*
Problem Link: https://practice.geeksforgeeks.org/problems/maximum-width-of-tree/1

Time Complexity: O(N)
Space Complexity: O(Height of Tree)
*/

class Solution {
  public:
    int solve(Node* root) {
        int ans = 0;
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()) {
            int size = q.size();
            ans = max(ans, size);
            
            for(int i = 0; i < size; i++) {
                Node* node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return ans;
    }
  
    int getMaxWidth(Node* root) {
        if(!root) return 0;
        
        return solve(root);
    }
};