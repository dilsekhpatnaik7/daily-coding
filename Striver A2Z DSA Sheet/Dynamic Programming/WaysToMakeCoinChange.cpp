/*
Problem Link: https://www.codingninjas.com/studio/problems/ways-to-make-coin-change_630471?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(N*Target + N)
Space Complexity: O(N*Target)
*/

#include<bits/stdc++.h>

long solve(int index, int value, int *denominations, vector<vector<long>>& dp) {
    if(index == 0) return value % denominations[0] == 0;
    if(dp[index][value] != -1) return dp[index][value];

    long nonTake = solve(index - 1, value, denominations, dp);
    long take = 0;
    if(denominations[index] <= value) {
        take = solve(index, value - denominations[index], denominations, dp);
    }

    return dp[index][value] = take + nonTake;
}

long countWaysToMakeChange(int *denominations, int n, int value) {
    vector<vector<long>> dp(n, vector<long>(value + 1, -1));
    return solve(n - 1, value, denominations, dp);
}