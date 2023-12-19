/*
Problem Link: https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/

Time Complexity: O(N*E*log(V))
Space Complexity: O(N)
*/

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<pair<int, int>> adj[n];
        for(auto i: edges) {
            adj[i[0]].push_back({i[1], i[2]});
            adj[i[1]].push_back({i[0], i[2]});
        }

        int countCity = n, city = -1;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

        for(int i = 0; i < n; i++) {
            q.push({0, i});
            vector<int> dist(n, 1e9);
            dist[i] = 0;

            while(!q.empty()) {
                int distance = q.top().first;
                int node = q.top().second;
                q.pop();

                for(auto it: adj[node]) {
                    int weight = it.second;
                    int adjacentNode = it.first;
                    if(distance + weight < dist[adjacentNode]) {
                        dist[adjacentNode] = distance + weight;
                        q.push({distance + weight, adjacentNode});
                    }
                }
            }

            int count = 0;
            for(int j = 0; j < n; j++) {
                if(dist[j] <= distanceThreshold) count++;
            }
            if(count <= countCity) {
                countCity = count;
                city = i;
            }
        }
        return city;
    }
};