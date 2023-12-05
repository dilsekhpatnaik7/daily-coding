/*
Problem Link: https://practice.geeksforgeeks.org/problems/grid-path-2/1

Time Complexity: O(PathLength + Recursive Stack Space)
Space Complexity: O(N)
*/

class Solution {
  public:
    int mod = 1e9 + 7;
    int solve(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp) {
        if(i == 0 && j == 0) return 1;
        if(i < 0 || j < 0) return 0;
        if(i >= 0 && j >= 0 && grid[i][j] == 1) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        return dp[i][j] = (solve(i - 1, j, grid, dp) + solve(i, j - 1, grid, dp)) % mod;
    }
    
    int totalWays(int n, int m, vector<vector<int>>& grid) {
        if(grid[0][0] == 1) return 0;

        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(n - 1, m - 1, grid, dp);
    }
};