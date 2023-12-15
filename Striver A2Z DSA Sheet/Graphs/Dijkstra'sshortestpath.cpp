/*
Problem Link: https://www.codingninjas.com/studio/problems/dijkstra's-shortest-path_985358?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(V*log(E))
Space Complexity: O(N)
*/

void adjacencyList(vector<vector<int>> &edge, vector<pair<int, int>> adj[]) {
    for(int i = 0; i < edge.size(); i++) {
        int u = edge[i][0];
        int v = edge[i][1];
        int wt = edge[i][2];

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
}

vector<int> dijkstra(vector<vector<int>> &edge, int vertices, int edges, int source) {
    vector<pair<int, int>> adj[vertices];
    adjacencyList(edge, adj);

    vector<int> dist(vertices, 1e9);
    dist[source] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});

    while(!pq.empty()) {
        int distance = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        for(auto it: adj[node]) {
            int adjacentNode = it.first;
            int edgeWeight = it.second;
            
            if(distance + edgeWeight < dist[adjacentNode]) {
                dist[adjacentNode] = distance + edgeWeight;
                pq.push({dist[adjacentNode], adjacentNode});
            }
        }
    }
    
    return dist;
}