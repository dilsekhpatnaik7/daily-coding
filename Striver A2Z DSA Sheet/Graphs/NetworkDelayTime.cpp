/*
Problem Link: https://www.codingninjas.com/studio/problems/network-delay-time_1382215?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(E*log(V))
Space Complexity: O(N)
*/

#include<bits/stdc++.h>
int networkDelayTime(vector<vector<int>> &edges, int n, int k) {
    vector<pair<int, int>> adj[n + 1];
    for(auto i: edges) {
        adj[i[0]].push_back({i[1], i[2]});
    }
    vector<int> dist(n + 1, 1e9);
    dist[k] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, k});

    while(!q.empty()) {
        int distance = q.top().first;
        int node = q.top().second;
        q.pop();

        for(auto i: adj[node]) {
            int adjacentNode = i.first;
            int nextDistance = i.second;
            if(distance + nextDistance < dist[adjacentNode]) {
                dist[adjacentNode] = distance + nextDistance;
                q.push({distance + nextDistance, adjacentNode});
            }
        }
    }

    int ans = INT_MIN;
    for(int i = 1; i <= n; i++) {
        if(dist[i] == 1e9) return -1;
        ans = max(ans, dist[i]);
    }
    return ans;
}