/*
Problem Link: https://www.codingninjas.com/studio/problems/count-square-submatrices-with-all-ones_3751502?leftPanelTabValue=PROBLEM

Time Complexity: O(N*M)
Space Complexity: O(N*M)
*/

int solve(int n, int m, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
    int ans = 0;
    for(int i = 0; i < n; i++) dp[i][0] = matrix[i][0];
    for(int j = 0; j < m; j++) dp[0][j] = matrix[0][j];

    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            if(matrix[i][j] == 0) dp[i][j] = 0;
            else {
                dp[i][j] = 1 + min({dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]});
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            ans += dp[i][j];
        }
    }
    return ans;
}

int countSquares(int n, int m, vector<vector<int>> &arr) {
    vector<vector<int>> dp(n, vector<int>(m, 0));
    return solve(n, m, arr, dp);
}