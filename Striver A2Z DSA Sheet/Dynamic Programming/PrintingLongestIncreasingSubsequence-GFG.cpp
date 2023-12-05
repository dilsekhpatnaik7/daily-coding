/*
Problem Link: https://practice.geeksforgeeks.org/problems/printing-longest-increasing-subsequence/1

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
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
};