/*
Problem Link: https://www.codingninjas.com/studio/problems/course-schedule-ii_1069243?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(V+E)
Space Complexity: O(V+E)
*/

#include<bits/stdc++.h>
vector<int> findSchedule(int numCourses, vector<pair<int, int>> &prerequisites) {
    vector<int> adj[numCourses + 1];
    for(auto i: prerequisites) {
        adj[i.second].push_back(i.first);
    }
    
    vector<int> indegree(numCourses + 1, 0);
    for(int i = 1; i <= numCourses; i++) {
        for(auto adjacentNode: adj[i]) {
            indegree[adjacentNode]++;
        }
    }
    
    queue<int> q;
    for(int i = 1; i <= numCourses; i++) {
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