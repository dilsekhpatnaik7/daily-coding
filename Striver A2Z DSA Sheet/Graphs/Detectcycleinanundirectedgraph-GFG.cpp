/*
Problem Link: https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

Time Complexity: O(V+E)
Space Complexity: O(V)
*/

class Solution {
  public:
    bool bfs(int src, vector<int> adj[], int vis[]) {
        vis[src] = 1;
        queue<pair<int, int>> q;
        q.push({src, -1});
        
        while(!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for(auto adjacentNode: adj[node]) {
                if(!vis[adjacentNode]) {
                    vis[adjacentNode] = 1;
                    q.push({adjacentNode, node});
                } else if(adjacentNode != parent){
                    return true;
                }
            }
        }
        return false;
    }
  
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V] = {0};
        
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                if(bfs(i, adj, vis)) return true;
            }
        }
        return false;
    }
};