/*
Problem Link: https://www.geeksforgeeks.org/problems/number-of-provinces/1

Time Complexity: O(N + 2E)
Space Complexity: O(N)
*/

class Solution {
  public:
    void solve(int node, vector<int> adjLs[], vector<int>& vis) {
        vis[node] = 1;
        for(auto i: adjLs[node]) {
            if(!vis[i]) solve(i, adjLs, vis);
        }
    }
  
    int numProvinces(vector<vector<int>> adj, int V) {
        if(!V) return 0;
        
        vector<int> adjLs[V];
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                if(adj[i][j] && i != j) {
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }
        
        vector<int> vis(V);
        int provinces = 0;
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                solve(i, adjLs, vis);
                provinces++;
            }
        }
        return provinces;
    }
};