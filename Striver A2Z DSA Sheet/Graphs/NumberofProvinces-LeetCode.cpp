/*
Problem Link: https://leetcode.com/problems/number-of-provinces/description/

Time Complexity: O(V+E)
Space Complexity: O(V)
*/

class Solution {
public:
    void solve(vector<vector<int>>& isConnected, int i, vector<int>& vis) {
        vis[i] = 1;
        for(int j = 0; j < isConnected.size(); j++) {
            if(isConnected[i][j] && !vis[j]) solve(isConnected, j, vis);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        if(!n) return 0;

        int provinces = 0;
        vector<int> vis(n);
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                solve(isConnected, i, vis);
                provinces++;
            }
        }
        return provinces;
    }
};