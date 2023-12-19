/*
Problem Link: https://practice.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/0?fbclid=IwAR2_lL0T84DnciLyzMTQuVTMBOi82nTWNLuXjUgahnrtBgkphKiYk6xcyJU

Time Complexity: O(V*E)
Space Complexity: O(N)
*/

class Solution {
  public:
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int> dist(V, 1e8);
        dist[S] = 0;
        
        for(int i = 0; i < V; i++) {
            for(auto it: edges) {
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                
                if(dist[u] != 1e8 && dist[u] + wt < dist[v]) dist[v] = dist[u] + wt; 
            }
        }
        
        for(auto i: edges) {
            int u = i[0];
            int v = i[1];
            int wt = i[2];
            
            if(dist[u] != 1e8 && dist[u] + wt < dist[v]) return {-1};
        }
        return dist;
    }
};