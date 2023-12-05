/*
Problem Link: https://www.codingninjas.com/studio/problems/rod-cutting-problem_800284?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(N*N + N)
Space Complexity: O(N*N)
*/

int solve(int index, int target, vector<int> &price, vector<vector<int>> &dp) {
	if(index == 0) return target * price[0];
	if(dp[index][target] != -1) return dp[index][target];

	int notTake = solve(index - 1, target, price, dp);
	int take = -1e9;
	int rodLength = index + 1;
	if(rodLength <= target) take = price[index] + solve(index, target - rodLength, price, dp);

	return dp[index][target] = max(take, notTake);
}

int cutRod(vector<int> &price, int n) {
	vector<vector<int>> dp(n, vector<int>(n + 1, -1));
	return solve(n - 1, n, price, dp);
}
