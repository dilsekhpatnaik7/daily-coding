// Problem link: https://leetcode.com/problems/fibonacci-number/

class Solution {
public:
    int fib(int n) {
        if(n < 2) return n;
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;
        int i = 2;
        while(i <= n) {
            dp[i] = dp[i - 1] + dp[i - 2];
            i++;
        }
        return dp[n];
    }
};