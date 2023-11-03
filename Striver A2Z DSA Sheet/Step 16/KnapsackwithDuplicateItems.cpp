/*
Problem Link: https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1

Time Complexity: O(N*Target + N)
Space Complexity: O(N*Target)
*/

class Solution{
public:
    int solve(int index, int w, int profit[], int weight[], vector<vector<int>>& dp) {
        if(index == 0) {
            return (w / weight[0]) * profit[0];
        }
        if(dp[index][w] != -1) return dp[index][w];
    
        int notTake = solve(index - 1, w, profit, weight, dp);
        int take = -1e9;
        if(weight[index] <= w) {
            take = profit[index] + solve(index, w - weight[index], profit, weight, dp);
        }
    
        return dp[index][w] = max(take, notTake);
    }

    int knapSack(int N, int W, int val[], int wt[]) {
        vector<vector<int>> dp(N, vector<int>(W + 1, -1));
        return solve(N - 1, W, val, wt, dp);
    }
};