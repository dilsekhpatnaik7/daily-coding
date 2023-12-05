/*
Problem Link: https://www.codingninjas.com/studio/problems/partition-equal-subset-sum-_892980?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(N*Target + N)
Space Complexity: O(N)
*/

#include<bits/stdc++.h>

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

bool canPartition(vector<int> &arr, int n) {
	int sum = 0;
    for(int i = 0; i < n; i++) sum += arr[i];
	if(sum % 2 != 0) return false;

	int target = sum / 2;
	vector<vector<int>> dp(n, vector<int>(target + 1, -1));
	return solve(n - 1, target, arr, dp);
}
