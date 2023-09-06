/*
Problem Link: https://leetcode.com/problems/subsets-ii/

Time Complexity: O(2 ^ N + N * log(N))
Space Complexity: O(2 ^ N + N + N ^ 2)
*/

class Solution {
public:
    void getSubsets(int index, vector<int>& arr, vector<int>& ds, vector<vector<int>>& ans) {
        ans.push_back(ds);

        for(int i = index; i < arr.size(); i++) {
            if(i > index && arr[i] == arr[i - 1]) continue;
            ds.push_back(arr[i]);
            getSubsets(i + 1, arr, ds, ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ds;
        vector<vector<int>> ans;

        getSubsets(0, nums, ds, ans);
        return ans;
    }
};