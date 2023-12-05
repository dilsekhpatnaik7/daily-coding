/*
Problem Link: https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1

Time Complexity: O(N*M)
Space Complexity: O(N*M)
*/

class Solution{
	public:
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
	
	int minOperations(string str1, string str2) {
	    return str1.size() + str2.size() - 2 * solve(str1, str2);
	} 
};