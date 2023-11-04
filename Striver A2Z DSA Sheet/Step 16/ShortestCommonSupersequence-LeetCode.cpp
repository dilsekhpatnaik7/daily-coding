/*
Problem Link: https://leetcode.com/problems/shortest-common-supersequence/description/

Time Complexity: O(N*M)
Space Complexity: O(N*M)
*/

class Solution {
public:
    void lcs(int n, int m, string& s, string& t, vector<vector<int>>& dp) {
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= m; j++) {
                if(i == 0 || j == 0) dp[i][j] = 0;
                else if(s[i - 1] == t[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    string solve(int n, int m, string& s, string& t, vector<vector<int>>& dp) {
        string ans = "";
        int i = n, j = m;
        while(i > 0 && j > 0) {
            if(s[i - 1] == t[j - 1]) {
                ans += s[i - 1];
                i--, j--;
            } else if(dp[i - 1][j] > dp[i][j - 1]) {
                ans += s[i - 1];
                i--;
            } else {
                ans += t[j - 1];
                j--;
            }
        }

        while(i > 0) {
            ans += s[i - 1];
            i--;
        }
        while(j > 0) {
            ans += t[j - 1];
            j--;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }

    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        lcs(n, m, str1, str2, dp);
        return solve(n, m, str1, str2, dp);
    }
};