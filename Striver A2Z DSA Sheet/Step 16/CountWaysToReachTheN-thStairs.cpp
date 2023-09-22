/*
Problem Link: https://www.codingninjas.com/studio/problems/count-ways-to-reach-the-n-th-stairs_798650?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

Time Complexity: O(N)
Space Complexity: O(N)
*/

#include <bits/stdc++.h> 
const int mod = 1e9 + 7;
int solve(int n, vector<int>& dp) {
    if(n <= 1) return 1;
    if(dp[n] != -1) return dp[n] % mod;

    return dp[n] = (solve(n - 1, dp) % mod + solve(n - 2, dp) % mod) % mod;
}

int countDistinctWays(int nStairs) {
    vector<int> dp(nStairs + 1, -1);
    return solve(nStairs, dp);
}