/*
Problem Link: https://www.codingninjas.com/studio/problems/frog-jump_3621012?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

Time Complexity: O(N)
Space Complexity: O(N)
*/

#include <bits/stdc++.h> 
int solve1(int index, vector<int> &heights, vector<int> &dp) {
    if(index == 0) return 0;
    if(dp[index] != -1) return dp[index];

    int left = solve1(index - 1, heights, dp) + abs(heights[index] - heights[index - 1]);
    int right = INT_MAX;
    if(index > 1) right = solve1(index - 2, heights, dp) + abs(heights[index] - heights[index - 2]);

    return dp[index] = min(left, right);
}

int solve2(int index, vector<int> &heights, vector<int> &dp) {
    dp[0] = 0;
    for(int i = 1; i < index; i++) {
        int first = dp[i -1] + abs(heights[i] - heights[i - 1]);
        int second = INT_MAX;
        if(i > 1) second = dp[i -2] + abs(heights[i] - heights[i - 2]);

        dp[i] = min(first, second);
    }
    return dp[index - 1];
}

int frogJump(int n, vector<int> &heights) {
    // Recursion + Memoization
    vector<int> dp(n + 1, -1);
    return solve1(n - 1, heights, dp);

    // Tabulation
    vector<int> dp(n, 0)
    return solve2(n, heights, dp);
}