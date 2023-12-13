/*
Problem Link: https://www.codingninjas.com/studio/problems/detect-cycle-in-a-directed-graph_1062626?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(V+E)
Space Complexity: O(N)
*/

#include<bits/stdc++.h>
void adjacencyList(vector<pair<int, int>>& edges, vector<int> adj[]) {
  for(int i = 0; i < edges.size(); i++) {
    int u = edges[i].first, v = edges[i].second;
    adj[u].push_back(v);
  }
}

int detectCycleInDirectedGraph(int n, vector<pair<int,int>> & edges) {
  vector<int> adj[n + 1];
  adjacencyList(edges, adj);

  vector<int> indegree(n + 1, 0);
  for(int i = 1; i <= n; i++) {
    for(auto adjacentNode: adj[i]) {
      indegree[adjacentNode]++;
    }
  }
  
  queue<int> q;
  for(int i = 1; i <= n; i++) {
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
  
  return !(count == n);
}