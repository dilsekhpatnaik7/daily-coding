/*
Problem Link: https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1

Time Complexity: O(N*M)
Space Complexity: O(N*M)
*/

class Solution{
    public:
    int solve(int n, int m, string& s, string& t, vector<vector<int>>& dp) {
        int ans = 0;
    
    	for(int i = 0; i <= n; i++) {
    		for(int j = 0; j <= m; j++) {
    			if(i == 0 || j == 0) dp[i][j] = 0;
    			else if(s[i - 1] == t[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    ans = max(ans, dp[i][j]);
                } else dp[i][j] = 0;
    		}
    	}
    	return ans;
    }
    
    int longestCommonSubstr (string S1, string S2, int n, int m) {
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        return solve(n, m, S1, S2, dp);
    }
};