// Peoblem Link: https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for(int i = 0 ; i < nums.size(); i++) {
            if(map.find(target - nums[i]) != map.end()) 
                return {map[target - nums[i]],i};
            else map[nums[i]] = i;
        }
        return {-1, -1};
    }
};