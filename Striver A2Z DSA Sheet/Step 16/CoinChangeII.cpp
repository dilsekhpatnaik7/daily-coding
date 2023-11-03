/*
Problem Link: https://leetcode.com/problems/coin-change-ii/description/

Time Complexity: O(N*Target + N)
Space Complexity: O(N*Target)
*/

class Solution {
public:
    int solve(int index, int value, vector<int>& coins, vector<vector<int>>& dp) {
        if(index == 0) return value % coins[0] == 0;
        if(dp[index][value] != -1) return dp[index][value];

        int nonTake = solve(index - 1, value, coins, dp);
        int take = 0;
        if(coins[index] <= value) {
            take = solve(index, value - coins[index], coins, dp);
        }

        return dp[index][value] = take + nonTake;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return solve(n - 1, amount, coins, dp);
    }
};