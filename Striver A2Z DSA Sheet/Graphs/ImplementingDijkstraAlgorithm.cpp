/*
Problem Link: https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

Time Complexity: O(V*log(E))
Space Complexity: O(N)
*/

class Solution {
	public:
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(V, 1e9);
        dist[S] = 0;
        
        pq.push({0, S});
        while(!pq.empty()) {
            int distance = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto it: adj[node]) {
                int adjacentNode = it[0];
                int edgeWeight = it[1];
                
                if(distance + edgeWeight < dist[adjacentNode]) {
                    dist[adjacentNode] = distance + edgeWeight;
                    pq.push({dist[adjacentNode], adjacentNode});
                }
            }
        }
        
        return dist;
    }
};