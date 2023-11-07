/*
Problem Link: https://www.codingninjas.com/studio/problems/number-of-longest-increasing-subsequence_3751627?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(N)
Space Complexity: O(N)
*/

#include<bits/stdc++.h>
int findNumberOfLIS(vector<int> &arr) {
    int n = arr.size(), maxi = 0;
    vector<int> dp(n, 1), count(n, 1);
	for(int i = 0; i < n; i++) {
		for (int prev = 0; prev < i; prev++) {
			if(arr[prev] < arr[i] && dp[prev] + 1 > dp[i]) {
				dp[i] = dp[prev] + 1;
				count[i] = count[prev];
			} else if(arr[prev] < arr[i] && dp[prev] + 1 == dp[i]){
                count[i] += count[prev];
            }
		}
        maxi = max(maxi, dp[i]);
	}
    
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(dp[i] == maxi) ans += count[i];
    }
    return ans;
}