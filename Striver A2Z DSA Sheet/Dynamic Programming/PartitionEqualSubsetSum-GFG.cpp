/*
Problem Link: https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1

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

    int equalPartition(int N, int arr[]) {
        int sum = 0;
        for(int i = 0; i < N; i++) sum += arr[i];
    	if(sum % 2 != 0) return false;
    
    	int target = sum / 2;
    	vector<vector<int>> dp(N, vector<int>(target + 1, -1));
    	return solve(N - 1, target, arr, dp);
    }
};