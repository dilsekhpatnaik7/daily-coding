/*
Problem Link: https://www.codingninjas.com/studio/problems/unique-paths-ii_977241?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

Time Complexity: O(PathLength + Recursive Stack Space)
Space Complexity: O(N)
*/

int solve(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &dp) {
    if(i == 0 && j == 0 && mat[i][j] != -1) return 1;
    if(i < 0 || j < 0) return 0;
    if(i >= 0 && j >= 0 && mat[i][j] == -1) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    return dp[i][j] = solve(i - 1, j, mat, dp) + solve(i, j - 1, mat, dp);
}

int mazeObstacles(int n, int m, vector<vector<int>> &mat) {
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return solve(n - 1, m - 1, mat, dp);
}