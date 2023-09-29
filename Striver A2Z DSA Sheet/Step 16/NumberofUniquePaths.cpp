/*
Problem Link: https://practice.geeksforgeeks.org/problems/number-of-unique-paths5339/1

Time Complexity: O(PathLength + Recursive Stack Space)
Space Complexity: O(N)
*/

class Solution {
    public:
    int solve(int i, int j, vector<vector<int>>& dp) {
    	if(i == 0 && j == 0) return 1;
    	if(i < 0 || j < 0) return 0;
    	if(dp[i][j] != -1) return dp[i][j];
    
    	return dp[i][j] = solve(i - 1, j, dp) + solve(i, j - 1, dp);
    }
    
    int NumberOfPath(int a, int b) {
        vector<vector<int>> dp(a, vector<int>(b, -1));
        return solve(a - 1, b - 1, dp);
    }
};