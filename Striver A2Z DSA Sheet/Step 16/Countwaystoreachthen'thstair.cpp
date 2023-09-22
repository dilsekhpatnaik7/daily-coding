/*
Problem Link: https://practice.geeksforgeeks.org/problems/count-ways-to-reach-the-nth-stair-1587115620/1

Time Complexity: O(N)
Space Complexity: O(N)
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    const int mod = 1e9 + 7;
    int solve(int n, vector<int>& dp) {
        if(n <= 1) return 1;
        if(dp[n] != -1) return dp[n];
        
        return dp[n] = (solve(n - 1, dp) + solve(n - 2, dp)) % mod;
    }
    
    int countWays(int n) {
        vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }
}