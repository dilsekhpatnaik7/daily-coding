/*
Problem Link: https://www.codingninjas.com/studio/problems/maximum-sum-of-non-adjacent-elements_843261?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

Time Complexity: O(N)
Space Complexity: O(N)
*/

#include <bits/stdc++.h> 
int solve(int index, vector<int>& nums, vector<int>& dp) {
    if(index == 0) return nums[index];
    if(index < 0) return 0;
    if(dp[index] != -1) return dp[index];

    int pick = nums[index] + solve(index - 2, nums, dp);
    int notPick = 0 + solve(index - 1, nums, dp);

    return dp[index] = max(pick, notPick);
}

int maximumNonAdjacentSum(vector<int> &nums) {
    int n = nums.size();
    vector<int> dp(n, -1);
    return solve(n - 1, nums, dp);
}