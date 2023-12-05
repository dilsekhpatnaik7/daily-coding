/*
Problem Link: https://www.codingninjas.com/studio/problems/longest-common-subsequence_624879?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(N*M)
Space Complexity: O(N*M)
*/

#include<bits/stdc++.h>
int solve(int i, int j, string s, string t, vector<vector<int>>& dp) {
	if(i < 0 || j < 0) return 0;
	if(dp[i][j] != -1) return dp[i][j];

	if(s[i] == t[j]) return dp[i][j] = 1 + solve(i - 1, j - 1, s, t, dp);

	int shrinkFirst = solve(i - 1, j, s, t, dp);
	int shrinkSecond = solve(i, j - 1, s, t, dp);

	return dp[i][j] = max(shrinkFirst, shrinkSecond);
}

int lcs(string s, string t) {
	int m = s.size(), n = t.size();
	vector<vector<int>> dp(m, vector<int>(n, -1));
	return solve(m - 1, n - 1, s, t, dp);
}