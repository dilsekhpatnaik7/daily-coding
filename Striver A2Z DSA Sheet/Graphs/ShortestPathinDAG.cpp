/*
Problem Link: https://www.codingninjas.com/studio/problems/shortest-path-in-dag_8381897?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(V+E)
Space Complexity: O(V+E)
*/

void topoSort(int node, vector<pair<int, int>> adj[], vector<int>& vis, stack<int>& s) {
    vis[node] = 1;
    
    for(auto adjacentNode: adj[node]) {
        int v = adjacentNode.first;
        if(!vis[v]) topoSort(v, adj, vis, s);
    }
    
    s.push(node);
}

vector<int> shortestPathInDAG(int n, int m, vector<vector<int>> &edges) {
    vector<pair<int, int>> adj[n];
    for(int i = 0; i < m; i++) {
        int u = edges[i][0], v = edges[i][1], wt = edges[i][2];
        adj[u].push_back({v, wt});
    }
    
    vector<int> vis(n, 0);
    stack<int> s;
    for(int i = 0; i < n; i++) {
        if(!vis[i]) topoSort(i, adj, vis, s);
    }
    
    vector<int> dist(n, 1e9);
    dist[0] = 0;
    
    while(!s.empty()) {
        int node = s.top(); s.pop();
        
        for(auto adjacentNode: adj[node]) {
            int v = adjacentNode.first;
            int wt = adjacentNode.second;
            
            if(dist[node] + wt < dist[v]) dist[v] = dist[node] + wt;
        }
    }
    
    for(int i = 0; i < n; i++) {
        if(dist[i] == 1e9) dist[i] = -1;
    }
    
    return dist;
}