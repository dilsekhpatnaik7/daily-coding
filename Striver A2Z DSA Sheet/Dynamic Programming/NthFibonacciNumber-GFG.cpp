/*
Problem Link: https://practice.geeksforgeeks.org/problems/nth-fibonacci-number1335/1

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
  public:
    const int mod = 1000000007;
    int nthFibonacci(int n){
        int dp[n + 1];
        dp[0] = 0, dp[1] = 1;
        for(int i = 2; i < n + 1; i++) {
                dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
        }
        return dp[n] % mod;
    }
};