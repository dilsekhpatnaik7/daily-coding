/*
Problem Link: https://practice.geeksforgeeks.org/problems/topological-sort/1

Time Complexity: O(V+E)
Space Complexity: O(N)
*/

class Solution {
	public:
	vector<int> topoSort(int V, vector<int> adj[]) {
	    vector<int> indegree(V, 0);
	    for(int i = 0; i < V; i++) {
	        for(auto adjacentNode: adj[i]) {
	            indegree[adjacentNode]++;
	        }
	    }
	    
	    queue<int> q;
	    for(int i = 0; i < V; i++) {
	        if(indegree[i] == 0) q.push(i);
	    }
	    
	    vector<int> ans;
	    while(!q.empty()) {
	        int node = q.front(); q.pop();
	        ans.push_back(node);
	        
	        for(auto adjacentNode: adj[node]) {
	            indegree[adjacentNode]--;
	            if(indegree[adjacentNode] == 0) q.push(adjacentNode);
	        }
	    }
	    
	    return ans;
	}
};