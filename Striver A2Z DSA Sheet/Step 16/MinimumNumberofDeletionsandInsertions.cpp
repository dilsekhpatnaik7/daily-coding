/*
Problem Link: https://www.codingninjas.com/studio/problems/minimum-number-of-deletions-and-insertions_4244510?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(N*M)
Space Complexity: O(N*M)
*/

int solve(string& s, string& t) {
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

	for(int i = 0; i <= n; i++) {
		for(int j = 0; j <= m; j++) {
			if(i == 0 || j == 0) dp[i][j] = 0;
			else if(s[i - 1] == t[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	return dp[n][m];
}

int canYouMake(string &s1, string &s2){
    return s1.size() + s2.size() - 2 * solve(s1, s2);
}