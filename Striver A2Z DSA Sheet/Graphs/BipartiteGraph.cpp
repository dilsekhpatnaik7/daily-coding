/*
Problem Link: https://practice.geeksforgeeks.org/problems/bipartite-graph/1

Time Complexity: O(N*M)
Space Complexity: O(N*M)
*/

class Solution {
public:
    bool dfs(int node, int color, vector<int>adj[], vector<int>& vis) {
        vis[node] = color;
        
        for(auto adjacentNode: adj[node]) {
            if(vis[adjacentNode] == -1) {
                if(!dfs(adjacentNode, !color, adj, vis)) return false;
            } else if(vis[node] == vis[adjacentNode]) return false;
        }
        return true;
    }

	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> vis(V, -1);
	    for(int i = 0; i < V; i++) {
	        if(vis[i] == -1) {
	            if(!dfs(i, 0, adj, vis)) return false;
	        }
	    }
	    return true;
	}
};