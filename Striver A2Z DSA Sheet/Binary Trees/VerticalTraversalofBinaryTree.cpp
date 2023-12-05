/*
Problem Link: https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
    public:
    void solve(Node* root, vector<int>& ans) {
        map<int, map<int, vector<int>>> nodes;
        queue<pair<Node*, pair<int, int>>> q;
        q.push({root, {0, 0}});
    
        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            Node* node = p.first;
            int x = p.second.first, y = p.second.second;
            nodes[x][y].push_back(node->data);
            
            if(node->left) q.push({node->left, {x - 1, y + 1}});
            if(node->right) q.push({node->right, {x + 1, y + 1}});
        }
    
        for(const auto& it_x : nodes) {
            for(const auto& it_y : it_x.second) {
                for(const auto& value : it_y.second) {
                    ans.push_back(value);
                }
            }
        }
    }
    
    vector<int> verticalOrder(Node *root) {
        if(!root) return {};
        
        vector<int> ans;
        solve(root, ans);
        return ans;
    }
};