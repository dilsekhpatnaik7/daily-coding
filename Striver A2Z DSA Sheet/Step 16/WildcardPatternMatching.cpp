/*
Problem Link: https://www.codingninjas.com/studio/problems/wildcard-pattern-matching_701650?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(N*M)
Space Complexity: O(N*M)
*/

#include<bits/stdc++.h>
int solve(int i, int j, string& pattern, string& text, vector<vector<int>>& dp) {
   if(i < 0 && j < 0) return true;
   if(i < 0 && j >= 0) return false;
   if(j < 0 && i >= 0) {
      for(int ii = 0; ii <= i; ii++) {
         if(pattern[ii] != '*') return false;
      }
      return true;
   }
   if(dp[i][j] != -1) return dp[i][j];

   if(pattern[i] == text[j] || pattern[i] == '?') return dp[i][j] = solve(i - 1, j - 1, pattern, text, dp);

   if(pattern[i] == '*') {
      return dp[i][j] = solve(i - 1, j, pattern, text, dp) | solve(i, j - 1, pattern, text, dp);
   } 

   return dp[i][j] = false;

}

bool wildcardMatching(string pattern, string text) {
   int n = pattern.size(), m = text.size();
   vector<vector<int>> dp(n, vector<int>(m, -1));
   return solve(n - 1, m - 1, pattern, text, dp);
}
