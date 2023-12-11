/*
Problem Link: https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

Time Complexity: O(N*M)
Space Complexity: O(N*M)
*/

class Solution {
  public:
    bool dfs(int node, vector<int> adj[], vector<int>& vis, vector<int>& pathVis) {
        vis[node] = 1;
        pathVis[node] = 1;
        
        for(auto adjacentNode: adj[node]) {
            if(!vis[adjacentNode]) {
                if(dfs(adjacentNode, adj, vis, pathVis)) return true;
            } else if(pathVis[adjacentNode]) return true;
        }
        
        pathVis[node] = 0;
        return false;
    }
  
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        vector<int> pathVis(V, 0);
        
        for(int i = 0; i < V; i++) {
            if(!vis[i] && dfs(i, adj, vis, pathVis)) return true;
        }
        return false;
    }
};