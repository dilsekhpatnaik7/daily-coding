/*
Problem Link: https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1

Time Complexity: O(V+E)
Space Complexity: O(V+E)
*/

class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<int> adj[N];
        for(auto i: edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        
        vector<int> dist(N, 1e9);
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
        
        for(int i = 0; i < N; i++) {
            if(dist[i] == 1e9) dist[i] = -1;
        }
        
        return dist;
    }
};