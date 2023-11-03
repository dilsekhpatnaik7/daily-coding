/*
Problem Link: https://leetcode.com/problems/longest-common-subsequence/description/

Time Complexity: O(N*M)
Space Complexity: O(N*M)
*/

class Solution {
public:
    // int solve(int i, int j, string s, string t, vector<vector<int>>& dp) {
    //     if(i < 0 || j < 0) return 0;
    //     if(dp[i][j] != -1) return dp[i][j];

    //     if(s[i] == t[j]) return dp[i][j] = 1 + solve(i - 1, j - 1, s, t, dp);

    //     int shrinkFirst = solve(i - 1, j, s, t, dp);
    //     int shrinkSecond = solve(i, j - 1, s, t, dp);

    //     return dp[i][j] = max(shrinkFirst, shrinkSecond);
    // }

    int solve(int n, int m, string s, string t, vector<vector<int>>& dp) {
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= m; j++) {
                if(i == 0 || j == 0) dp[i][j] = 0;
                else if(s[i - 1] == t[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n][m];
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        return solve(n, m, text1, text2, dp);
    }
};