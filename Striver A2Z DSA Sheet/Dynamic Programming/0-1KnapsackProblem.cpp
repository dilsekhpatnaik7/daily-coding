/*
Problem Link: https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

Time Complexity: O(N*Target)
Space Complexity: O(N*Target + N)
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int solve(int index, int W, int wt[], int val[], vector<vector<int>>& dp) {
        if(index == 0) {
            if(wt[0] <= W) return val[0];
            else return 0;
        }
        if(dp[index][W] != -1) return dp[index][W];
        
        int nonTake = solve(index - 1, W, wt, val, dp);
        int take = 0;
        if(wt[index] <= W) {
            take = val[index] + solve(index - 1, W - wt[index], wt, val, dp);
        }
        
        return dp[index][W] = max(take, nonTake);
    }
    
    int knapSack(int W, int wt[], int val[], int n) { 
        vector<vector<int>> dp(n, vector<int>(W + 1, -1));
        return solve(n - 1, W, wt, val, dp);
    }
};