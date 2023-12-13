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

void dfs(int node, vector<int> adj[], vector<int>& vis, stack<int>& s) {
    vis[node] = 1;
    
    for(auto adjacentNode: adj[node]) {
        if(!vis[adjacentNode]) dfs(adjacentNode, adj, vis, s);
    }
    
    s.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int nodes) {
    vector<int> adj[nodes];
    adjacencyList(graph, adj);

    vector<int> vis(nodes, 0);
    vector<int> ans;
    stack<int> s;

    for(int i = 0; i < nodes; i++) {
        if(!vis[i]) dfs(i, adj, vis, s);
    }

    while(!s.empty()) {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}