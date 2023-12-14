/*
Problem Link: https://www.codingninjas.com/studio/problems/single-source-shortest-path_8416371?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(V+E)
Space Complexity: O(V+E)
*/

vector<int> shortestPath(int n, vector<vector<int>>&edges, int src) {
    vector<int> adj[n];
    for(auto i: edges) {
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);
    }
    
    vector<int> dist(n, 1e9);
    dist[src] = 0;
    queue<int> q;
    q.push(src);
    
    while(!q.empty()) {
        int node = q.front(); q.pop();
        
        for(auto adjacentNode: adj[node]) {
            if(dist[node] + 1 < dist[adjacentNode]) {
                dist[adjacentNode] = dist[node] + 1;
                q.push(adjacentNode);
            }
        }
    }
    
    for(int i = 0; i < n; i++) {
        if(dist[i] == 1e9) dist[i] = -1;
    }
    
    return dist;
}