/*
Problem Link: https://www.codingninjas.com/studio/problems/subset-sum-equal-to-k_1550954?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(N*Target + N)
Space Complexity: O(N)
*/

#include <bits/stdc++.h>

bool solve(int index, int target, vector<int> &arr, vector<vector<int>> &dp) {
    if(target == 0) return true;
    if(index == 0) return arr[0] == target;
    if(dp[index][target] != -1) return dp[index][target];

    bool nonTake = solve(index - 1, target, arr, dp);
    bool take = false;
    if(target >= arr[index]) {
        take = solve(index - 1, target - arr[index], arr, dp);
    }

    return dp[index][target] = take or nonTake;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return solve(n - 1, k, arr, dp);
}