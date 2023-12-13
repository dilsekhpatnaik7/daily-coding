/*
Problem Link: https://www.codingninjas.com/studio/problems/topological-sorting_973003?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(V+E)
Space Complexity: O(N)
*/

#include<bits/stdc++.h>
void adjacencyList(vector<vector<int>>& graph, vector<int> adj[]) {
    for(auto i: graph) {
        adj[i[0]].push_back(i[1]);
    }
}

vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int nodes) {
    vector<int> adj[nodes];
    adjacencyList(graph, adj);

    vector<int> indegree(nodes, 0);
    for(int i = 0; i < nodes; i++) {
        for(auto adjacentNode: adj[i]) {
            indegree[adjacentNode]++;
        }
    }
    
    queue<int> q;
    for(int i = 0; i < nodes; i++) {
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