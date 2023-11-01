/*
Problem Link: https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1 

Time Complexity: O(N*Target + N)
Space Complexity: O(N)
*/

class Solution{   
public:
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

    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return solve(n - 1, sum, arr, dp);
    }
};