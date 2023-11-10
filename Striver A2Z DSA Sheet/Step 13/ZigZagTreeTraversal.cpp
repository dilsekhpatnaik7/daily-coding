/*
Problem Link: https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution{
    public:
    void solve(Node* root, vector<int>& ans) {
        queue<Node*> q;
        stack<int> s;
        bool flag = false;
        q.push(root);
        
        while(!q.empty()) {
            int size = q.size();
            
            for(int i = 0; i < size; i++) {
                Node* node = q.front();
                q.pop();
                
                if(flag) s.push(node->data);
                else ans.push_back(node->data);
                
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(flag) {
                while(!s.empty()) {
                    ans.push_back(s.top());
                    s.pop();
                }
            }
            flag = !flag;
        }
        
    }
    
    vector<int> zigZagTraversal(Node* root) {
        if(!root) return {};
        
        vector<int> ans;
        solve(root, ans);
        return ans;
    }
};