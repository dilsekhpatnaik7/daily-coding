/*
Problem Link: https://leetcode.com/problems/minimum-falling-path-sum/description/

Time Complexity: O(PathLength + Recursive Stack Space)
Space Complexity: O(N)
*/

class Solution {
public: 
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int dp[n+1][m+1];
        for(int i = 0 ; i <= n ;++i){
            for(int j = 0 ; j <= m ; ++j){
               dp[i][j]=INT_MAX;
            }
        }

        for(int i = 0 ; i < n ; ++i){
            for(int j = 0; j <m  ; ++j){
                if(i==0 && j==0){
                    dp[i][j] = matrix[i][j];
                }
                else if(i==0){
                    dp[i][j] = matrix[i][j];
                }
                else if (j==0){
                    dp[i][j] = matrix[i][j]+ min(dp[i-1][j],dp[i-1][j+1]);
                }
                else {
                     dp[i][j] = matrix[i][j]+ min(dp[i-1][j],min(dp[i-1][j-1],dp[i-1][j+1]));
                }
             
            }
        }

        int ans = INT_MAX;
        for(int j = 0 ; j < m ; ++j){
            ans = min(dp[n-1][j],ans);
        }
        return ans ;
    }
};