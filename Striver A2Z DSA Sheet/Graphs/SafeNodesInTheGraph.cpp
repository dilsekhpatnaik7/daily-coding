/*
Problem Link: https://www.codingninjas.com/studio/problems/safe-nodes-in-the-graph_1376703?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(N*M)
Space Complexity: O(N*M)
*/

#include <bits/stdc++.h> 
void adjacencyList(vector<vector<int>>& edges, vector<int> adj[]) {
    for(auto i: edges) {
        adj[i[0]].push_back(i[1]);
    }
}

bool dfs(int node, vector<int> adj[], vector<int>& vis, vector<int>& pathVis, vector<int>& check) {
    vis[node] = 1;
    pathVis[node] = 1;
    check[node] = 0;
    
    for(auto adjacentNode: adj[node]) {
        if(!vis[adjacentNode] && dfs(adjacentNode, adj, vis, pathVis, check)) {
            return true;
        } else if(pathVis[adjacentNode]) {
            return true;
        }
    }
    
    check[node] = 1;
    pathVis[node] = 0;
    return false;
}

vector<int> safeNodes(vector<vector<int>> &edges, int n, int e) {
    vector<int> adj[n];
    vector<int> vis(n);
    vector<int> pathVis(n);
    vector<int> check(n);
    vector<int> safeNodes;

    adjacencyList(edges, adj);
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            dfs(i, adj, vis, pathVis, check);
        }
    }

    for(int i = 0; i < n; i++) {
        if(check[i]) safeNodes.push_back(i);
    }
    return safeNodes;
}