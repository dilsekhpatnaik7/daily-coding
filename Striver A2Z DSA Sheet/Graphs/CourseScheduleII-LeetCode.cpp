/*
Problem Link: https://leetcode.com/problems/course-schedule-ii/description/

Time Complexity: O(V+E)
Space Complexity: O(V+E)
*/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
	    for(auto i: prerequisites) {
	        adj[i[1]].push_back(i[0]);
	    }
	    
	    vector<int> indegree(numCourses, 0);
	    for(int i = 0; i < numCourses; i++) {
	        for(auto adjacentNode: adj[i]) {
	            indegree[adjacentNode]++;
	        }
	    }
	    
	    queue<int> q;
	    for(int i = 0; i < numCourses; i++) {
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
	    
	    return ans.size() == numCourses ? ans : vector<int>{};
    }
};