/*
Problem Link: https://leetcode.com/problems/longest-increasing-subsequence/description/

Time Complexity: O(N*N)
Space Complexity: O(N*N)
*/

class Solution {
public:
    int solve(int index, int previous, int n, vector<int>& arr, vector<vector<int>>& dp) {
        if(index == n) return 0;
        if(dp[index][previous + 1] != -1) return dp[index][previous + 1];

        int length = solve(index + 1, previous, n, arr, dp);
        if(previous == -1 || arr[index] > arr[previous]) {
            length = max(length, 1 + solve(index + 1, index, n, arr, dp));
        }

        return dp[index][previous + 1] = length;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solve(0, -1, n, nums, dp);
    }
};