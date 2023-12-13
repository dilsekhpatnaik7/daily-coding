/*
Problem Link: https://leetcode.com/problems/find-eventual-safe-states/description/

Time Complexity: O(N*M)
Space Complexity: O(N*M)
*/

class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& vis, vector<int>& pathVis, vector<int>& check) {
        vis[node] = 1;
        pathVis[node] = 1;
        check[node] = 0;

        for(auto adjacentNode: graph[node]) {
            if(!vis[adjacentNode] && dfs(adjacentNode, graph, vis, pathVis, check)) return true;
            else if(pathVis[adjacentNode]) return true;
        }

        pathVis[node] = 0;
        check[node] = 1;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        if(!n) return {};

        vector<int> vis(n);
        vector<int> pathVis(n);
        vector<int> check(n);
        vector<int> safeNodes;

        for(int i = 0; i < n; i++) {
            if(!vis[i]) dfs(i, graph, vis, pathVis, check);
        }

        for(int i = 0; i < n; i++) {
            if(check[i]) safeNodes.push_back(i);
        }
        return safeNodes;
    }
};