/*
Problem Link: https://leetcode.com/problems/delete-operation-for-two-strings/description/

Time Complexity: O(N*M)
Space Complexity: O(N*M)
*/

class Solution {
public:
    int solve(string& s, string& t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= m; j++) {
                if(i == 0 || j == 0) dp[i][j] = 0;
                else if(s[i - 1] == t[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n][m];
    }

    int minDistance(string word1, string word2) {
        return word1.size() + word2.size() - 2 * solve(word1, word2);
    }
};