/*
Problem Link: https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

Time Complexity: O(N + 2E)
Space Complexity: O(N)
*/

class Solution {
  public:
    void solve(int node, vector<int> adj[], vector<int>& vis, vector<int>& dfs) {
        vis[node] = 1;
        dfs.push_back(node);
        
        for(auto i: adj[node]) {
            if(!vis[i]) solve(i, adj, vis, dfs);
        }
    }
  
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        if(!V) return {};
        
        vector<int> vis(V);
        vector<int> dfs;
        solve(0, adj, vis, dfs);
        
        return dfs;
    }
};