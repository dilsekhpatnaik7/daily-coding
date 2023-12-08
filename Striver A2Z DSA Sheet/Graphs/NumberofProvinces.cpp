/*
Problem Link: https://www.geeksforgeeks.org/problems/number-of-provinces/1

Time Complexity: O(V+E)
Space Complexity: O(V)
*/

class Solution {
  public:
    void solve(vector<vector<int>>& adj, int i, vector<int>& vis) {
        vis[i] = 1;
        for(int j = 0; j < adj.size(); j++) {
            if(adj[i][j] && !vis[j]) solve(adj, j, vis);
        }
    }
  
    int numProvinces(vector<vector<int>> adj, int V) {
        if(!V) return 0;
        
        int provinces = 0;
        vector<int> vis(V);
        
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                solve(adj, i, vis);
                provinces++;
            }
        }
        return provinces;
    }
};