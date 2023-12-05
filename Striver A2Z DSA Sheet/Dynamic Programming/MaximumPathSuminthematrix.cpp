/*
Problem Link: https://www.codingninjas.com/studio/problems/maximum-path-sum-in-the-matrix_797998?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

Time Complexity: O(PathLength + Recursive Stack Space)
Space Complexity: O(N)
*/

#include <bits/stdc++.h> 

int getMaxPathSum(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    int dp[n+1][m+1];
    for(int i = 0 ; i <= n ;++i){
        for(int j = 0 ; j <= m ; ++j){
            dp[i][j]=INT_MIN;
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
                dp[i][j] = matrix[i][j]+ max(dp[i-1][j],dp[i-1][j+1]);
            }
            else {
                    dp[i][j] = matrix[i][j]+ max(dp[i-1][j],max(dp[i-1][j-1],dp[i-1][j+1]));
            }
            
        }
    }
    
    int ans = INT_MIN;

    for(int j = 0 ; j < m ; ++j){
        ans = max(dp[n-1][j],ans);
    }

    return ans;
}