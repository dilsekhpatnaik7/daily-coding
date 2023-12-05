/*
Problem Link: https://leetcode.com/problems/subsets/

Time Complexity: O(2 ^ N)
Space Complexity: O(2 ^ N + N)
*/

class Solution {
public:
    void generateSubsets(int index, int n, vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans) {
        if(index == n) {
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[index]);
        generateSubsets(index + 1, n, nums, temp, ans);
        
        temp.pop_back();
        generateSubsets(index + 1, n, nums, temp, ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;
        generateSubsets(0, nums.size(), nums, temp, ans);
        return ans;
    }
};