/*
Problem Link: https://www.codingninjas.com/studio/problems/longest-palindromic-subsequence_842787?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(N*M)
Space Complexity: O(N*M)
*/

#include <bits/stdc++.h> 
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

int longestPalindromeSubsequence(string s) {
    string t = s;
    reverse(t.begin(), t.end());
    
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    return solve(n, m, s, t, dp);
}