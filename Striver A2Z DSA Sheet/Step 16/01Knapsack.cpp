/*
Problem Link: https://www.codingninjas.com/studio/problems/0-1-knapsack_920542?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(N*Target)
Space Complexity: O(N*Target + N)
*/

#include <bits/stdc++.h> 
int solve(int index, int maxWeight, vector<int> &weight, vector<int>& value, vector<vector<int>>& dp) {
	if(index == 0) {
		if(weight[0] <= maxWeight) return value[0];
		else return 0;
	}
	if(dp[index][maxWeight] != -1) return dp[index][maxWeight];

	int nonTake = solve(index - 1, maxWeight, weight, value, dp);
	int take = 0;
	if(weight[index] <= maxWeight) {
		take = value[index] + solve(index - 1, maxWeight - weight[index], weight, value, dp);
	}

	return dp[index][maxWeight] = max(take, nonTake);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
	vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
	return solve(n - 1, maxWeight, weight, value, dp);
}