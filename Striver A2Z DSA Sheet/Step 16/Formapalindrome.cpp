/*
Problem Link: https://practice.geeksforgeeks.org/problems/form-a-palindrome1455/1

Time Complexity: O(N*M)
Space Complexity: O(N*M)
*/

class Solution{
  public:
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
  
    int countMin(string str) {
        int n = str.size();
    	string t = str;
    	reverse(t.begin(), t.end());
    
    	vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    	return n - solve(n, n, str, t, dp);
    }
};