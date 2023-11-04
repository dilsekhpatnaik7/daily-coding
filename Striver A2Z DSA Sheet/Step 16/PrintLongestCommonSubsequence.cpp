/*
Problem Link: https://www.codingninjas.com/studio/problems/print-longest-common-subsequence_8416383?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(N*M + N+M)
Space Complexity: O(N*M)
*/

#include<bits/stdc++.h>
int solve(int n, int m, string& s, string& t, vector<vector<int>>& dp) {
	for(int i = 0; i <= n; i++) {
		for(int j = 0; j <= m; j++) {
			if(i == 0 || j == 0) dp[i][j] = 0;
			else if(s[i - 1] == t[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	return dp[n][m];
}

string printLCS(int n, int m, int length, string &s, string &t, vector<vector<int>> &dp) {
    string ans = "";
	for(int i = 0; i < length; i++) ans += "$"; 

	int i = n, j = m, index = length - 1;
	while(i > 0 && j > 0) {
		if(s[i - 1] == t[j - 1]) {
			ans[index] = s[i - 1];
			index--, i--, j--;
		} else if(dp[i - 1][j] > dp[i][j - 1]) i--;
		else j--; 
	}
	return ans;
}

string findLCS(int n, int m,string &s1, string &s2) {
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
	int length = solve(n, m, s1, s2, dp);
	return printLCS(n, m, length, s1, s2, dp);
}