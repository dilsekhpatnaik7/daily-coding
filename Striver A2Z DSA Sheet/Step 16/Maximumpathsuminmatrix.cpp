/*
Problem Link: Maximum path sum in matrix

Time Complexity: O(PathLength + Recursive Stack Space)
Space Complexity: O(N)
*/

class Solution{
public:
    int solve(vector<vector<int>>& Matrix, int i, int j, vector<vector<int>>& dp) {
        int n = Matrix.size(), m = Matrix[0].size();
        if(i < 0 || i >= n || j < 0 || j >= m) return -1e9;
        if(dp[i][j] != -1) return dp[i][j];
        if(i == 0) return Matrix[0][j];
        
        int diagonal = Matrix[i][j] + solve(Matrix, i - 1, j - 1, dp);
        int left = Matrix[i][j] + solve(Matrix, i - 1, j, dp);
        int up = Matrix[i][j] + solve(Matrix, i - 1, j + 1, dp);
        
        return dp[i][j] = max({diagonal, left, up});
    }
    
    int maximumPath(int N, vector<vector<int>> Matrix) {
        int maximum = 0;
        vector<vector<int>> dp(N, vector<int>(N, -1));
        for(int i = 0; i < N; i++) {
            int ans = solve(Matrix, N - 1, i, dp);
            maximum = max(maximum, ans); 
        }
        return maximum;
    }
};