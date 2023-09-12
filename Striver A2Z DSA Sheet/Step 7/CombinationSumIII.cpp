/*
Problem Link: https://leetcode.com/problems/combination-sum-iii/

Time Complexity: O(2 ^ N + N)
Space Complexity: O(2 ^ N + N + N + N ^ 2)
*/

class Solution {
public:
    void solve(int index, int target, int k, vector<int> &nums, vector<int> &ds, vector<vector<int>>& ans) {
        if(index == nums.size()) {
            if(ds.size() == k and target == 0) {
                ans.push_back(ds);
            }
            return;
        }

        if(nums[index] <= target) {
            ds.push_back(nums[index]);
            solve(index + 1, target - nums[index], k, nums, ds, ans);
            ds.pop_back();
        }
        solve(index + 1, target, k, nums, ds, ans);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums;
        vector<int> ds;
        vector<vector<int>> ans;
        for(int i = 1; i <= 9; i++) {
           nums.push_back(i);
        }
        solve(0, n, k, nums, ds, ans);
        return ans;
    }
};