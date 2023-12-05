/*
Problem Link: https://www.codingninjas.com/studio/problems/printing-longest-increasing-subsequence_8360670?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(N)
Space Complexity: O(N)
*/

vector<int> printingLongestIncreasingSubsequence(vector<int> arr, int n) {
	vector<int> dp(n, 1), hash(n);
	int maxi = 1;
	int lastIndex = 0;
	for(int i = 0; i < n; i++) {
		hash[i] = i;
		for (int prev = 0; prev < i; prev++) {
			if(arr[prev] < arr[i] && dp[prev] + 1 > dp[i]) {
				dp[i] = dp[prev] + 1;
				hash[i] = prev;
			}
		}
		if(dp[i] > maxi) {
			maxi = dp[i];
			lastIndex = i;
		}
	}

	vector<int> ans;
	ans.push_back(arr[lastIndex]);
	while(hash[lastIndex] != lastIndex) {
		lastIndex = hash[lastIndex];
		ans.push_back(arr[lastIndex]);
	}
	reverse(ans.begin(), ans.end());
	return ans;
}
