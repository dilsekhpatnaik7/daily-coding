/*
Problem Link: https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

Time Complexity: O(V+E)
Space Complexity: O(N)
*/

class Solution {
  public:
    bool isCyclic(int V, vector<int> adj[]) {
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
	    
	    int count = 0;
	    while(!q.empty()) {
	        int node = q.front(); q.pop();
	        count++;
	        
	        for(auto adjacentNode: adj[node]) {
	            indegree[adjacentNode]--;
	            if(indegree[adjacentNode] == 0) q.push(adjacentNode);
	        }
	    }
	    
	    return !(count == V);
    }
};