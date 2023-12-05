/*
Problem Link: https://leetcode.com/problems/triangle/

Time Complexity: O(N)
Space Complexity: O(N^2)
*/

class Solution {
public:
  int solve(int i, int j, int n, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
    if(i == n - 1) return triangle[i][j];
    if(dp[i][j] != -1) return dp[i][j];

    int down = triangle[i][j] + solve(i + 1, j, n, triangle, dp);
    int diagonal = triangle[i][j] + solve(i + 1, j + 1, n, triangle, dp);

    return dp[i][j] = min(down, diagonal);
  }

  int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return solve(0, 0, n, triangle, dp);
  }
};