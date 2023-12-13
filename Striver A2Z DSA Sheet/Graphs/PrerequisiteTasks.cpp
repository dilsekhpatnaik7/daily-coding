/*
Problem Link: https://www.geeksforgeeks.org/problems/prerequisite-tasks/1

Time Complexity: O(V+E)
Space Complexity: O(V+E)
*/

class Solution {
public:
	bool isPossible(int N,int P, vector<pair<int, int>>& prerequisites) {
	    vector<int> adj[N];
	    for(auto i: prerequisites) {
	        adj[i.second].push_back(i.first);
	    }
	    
	    vector<int> indegree(N, 0);
	    for(int i = 0; i < N; i++) {
	        for(auto adjacentNode: adj[i]) {
	            indegree[adjacentNode]++;
	        }
	    }
	    
	    queue<int> q;
	    for(int i = 0; i < N; i++) {
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
	    
	    return count == N;
	}
};