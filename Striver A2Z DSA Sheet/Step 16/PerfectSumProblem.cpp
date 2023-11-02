/*
Problem Link: https://practice.geeksforgeeks.org/problems/perfect-sum-problem5633/1

Time Complexity: O(N*Target + N)
Space Complexity: O(N)
*/

class Solution{
public:
    int mod = 1e9 + 7;
    int solve(int index, int target, int arr[], vector<vector<int>>& dp) {
    	if(target == 0) return 1;
    	if(index == 0) return arr[0] == target;
    	if(dp[index][target] != -1) return dp[index][target];
    
    	int nonTake = solve(index - 1, target, arr, dp) % mod;
    	int take = 0;
    	if(arr[index] <= target) take = solve(index - 1, target - arr[index], arr, dp) % mod;
    
    	return dp[index][target] = (take % mod + nonTake % mod) % mod;
    }

	int perfectSum(int arr[], int n, int sum) {
	    vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
	    sort(arr, arr + n);
	    reverse(arr, arr + n);
	    
	    return solve(n - 1, sum, arr, dp);
	}
	  
};