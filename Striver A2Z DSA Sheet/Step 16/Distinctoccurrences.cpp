/*
Problem Link: https://practice.geeksforgeeks.org/problems/distinct-occurrences/1

Time Complexity: O(N*M)
Space Complexity: O(N*M)
*/

class Solution {
    public:
    int mod = 1e9 + 7;
    int solve(int i, int j, string &s, string &t, vector<vector<int>>& dp) {
        if(j < 0) return 1;
        if(i < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == t[j]) return dp[i][j] = (solve(i - 1, j - 1, s, t, dp) + solve(i - 1, j, s, t, dp)) % mod;

        return dp[i][j] = solve(i - 1, j, s, t, dp);
    }
    
    int subsequenceCount(string S, string T) {
        int n = S.size(), m = T.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(n - 1, m - 1, S, T, dp);
    }
};