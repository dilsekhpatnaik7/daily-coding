/*
Problem Link: https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size(), maxi = 0;
        vector<int> dp(n, 1), count(n, 1);
        for(int i = 0; i < n; i++) {
            for (int prev = 0; prev < i; prev++) {
                if(nums[prev] < nums[i] && dp[prev] + 1 > dp[i]) {
                    dp[i] = dp[prev] + 1;
                    count[i] = count[prev];
                } else if(nums[prev] < nums[i] && dp[prev] + 1 == dp[i]){
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
};