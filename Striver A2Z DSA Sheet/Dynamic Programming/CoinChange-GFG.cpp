/*
Problem Link: https://practice.geeksforgeeks.org/problems/coin-change2448/1

Time Complexity: O(N*Target + N)
Space Complexity: O(N*Target)
*/

class Solution {
  public:
    // int solve(int index, int value, int coins[], vector<vector<long long int>>& dp) {
    //     if(index == 0) return value % coins[0] == 0;
    //     if(dp[index][value] != -1) return dp[index][value];

    //     int nonTake = solve(index - 1, value, coins, dp);
    //     int take = 0;
    //     if(coins[index] <= value) {
    //         take = solve(index, value - coins[index], coins, dp);
    //     }

    //     return dp[index][value] = take + nonTake;
    // }
    
    long long int solve(int N, int value, int coins[], vector<vector<long long int>>& dp) {
        for(int i = 0; i <= value; i++) {
            dp[0][i] = (i % coins[0] == 0);
        }
        
        for(int i = 1; i < N; i++) {
            for(int j = 0; j <= value; j++) {
                long long int nonTake = dp[i - 1][j];
                long long int take = 0;
                if(coins[i] <= j) take = dp[i][j - coins[i]];
                
                dp[i][j] = take + nonTake;
            }
        }
        return dp[N - 1][value];
    }
  
    long long int count(int coins[], int N, int sum) {
        vector<vector<long long int>> dp(N, vector<long long int>(sum + 1, 0));
        return solve(N, sum, coins, dp);
    }
};