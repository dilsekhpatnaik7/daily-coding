/*
Problem Link: https://leetcode.com/problems/number-of-provinces/description/

Time Complexity: O(N + 2E)
Space Complexity: O(N)
*/

class Solution {
public:
    void solve(int node, vector<int> adj[], vector<int>& vis) {
        vis[node] = 1;
        for(auto i: adj[node]) {
            if(!vis[i]) solve(i, adj, vis);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        if(!n) return 0;

        vector<int> adj[n];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(isConnected[i][j] && i != j) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<int> vis(n);
        int provinces = 0;
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                solve(i, adj, vis);
                provinces++;
            }
        }
        return provinces;
    }
};