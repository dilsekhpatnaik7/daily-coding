// Problem Link: https://leetcode.com/problems/domino-and-tromino-tiling/
// Leetcode I'd: https://leetcode.com/dilsekhpatnaik7/

class Solution {
public:
    int numTilings(int n) {
        int MOD = 1e9+7;
        vector<int> dp(1e3+1, 0 );

        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;

        for(int i = 4;i<=n;i++){
            int val = (dp[i-1]%MOD + dp[i-1]%MOD)%MOD;
            val = (val%MOD + dp[i-3]%MOD)%MOD;
            dp[i] = val;
        }
        return dp[n];
    }
};