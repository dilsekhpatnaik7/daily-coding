/*
Problem Link: https://practice.geeksforgeeks.org/problems/max-sum-without-adjacents2430/1

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution{
public:	
    int solve(int index, int* arr, vector<int>& dp) {
        if(index == 0) return arr[index];
        if(index < 0) return 0;
        if(dp[index] != -1) return dp[index];
    
        int pick = arr[index] + solve(index - 2, arr, dp);
        int notPick = 0 + solve(index - 1, arr, dp);
    
        return dp[index] = max(pick, notPick);
    }

	int findMaxSum(int *arr, int n) {
	    vector<int> dp(n, -1);
	    return solve(n - 1, arr, dp);
	}
};