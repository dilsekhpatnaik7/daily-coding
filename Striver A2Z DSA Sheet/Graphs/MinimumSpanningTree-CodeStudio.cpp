/*
Problem Link: https://www.codingninjas.com/studio/problems/minimum-spanning-tree_631769?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(E*log(V))
Space Complexity: O(N)
*/

#include<bits/stdc++.h>
int minimumSpanningTree(vector<vector<int>>& edges, int n) {
  vector<pair<int, int>> adj[n];
  for(auto i: edges) {
    adj[i[0]].push_back({i[1], i[2]});
    adj[i[1]].push_back({i[0], i[2]});
  }

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
  q.push({0, 0});
  vector<int> vis(n, 0);
  int sum = 0;
  
  while(!q.empty()) {
    int distance = q.top().first;
    int node = q.top().second;
    q.pop();
    
    if(vis[node]) continue;
    
    vis[node] = 1;
    sum += distance;
    
    for(auto i: adj[node]) {
      int adjacentNode = i.first;
      int weight = i.second;
      if(!vis[adjacentNode]) {
        q.push({weight, adjacentNode});
      }
    }
  }
  return sum;
}