/*
Problem Link: https://leetcode.com/problems/partition-equal-subset-sum/description/

Time Complexity: O(N*Target + N)
Space Complexity: O(N)
*/

class Solution {
public:
    bool solve(int index, int target, vector<int> &nums, vector<vector<int>> &dp) {
        if(target == 0) return true;
        if(index == 0) return nums[0] == target;
        if(dp[index][target] != -1) return dp[index][target];

        bool nonTake = solve(index - 1, target, nums, dp);
        bool take = false;
        if(target >= nums[index]) {
            take = solve(index - 1, target - nums[index], nums, dp);
        }

        return dp[index][target] = take or nonTake;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; i++) sum += nums[i];
        if(sum % 2 != 0) return false;

        int target = sum / 2;
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return solve(n - 1, target, nums, dp);
    }
};