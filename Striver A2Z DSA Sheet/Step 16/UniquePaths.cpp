/*
Problem Link: https://leetcode.com/problems/unique-paths/description/

Time Complexity: O(PathLength + Recursive Stack Space)
Space Complexity: O(N)
*/

class Solution {
public:
    // Recursion + Memoization
    int solve(int i, int j, vector<vector<int>>& dp) {
        if(i == 0 && j == 0) return 1;
        if(i < 0 || j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        return dp[i][j] = solve(i - 1, j, dp) + solve(i, j - 1, dp);
    }

    // Tabulation
    int solve2(int m, int n, vector<vector<int>>& dp) {
        dp[0][0] = 1;
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m][n];
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));

        // Recursion + Memoization
	    return solve(m - 1, n - 1, dp);

        // Tabulation
        return solve2(m - 1, n - 1, dp);
    }
};