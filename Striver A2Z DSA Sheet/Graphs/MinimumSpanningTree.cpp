/*
Problem Link: https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1

Time Complexity: O(NE*log(V))
Space Complexity: O(N)
*/

class Solution {
	public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, 0});
        vector<int> vis(V, 0);
        int sum = 0;
        
        while(!q.empty()) {
            int distance = q.top().first;
            int node = q.top().second;
            q.pop();
            
            if(vis[node]) continue;
            
            vis[node] = 1;
            sum += distance;
            
            for(auto i: adj[node]) {
                int adjacentNode = i[0];
                int weight = i[1];
                if(!vis[adjacentNode]) {
                    q.push({weight, adjacentNode});
                }
            }
        }
        return sum;
    }
};