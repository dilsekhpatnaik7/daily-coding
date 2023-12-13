/*
Problem Link: https://practice.geeksforgeeks.org/problems/eventual-safe-states/1

Time Complexity: O(V+E)
Space Complexity: O(V+E)
*/

class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int> adjRev[V];
        vector<int> indegree(V, 0);
        for(int i = 0; i < V; i++) {
            for(auto adjacentNode: adj[i]) {
                adjRev[adjacentNode].push_back(i);
                indegree[i]++;
            }
        }
        
        queue<int> q;
        vector<int> safeNodes;
        
        for(int i = 0; i < V; i++) {
            if(indegree[i] == 0) q.push(i);
        }
        
        while(!q.empty()) {
            int node = q.front(); q.pop();
            safeNodes.push_back(node);
            
            for(auto adjacentNode: adjRev[node]) {
                indegree[adjacentNode]--;
                if(indegree[adjacentNode] == 0) q.push(adjacentNode);
            }
        }
    
        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};