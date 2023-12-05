/*
Problem Link: https://leetcode.com/problems/wildcard-matching/description/

Time Complexity: O(N*M)
Space Complexity: O(N*M)
*/

class Solution {
public:
    bool solve(int n, int m, string& pattern, string& text) {
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;

        for(int j = 1; j <= m; j++) dp[0][j] = false;

        for(int i = 1; i <= n; i++) {
            bool flag = true;
            for(int ii = 1; ii <= i; ii++) {
                if(pattern[ii - 1] != '*') {
                    flag = false;
                    break;
                }
            }
            dp[i][0] = flag;
        }

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(pattern[i - 1] == text[j - 1] || pattern[i -1] == '?') dp[i][j] = dp[i - 1][j - 1];
                else if(pattern[i - 1] == '*') dp[i][j] = dp[i - 1][j] | dp[i][j - 1];
                else dp[i][j] = false;
            }
        }

        return dp[n][m];
    }

    bool isMatch(string s, string p) {
        int n = p.size(), m = s.size();
        return solve(n, m, p, s);
    }
};