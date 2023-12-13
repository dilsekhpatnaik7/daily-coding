/*
Problem Link: https://practice.geeksforgeeks.org/problems/topological-sort/1

Time Complexity: O(V+E)
Space Complexity: O(N)
*/

class Solution {
	public:
	void dfs(int node, vector<int> adj[], vector<int>& vis, stack<int>& s) {
	    vis[node] = 1;
	    
	    for(auto adjacentNode: adj[node]) {
	        if(!vis[adjacentNode]) dfs(adjacentNode, adj, vis, s);
	    }
	    
	    s.push(node);
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) {
	    vector<int> vis(V, 0);
	    stack<int> s;
	    vector<int> ans;
	    
	    for(int i = 0; i < V; i++) {
	        if(!vis[i]) dfs(i, adj, vis, s);
	    }
	    
	    while(!s.empty()) {
	        ans.push_back(s.top());
	        s.pop();
	    }
	    return ans;
	}
};