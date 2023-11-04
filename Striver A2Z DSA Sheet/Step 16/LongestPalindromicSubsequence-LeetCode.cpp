/*
Problem Link: https://leetcode.com/problems/longest-palindromic-subsequence/description/

Time Complexity: O(N*M)
Space Complexity: O(N*M)
*/

class Solution {
public:
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

    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        return solve(n, m, s, t, dp);
    }
};