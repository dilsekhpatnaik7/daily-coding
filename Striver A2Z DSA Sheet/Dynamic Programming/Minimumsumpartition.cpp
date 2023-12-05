/*
Problem Link: https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1

Time Complexity: O(N*Target + N)
Space Complexity: O(N)
*/

class Solution{
  public:
    bool solve(int index, int target, int arr[], vector<vector<int>> &dp) {
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
  
	int minDifference(int arr[], int n)  { 
	    if(n == 1) return arr[0];
	    
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
};