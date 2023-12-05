/*
Problem Link: https://www.codingninjas.com/studio/problems/count-subsets-with-sum-k_3952532?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(N*Target + N)
Space Complexity: O(N)
*/

#include<bits/stdc++.h>

int mod = 1e9 + 7;
int solve(int index, int target, vector<int>& arr, vector<vector<int>>& dp) {
	if(target == 0) return 1;
	if(index == 0) return arr[0] == target;
	if(dp[index][target] != -1) return dp[index][target];

	int nonTake = solve(index - 1, target, arr, dp);
	int take = 0;
	if(arr[index] <= target) take = solve(index - 1, target - arr[index], arr, dp);

	return dp[index][target] = (take + nonTake) % mod;
}

int findWays(vector<int>& arr, int k) {
	int n = arr.size();
	vector<vector<int>> dp(n, vector<int>(k + 1, -1));
	return solve(n - 1, k, arr, dp);
}