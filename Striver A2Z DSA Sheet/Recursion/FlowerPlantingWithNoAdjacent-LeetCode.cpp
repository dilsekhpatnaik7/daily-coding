/*
Problem Link: https://leetcode.com/problems/flower-planting-with-no-adjacent/description/

Time Complexity: O(N^2)
Space Complexity: O(N)
*/

class Solution {
public:
    bool solve(int currentColor, int totalVertex, int currVertex, vector<int>& color, vector<vector<int>>& adj) {
        if (currVertex == totalVertex) return true;
        
        for (int i = 1; i <= currentColor; ++i) {
            if (isSafe(i, currVertex, color, adj)) {
                color[currVertex] = i;
                if (solve(currentColor, totalVertex, currVertex + 1, color, adj)) {
                    return true;
                }
                color[currVertex] = 0;
            }
        }
        return false;
    }

    bool isSafe(int currentColor, int currVertex, vector<int>& color, vector<vector<int>>& adj) {
        for (int neighbour : adj[currVertex]) {
            if (currentColor == color[neighbour]) return false;
        }
        return true;
    }

    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> adj(n);
        vector<int> color(n);

        for (int i = 0; i < paths.size(); ++i) {
            adj[paths[i][0] - 1].push_back(paths[i][1] - 1);
            adj[paths[i][1] - 1].push_back(paths[i][0] - 1);
        }
        solve(4, n, 0, color, adj);
        return color;
    }
};