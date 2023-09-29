/*
Problem Link: https://www.codingninjas.com/studio/problems/unique-paths_1081470?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

Time Complexity: O(PathLength + Recursive Stack Space)
Space Complexity: O(N)
*/

#include <bits/stdc++.h> 
int solve(int i, int j, vector<vector<int>>& dp) {
	if(i == 0 && j == 0) return 1;
	if(i < 0 || j < 0) return 0;
	if(dp[i][j] != -1) return dp[i][j];

	return dp[i][j] = solve(i - 1, j, dp) + solve(i, j - 1, dp);
}

int uniquePaths(int m, int n) {
	vector<vector<int>> dp(m, vector<int>(n, -1));
	return solve(m - 1, n - 1, dp);
}