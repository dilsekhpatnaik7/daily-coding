/*
Problem Link: https://leetcode.com/problems/is-graph-bipartite/description/

Time Complexity: O(N*M)
Space Complexity: O(N*M)
*/

class Solution {
public:
    bool bfs(int start, int col, vector<vector<int>>& graph, vector<int>& color) {
        color[start] = col;

        queue<int> q;
        q.push(start);
        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(auto adjacentNode: graph[node]) {
                if(color[adjacentNode] == -1) {
                    color[adjacentNode] = !color[node];
                    q.push(adjacentNode);
                } else if(color[node] == color[adjacentNode]) return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        for(int i = 0; i < n; i++) {
            if(color[i] == -1 && !bfs(i, 0, graph, color)) return false; 
        }
        return true;
    }
};