/*
Problem Link: https://www.codingninjas.com/studio/problems/combination-sum-iii_5038357?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

Time Complexity: O(2 ^ N + N)
Space Complexity: O(2 ^ N + N + N + N ^ 2)
*/

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

vector<vector<int>> combinationSum(int k, int n) {
    vector<int> nums;
    vector<int> ds;
    vector<vector<int>> ans;
    for(int i = 1; i <= 9; i++) {
        nums.push_back(i);
    }
    solve(0, n, k, nums, ds, ans);
    return ans;
}