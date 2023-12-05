/*
Problem Link: https://practice.geeksforgeeks.org/problems/geek-jump/1

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
  public:
    int solve(int index, vector<int> &height, vector<int> &dp) {
        if(index == 0) return 0;
        if(dp[index] != -1) return dp[index];
        
        int first = solve(index - 1, height, dp) + abs(height[index] - height[index - 1]);
        int second = INT_MAX;
        if(index > 1) second = solve(index - 2, height, dp) + abs(height[index] - height[index - 2]);
        
        return dp[index] = min(first, second);
    }
  
    int minimumEnergy(vector<int>& height, int n) {
        vector<int> dp(n + 1, -1);
        return solve(n - 1, height, dp);
    }
};