/*
Problem Link: https://www.codingninjas.com/studio/problems/partitions-with-given-difference_3751628?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(N*Target + N)
Space Complexity: O(N)
*/

#include <bits/stdc++.h> 

int mod = 1e9 + 7;
int solve(int index, int target, vector<int>& arr, vector<vector<int>>& dp) {
	if(index == 0) {
        if(target == 0 && arr[0] == 0) return 2;
        if(target == 0 || target == arr[0]) return 1;
        return 0;
    }
	if(dp[index][target] != -1) return dp[index][target];

	int nonTake = solve(index - 1, target, arr, dp);
	int take = 0;
	if(arr[index] <= target) take = solve(index - 1, target - arr[index], arr, dp);

	return dp[index][target] = (take + nonTake) % mod;
}

int countPartitions(int n, int d, vector<int> &arr) {
    int totalSum = 0;
    for(int i = 0; i < n; i++) totalSum += arr[i];
    if(totalSum - d < 0 || (totalSum - d) % 2) return 0;

    int target = (totalSum - d) / 2;
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    return solve(n - 1, target, arr, dp);
}


