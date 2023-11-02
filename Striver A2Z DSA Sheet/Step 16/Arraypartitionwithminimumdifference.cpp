/*
Problem Link: https://www.codingninjas.com/studio/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum._842494?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(N*Target + N)
Space Complexity: O(N)
*/

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

int minSubsetSumDifference(vector<int>& arr, int n) {
	int totalSum = 0;
	for(int i = 0; i < n; i++) totalSum += arr[i];
	vector<vector<int>> dp(n, vector<int>(totalSum + 1, -1));
	
	for(int i = 0; i <= totalSum; i++) {
		bool result = solve(n - 1, totalSum - i, arr, dp);
	}

	int minimum = 1e9;
	for(int i = 0; i <= totalSum; i++) {
		if(dp[n - 1][i] == 1) minimum = min(minimum, abs((totalSum - i) - i));
	}
	return minimum;
}