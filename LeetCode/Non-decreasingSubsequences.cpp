// Problem Link: https://leetcode.com/problems/non-decreasing-subsequences/
// Leetcode I'd: https://leetcode.com/dilsekhpatnaik7/

class Solution {
public:
    void solve(vector<int> nums, int index, vector<int> output, set<vector<int>>& ans){
        if(index >= nums.size()){
            if(output.size() > 1)
                ans.insert(output);
            return;
        }
        if(output.size() == 0 || nums[index] >= output.back()){
            output.push_back(nums[index]);
            solve(nums, index + 1, output, ans);
            output.pop_back();
        }
        solve(nums, index+1, output, ans);
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> output;
        set<vector<int>> ans;
        solve(nums, 0, output, ans);
        return vector(ans.begin(), ans.end());
    }
};