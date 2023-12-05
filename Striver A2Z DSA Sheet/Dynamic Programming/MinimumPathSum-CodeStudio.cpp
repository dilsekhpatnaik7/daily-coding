/*
Problem Link: https://www.codingninjas.com/studio/problems/minimum-path-sum_985349?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

Time Complexity: O(PathLength + Recursive Stack Space)
Space Complexity: O(N)
*/

#include <bits/stdc++.h> 
int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
    if(i == 0 && j == 0) return grid[i][j];
    if(i < 0 || j < 0) return 1e9;
    if(dp[i][j] != -1) return dp[i][j];

    int left = grid[i][j] + solve(i - 1, j, grid, dp);
    int right = grid[i][j] + solve(i, j - 1, grid, dp);
    return dp[i][j] = min(left, right);
}

int minSumPath(vector<vector<int>> &grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return solve(n - 1, m - 1, grid, dp);
}