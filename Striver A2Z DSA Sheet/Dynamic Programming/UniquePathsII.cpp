/*
Problem Link: https://leetcode.com/problems/unique-paths-ii/description/

Time Complexity: O(PathLength + Recursive Stack Space)
Space Complexity: O(N)
*/

class Solution {
public:
    int solve(int i, int j, vector<vector<int>> &obstacleGrid, vector<vector<int>> &dp) {
        if(i == 0 && j == 0) return 1;
        if(i < 0 || j < 0) return 0;
        if(i >= 0 && j >= 0 && obstacleGrid[i][j] == 1) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        return dp[i][j] = solve(i - 1, j, obstacleGrid, dp) + solve(i, j - 1, obstacleGrid, dp);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0] == 1) return 0;

        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(n - 1, m - 1, obstacleGrid, dp);
    }
};