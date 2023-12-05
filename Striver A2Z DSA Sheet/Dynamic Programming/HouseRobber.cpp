/*
Problem Link: https://leetcode.com/problems/house-robber/description/

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
public:
    // Recursion + Memoization
    int solve(int index, vector<int>& nums, vector<int>& dp) {
        if(index == 0) return nums[index];
        if(index < 0) return 0;
        if(dp[index] != -1) return dp[index];

        int pick = nums[index] + solve(index - 2, nums, dp);
        int notPick = 0 + solve(index - 1, nums, dp);

        return dp[index] = max(pick, notPick);
    }

    // Tabulation
    int solve2(int index, vector<int>& nums, vector<int>& dp) {
        dp[0] = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            int take = nums[i]; if(i > 1) take += dp[i - 2];
            int notTake = 0 + dp[i - 1];

            dp[i] = max(take, notTake);
        }
        return dp[index];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);

        //Recursion + Memoization
        return solve(n - 1, nums, dp);

        // Tabulation
        return solve2(n - 1, nums, dp);
    }
};