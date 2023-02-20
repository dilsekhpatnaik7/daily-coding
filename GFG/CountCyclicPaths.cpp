// Problem Link: https://practice.geeksforgeeks.org/problems/aa0000a5f710ce8d41366b714341eef644ec7b82/1
// GFG I'd: https://auth.geeksforgeeks.org/user/dilsekhpatnaik7

class Solution {   
public:
    const int mod = 1e9+7;
    int countPaths(int N) {
        vector<vector<int>> dp(4, vector<int>(N + 1, 0));
        dp[0][0] = 1;
        for(int i = 1; i <= N; i++) {
            for(int j = 0; j <= 3; j++) {
                dp[j][i] = (dp[j][i] + dp[(j + 1) % 4][i - 1]) % mod;
                dp[j][i] = (dp[j][i] + dp[(j + 2) % 4][i - 1]) % mod;
                dp[j][i] = (dp[j][i] + dp[(j + 3) % 4][i - 1]) % mod;
            }
        }
        return dp[0][N];
    }
};