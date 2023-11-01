/*
Problem Link: https://www.codingninjas.com/studio/problems/chocolate-pickup_3125885?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(3^N * 3^N)
Space Complexity: O(N)
*/

#include <bits/stdc++.h> 

int solve(int i, int j1, int j2, int r, int c, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp) {
    if(j1 < 0 || j2 < 0 || j1 >= c || j2 >= c) return -1e9;
    if(i == r - 1) {
        if(j1 == j2) return grid[i][j1];
        else return grid[i][j1] + grid[i][j2];
    }
    if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

    int maximum = -1e9;
    for(int dj1 = -1; dj1 <= 1; dj1++) {
        for(int dj2 = -1; dj2 <= 1; dj2++) {
            int val = 0;
            if(j1 == j2) val = grid[i][j1];
            else val = grid[i][j1] + grid[i][j2];
            val += solve(i + 1, j1 + dj1, j2 + dj2, r, c, grid, dp);
            maximum = max(maximum, val);
        }
    }
    return dp[i][j1][j2] = maximum;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
    return solve(0, 0, c - 1, r, c, grid, dp);
}