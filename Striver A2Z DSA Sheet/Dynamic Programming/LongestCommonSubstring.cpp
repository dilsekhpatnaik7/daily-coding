/*
Problem Link: https://www.codingninjas.com/studio/problems/longest-common-substring_1235207?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(N*M)
Space Complexity: O(N*M)
*/

#include<bits/stdc++.h>
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

int lcs(string &str1, string &str2) {
    int n = str1.size(), m = str2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    return solve(n, m, str1, str2, dp);
}