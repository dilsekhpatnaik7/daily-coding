/*
Problem Link: https://www.geeksforgeeks.org/problems/negative-weight-cycle3504/1

Time Complexity: O(N*E)
Space Complexity: O(N)
*/

class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    vector<int> dist(n, 1e8);
        dist[0] = 0;
        
        for(int i = 0; i < n; i++) {
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
            
            if(dist[u] + wt < dist[v]) return 1;
        }
        return 0;
	}
};