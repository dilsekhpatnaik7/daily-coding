/*
Problem Link: https://leetcode.com/problems/climbing-stairs/

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
public:
    int solve1(int n, vector<int>& dp) {
        if(n <= 1) return 1;
        if(dp[n] != -1) return dp[n];

        return dp[n] = solve1(n - 1, dp) + solve1(n - 2, dp);
    }

    int solve2(int n, vector<int>& dp) {
        dp[0] = dp[1] = 1;
        for(int i = 2; i < n + 1; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }

    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);

        // Recursion + Memoization
        return solve1(n, dp);

        // Tabulation
        return solve2(n, dp);
    }
};