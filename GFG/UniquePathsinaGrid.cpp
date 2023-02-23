// Problem Link: https://practice.geeksforgeeks.org/problems/96161dfced02d544fc70c71d09b7a616fe726085/1
// GFG I'd: https://auth.geeksforgeeks.org/user/dilsekhpatnaik7

class Solution {
  public:
    int uniquePaths(int n, int m, vector<vector<int>> &grid) {
        vector<vector<int>> dp(n, vector<int> (m));
        dp[0][0] = grid[0][0] == 1 ? 1 : 0;
        for(int i = 1; i < n; i++) {
            dp[i][0] = grid[i][0] == 1 ? dp[i-1][0] : 0;
        }
        for(int j = 1; j < m; j++) {
            dp[0][j] = grid[0][j] == 1 ? dp[0][j-1] : 0;
        }
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                if (grid[i][j] == 1) {
                    dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % 1000000007;
                }
            }
        }
        return dp[n-1][m-1];
    }
};