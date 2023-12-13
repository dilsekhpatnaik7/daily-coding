/*
Problem Link: https://www.codingninjas.com/studio/problems/safe-nodes-in-the-graph_1376703?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(V+E)
Space Complexity: O(V+E)
*/

#include <bits/stdc++.h> 
void adjacencyList(vector<vector<int>>& edges, vector<int> adj[]) {
    for(auto i: edges) {
        adj[i[0]].push_back(i[1]);
    }
}

vector<int> safeNodes(vector<vector<int>> &edges, int n, int e) {
    vector<int> adj[n];
    vector<int> adjRev[n];
    vector<int> indegree(n, 0);
    adjacencyList(edges, adj);

    for(int i = 0; i < n; i++) {
        for(auto adjacentNode: adj[i]) {
            adjRev[adjacentNode].push_back(i);
            indegree[i]++;
        }
    }
    
    queue<int> q;
    vector<int> safeNodes;
    
    for(int i = 0; i < n; i++) {
        if(indegree[i] == 0) q.push(i);
    }
    
    while(!q.empty()) {
        int node = q.front(); q.pop();
        safeNodes.push_back(node);
        
        for(auto adjacentNode: adjRev[node]) {
            indegree[adjacentNode]--;
            if(indegree[adjacentNode] == 0) q.push(adjacentNode);
        }
    }
    
    sort(safeNodes.begin(), safeNodes.end());
    return safeNodes;
}