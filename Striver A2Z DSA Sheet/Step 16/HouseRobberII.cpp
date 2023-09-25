/*
Problem Link: https://leetcode.com/problems/house-robber-ii/description/

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
public:
    int solve(int index, vector<int>& v, vector<int>& dp) {
        if(index == 0) return v[index];
        if(index < 0) return 0;
        if(dp[index] != -1) return dp[index];

        int left = v[index] + solve(index - 2, v, dp);
        int right = 0 + solve(index - 1, v, dp);

        return dp[index] = max(left, right);
    }

    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];

        vector<int> temp1, temp2;
        for(int i = 0; i < nums.size(); i++) {
            if(i != 0) temp1.push_back(nums[i]);
            if(i != nums.size() - 1) temp2.push_back(nums[i]);
        }

        int n = temp1.size(), m = temp2.size();
        vector<int> dp1(n, -1), dp2(m, -1);
        int left = solve(n - 1, temp1, dp1);
        int right = solve(m - 1, temp2, dp2);

        return max(left, right);
    }
};