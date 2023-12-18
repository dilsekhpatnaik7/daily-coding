/*
Problem Link: https://www.geeksforgeeks.org/problems/cheapest-flights-within-k-stops/1

Time Complexity: O(E)
Space Complexity: O(N)
*/

class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        vector<pair<int, int>> adj[n];
        for(auto i: flights) {
            adj[i[0]].push_back({i[1], i[2]});
        }
            
        vector<int> dist(n, 1e9);
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});
        dist[src] = 0;
        
        while(!q.empty()) {
            int stops = q.front().first;
            int node = q.front().second.first;
            int cost = q.front().second.second;
            q.pop();
            
            if(stops > K) continue;
            for(auto i: adj[node]) {
                int adjacentNode = i.first;
                int weight = i.second;
                
                if(cost + weight < dist[adjacentNode] && stops <= K) {
                    dist[adjacentNode] = cost + weight;
                    q.push({stops + 1, {adjacentNode, cost + weight}});
                }
            }
        }
        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};