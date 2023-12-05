/*
Problem Link: https://practice.geeksforgeeks.org/problems/shortest-common-supersequence0322/1

Time Complexity: O(N*M)
Space Complexity: O(N*M)
*/

class Solution {
    public:
    int lcs(int n, int m, string& s, string& t, vector<vector<int>>& dp) {
    	for(int i = 0; i <= n; i++) {
    		for(int j = 0; j <= m; j++) {
    			if(i == 0 || j == 0) dp[i][j] = 0;
    			else if(s[i - 1] == t[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
    			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    		}
    	}
    	return dp[n][m];
    }
    
    int shortestCommonSupersequence(string X, string Y, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        return m + n - lcs(m, n, X, Y, dp);
    }
};