/*
Problem Link: https://leetcode.com/problems/find-eventual-safe-states/

Time Complexity: O(V+E)
Space Complexity: O(V+E)
*/

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> adjRev[n];
        vector<int> indegree(n, 0);
        for(int i = 0; i < n; i++) {
            for(auto adjacentNode: graph[i]) {
                adjRev[adjacentNode].push_back(i);
                indegree[i]++;
            }
        }
        
        queue<int> q;
        vector<int> safeNodes;
        
        for(int i = 0; i < n; i++) {
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