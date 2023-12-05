/*
Problem Link: https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
    public:
    void solve(Node* root, vector<int>& ans) {
        map<int, int> m;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            
            Node* node = it.first;
            int line = it.second;
            if(m.find(line) == m.end()) m[line] = node->data;
            
            if(node->left) q.push({node->left, line - 1});
            if(node->right) q.push({node->right, line + 1});
        }
        for(auto i: m) {
            ans.push_back(i.second);
        }
    }
    
    vector<int> topView(Node *root) {
        if(!root) return {};
        
        vector<int> ans;
        solve(root, ans);
        return ans;
    }

};