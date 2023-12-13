/*
Problem Link: https://www.geeksforgeeks.org/problems/eventual-safe-states/1

Time Complexity: O(N*M)
Space Complexity: O(N*M)
*/

class Solution {
  public:
    bool dfs(int node, vector<int> adj[], vector<int>& vis, vector<int>& pathVis, vector<int>& check) {
        vis[node] = 1;
        pathVis[node] = 1;
        check[node] = 0;
        
        for(auto adjacentNode: adj[node]) {
            if(!vis[adjacentNode] && dfs(adjacentNode, adj, vis, pathVis, check)) {
                return true;
            } else if(pathVis[adjacentNode]) {
                return true;
            }
        }
        
        check[node] = 1;
        pathVis[node] = 0;
        return false;
    }
  
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        if(!V) return {};
        
        vector<int> vis(V, 0);
        vector<int> pathVis(V, 0);
        vector<int> check(V, 0);
        vector<int> safeNodes;
        
        for(int i = 0; i < V; i++) {
            if(!vis[i]) dfs(i, adj, vis, pathVis, check);
        }
        
        for(int i = 0; i < V; i++) {
            if(check[i] == 1) safeNodes.push_back(i);
        }
        return safeNodes;
    }
};