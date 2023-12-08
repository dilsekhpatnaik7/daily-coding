/*
Problem Link: https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

Time Complexity: O(N + 2E)
Space Complexity: O(N)
*/

class Solution {
  public:
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        if(!V) return {};
         
        vector<int> vis(V);
        vis[0] = 1;
        vector<int> bfs;
        queue<int> q;
        q.push(0);
        
        while(!q.empty()) {
            int node = q.front(); q.pop();
            
            bfs.push_back(node);
            for(auto it: adj[node]) {
                if(!vis[it]) {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        return bfs;
    }
};