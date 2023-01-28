// Problem Link: https://practice.geeksforgeeks.org/problems/scrambled-string/1
// GFG I'd: https://auth.geeksforgeeks.org/user/dilsekhpatnaik7

class Solution{
public:
    bool isScramble(string s1, string s2){
        if (s1.size() != s2.size()) return false;
        int n = s1.size();
        bool dp[n][n][n];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                dp[i][j][0] = (s1[i] == s2[j]);
            }
        }
        for(int k = 2; k <= n; k++) {
            for(int i = 0; i <= n - k; i++) {
                for(int j = 0; j <= n - k; j++) {
                    dp[i][j][k-1] = false;
                    for(int p = 1; p < k; p++) {
                        if((dp[i][j][p-1] && dp[i+p][j+p][k-p-1]) || (dp[i][j+k-p][p-1] && dp[i+p][j][k-p-1])) {
                            dp[i][j][k-1] = true;
                            break;
                        }
                    }
                }
            }
        }
        return dp[0][0][n-1];
    }    
};