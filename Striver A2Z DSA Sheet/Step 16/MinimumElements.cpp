/*
Problem Link: https://www.codingninjas.com/studio/problems/minimum-elements_3843091?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(N*Target)
Space Complexity: O(N*Target)
*/

#include <bits/stdc++.h>
// int solve(int index, int target, vector<int> &num, vector<vector<int>> &dp) {
//     if(index == 0) {
//         if(target % num[0] == 0) return target / num[0];
//         return 1e9;
//     }
//     if(dp[index][target] != -1) return dp[index][target];

//     int nonTake = solve(index - 1, target, num, dp);
//     int take = 1e9;
//     if(num[index] <= target) {
//         take = 1 + solve(index, target - num[index], num, dp);
//     }

//     return min(take, nonTake);
// }

int solve(int n, int target, vector<int> &num, vector<vector<int>> &dp) {
    for(int i = 0; i <= target; i++) {
        if(i % num[0] == 0) dp[0][i] = i / num[0];
        else dp[0][i] = 1e9;
    }

    for(int i = 1; i < n; i++) {
        for(int j = 0; j <= target; j++) {
            int nonTake = dp[i - 1][j];
            int take = 1e9;
            if(num[i] <= j) take = 1 + dp[i][j - num[i]];

            dp[i][j] = min(take, nonTake);
        }
    }
    return dp[n - 1][target];
}

int minimumElements(vector<int> &num, int x) {
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(x + 1, -1));
    
    int result = solve(n, x, num, dp);
    if(result >= 1e9) return -1;
    return result;
}