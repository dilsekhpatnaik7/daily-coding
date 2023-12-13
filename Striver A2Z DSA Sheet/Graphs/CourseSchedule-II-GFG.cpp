/*
Problem Link: https://www.geeksforgeeks.org/problems/course-schedule/1

Time Complexity: O(V+E)
Space Complexity: O(V+E)
*/

class Solution {
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) {
        vector<int> adj[n];
	    for(auto i: prerequisites) {
	        adj[i[1]].push_back(i[0]);
	    }
	    
	    vector<int> indegree(n, 0);
	    for(int i = 0; i < n; i++) {
	        for(auto adjacentNode: adj[i]) {
	            indegree[adjacentNode]++;
	        }
	    }
	    
	    queue<int> q;
	    for(int i = 0; i < n; i++) {
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
	    
	    return ans.size() == n ? ans : vector<int>{};
    }
};