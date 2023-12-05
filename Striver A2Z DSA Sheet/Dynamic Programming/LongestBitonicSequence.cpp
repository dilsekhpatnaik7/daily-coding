/*
Problem Link: https://www.codingninjas.com/studio/problems/longest-bitonic-sequence_1062688?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(N)
Space Complexity: O(N)
*/

#include<bits/stdc++.h>
int longestBitonicSubsequence(vector<int>& arr, int n) {
	vector<int> dp1(n, 1);
	for(int i = 0; i < n; i++) {
		for (int prev = 0; prev < i; prev++) {
			if(arr[i] > arr[prev] && dp1[prev] + 1 > dp1[i]) {
				dp1[i] = dp1[prev] + 1;
			}
		}
	}
    
	vector<int> dp2(n, 1);
	for(int i = n - 1; i >= 0; i--) {
		for (int prev = n - 1; prev > i; prev--) {
			if(arr[i] > arr[prev] && dp2[prev] + 1 > dp2[i]) {
				dp2[i] = dp2[prev] + 1;
			}
		}
	}

	int maxi = 0;
	for(int i = 0; i < n; i++) {
		maxi = max(maxi, dp1[i] + dp2[i] - 1);
	}
	return maxi;
}
