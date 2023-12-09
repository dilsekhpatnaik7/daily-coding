/*
Problem Link: https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

Time Complexity: O(V+2E)
Space Complexity: O(V)
*/

class Solution {
  public:
    bool dfs(int node, int parent, vector<int> adj[], int vis[]) {
        vis[node] = 1;
        
        for(auto adjacentNode: adj[node]) {
            if(!vis[adjacentNode]) {
                if(dfs(adjacentNode, node, adj, vis)) return true;
            } else if(adjacentNode != parent) return true;
        }
        return false;
    }
  
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V] = {0};
        
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                if(dfs(i, -1, adj, vis)) return true;
            }
        }
        return false;
    }
};