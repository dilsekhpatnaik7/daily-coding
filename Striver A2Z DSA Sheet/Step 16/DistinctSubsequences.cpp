/*
Problem Link: https://www.codingninjas.com/studio/problems/subsequence-counting_3755256?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(N*M)
Space Complexity: O(N*M)
*/

int mod = 1e9 + 7;
int solve(int i, int j, string &s, string &t, vector<vector<int>>& dp) {
	if(j < 0) return 1;
	if(i < 0) return 0;
	if(dp[i][j] != -1) return dp[i][j];

	if(s[i] == t[j]) return dp[i][j] = (solve(i - 1, j - 1, s, t, dp) + solve(i - 1, j, s, t, dp)) % mod;

	return dp[i][j] = solve(i - 1, j, s, t, dp);
}

int distinctSubsequences(string &str, string &sub) {
	int n = str.size(), m = sub.size();
	vector<vector<int>> dp(n, vector<int>(m, -1));
	return solve(n - 1, m - 1, str, sub, dp);
}